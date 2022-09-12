/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom_srt_f_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 13:57:29 by cudoh             #+#    #+#             */
/*   Updated: 2022/07/31 13:57:29 by cudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "custom_srt_f_utils.h"

/**
 * @brief 	This function executes when normal sort algorithm
 * 			is activated. In this case, the stack may be ordered
 * 			but not sorted.
 * 			Hence, this function ensures that the ordered stack
 * 			is sorted by searching for the head nbr and moving 
 * 			it to the top of the stack (sorted)
 * 
 * @param v 
 */
void	ft_on_ordered(t_var *v)
{
	(v->s_attr).nbr = *(int *)v->s->content;
	ft_is_nbr_in_stk((v->s_attr).nbr, &(v->a), &(v->a_attr));
	ft_move_nbr_to_stk_top(&(v->a), &(v->a_attr));
}

// This function search for the next and prev number in a sequence, given a
// number as the current.
int	ft_fetch_seq(int nbr, t_list **ss, t_attr *ss_attr)
{
	if (*ss == NULL)
		return (0);
	ft_update_stk_attr(ss, ss_attr);
	if (ft_is_nbr_n_stkhead(nbr, ss_attr))
		return (1);
	else
	{
		ss_attr->nbr_cur = nbr;
		while (ss_attr->cur->next != ss_attr->tail)
		{
			ss_attr->nbr = *((int *)ss_attr->cur->next->content);
			if (ss_attr->nbr == nbr)
			{
				ss_attr->nbr_prev = *((int *)ss_attr->cur->content);
				return (1);
			}
			ss_attr->cur = ss_attr->cur->next;
		}
		ss_attr->nbr_prev = *((int *)ss_attr->cur->content);
		ss_attr->nbr_nxt = *((int *)ss_attr->head->content);
		return (1);
	}
	return (0);
}

int	ft_is_nbr_in_stk(int nbr, t_list **stk, t_attr *s_attr)
{
	if (*stk == NULL)
		return (0);
	ft_update_stk_attr(stk, s_attr);
	s_attr->idx = 0;
	while (s_attr->cur != NULL)
	{
		s_attr->nbr = *(int *)s_attr->cur->content;
		if (nbr == s_attr->nbr)
			return (1);
		s_attr->cur = s_attr->cur->next;
		s_attr->idx++;
	}
	return (0);
}

/**
 * This function executes when match value is 1
 * This means that there is a match for the nbr preceeding the cur number
 * and that following the current number does not match
 * Hence, the function finds the right number and put it in place
 */
int	ft_on_next(t_var *v)
{
	v->rc = ft_is_nbr_in_stk((v->s_attr).nbr_nxt, &(v->b), &(v->b_attr));
	if (v->rc)
	{
		ft_move_nbr_to_stk_top(&(v->b), &(v->b_attr));
		ft_ps_stk_rotate(&(v->a), &(v->a_attr));
		ft_ps_stk_push(&(v->b), &(v->b_attr), &(v->a));
	}
	else
	{
		if (*(int *)((v->a)->next->next->content) == (v->s_attr).nbr_nxt)
		{
			ft_ps_stk_rotate(&(v->a), &(v->a_attr));
			ft_ps_stk_swap(&(v->a));
			ft_printf("sa\n");
			return (1);
		}
		ft_ps_stk_rotate(&(v->a), &(v->a_attr));
		ft_update_stk_attr(&(v->a), &(v->a_attr));
		ft_find_pos_in_stk((v->a_attr).nbr_cur, &(v->b), &(v->b_attr));
		ft_move_nbr_to_stk_top(&(v->b), &(v->b_attr));
		ft_ps_stk_push(&(v->a), &(v->a_attr), &(v->b));
		ft_ps_stk_rrotate(&(v->a), &(v->a_attr));
	}
	return (1);
}

/**
 * This function executes when match value is 8
 * This means that there is a match for the nbr following the cur number
 * and that preceeding the current number does not match
 * Hence, the function finds the right number and put it in place
 */
int	ft_on_prev(t_var *v)
{
	int	rc;

	rc = 0;
	rc = ft_is_nbr_in_stk((v->s_attr).nbr_nxt, &(v->b), &(v->b_attr));
	if (rc)
	{
		ft_move_nbr_to_stk_top(&(v->b), &(v->b_attr));
		ft_ps_stk_push(&(v->b), &(v->b_attr), &(v->a));
	}
	else
	{
		ft_ps_stk_rrotate(&(v->a), &(v->a_attr));
		ft_update_stk_attr(&(v->a), &(v->a_attr));
		ft_find_pos_in_stk((v->a_attr).nbr_cur, &(v->b), &(v->b_attr));
		ft_move_nbr_to_stk_top(&(v->b), &(v->b_attr));
		ft_ps_stk_push(&(v->a), &(v->a_attr), &(v->b));
	}
	return (1);
}
