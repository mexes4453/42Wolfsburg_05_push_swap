/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_srt_b_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 12:48:33 by cudoh             #+#    #+#             */
/*   Updated: 2022/07/31 15:09:19 by cudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "quick_srt_b_utils.h"

/**
 * @brief This function logs the action to be performed on a stk
 * 			The flags for the stack operations are as follows
 * 			1 1 1 0 0 1 1 1 (8 bits -> 0 - 7)
 * 			7 6 5 4 3 2 1 0
 *			| | | | | | | |__ rrb
 * 			| | | | | |	|____ rb
 *  	 	| | | | | |______ sb
 *  	 	| | | | |________ pb
 * @param s
 * @param sattr
 */
void	ft_log_stk_op(t_list **s, t_attr *sattr)
{
	if (*s == NULL)
		return ;
	ft_update_stk_attr(s, sattr);
	if (sattr->cur->next)
	{
		sattr->nbr_nxt = *(int *)sattr->cur->next->content;
		sattr->nbr_cur = *(int *)sattr->cur->content;
		if ((sattr->nbr_nxt > sattr->nbr_cur) && sattr->id == 'b')
			sattr->ops_flags |= (1 << 2);
		else if ((sattr->nbr_nxt < sattr->nbr_cur) && sattr->id == 'a')
			sattr->ops_flags |= (1 << 2);
	}
}

void	ft_exe_stk_op(t_list **a, t_attr *a_attr, t_list **b, t_attr *b_attr)
{
	ft_log_stk_op(a, a_attr);
	ft_log_stk_op(b, b_attr);
	if ((a_attr->ops_flags & b_attr->ops_flags) == 4)
	{
		ft_ps_stk_swap(a);
		ft_ps_stk_swap(b);
		ft_printf("ss\n");
	}
	else if ((a_attr->ops_flags & (1 << 2)) == 4)
	{
		ft_ps_stk_swap(a);
		ft_printf("sa\n");
	}
	else if ((b_attr->ops_flags & (1 << 2)) == 4)
	{
		ft_ps_stk_swap(b);
		ft_printf("sb\n");
	}
	a_attr->ops_flags = 0;
	b_attr->ops_flags = 0;
}

void	ft_free_stk(t_list **ss, t_list **sa, t_list **sb)
{
	ft_lstclear(ss, ft_ps_del_node);
	ft_lstclear(sa, ft_ps_del_node);
	ft_lstclear(sb, ft_ps_del_node);
}

void	ft_free_attr(t_attr *s_attr)
{
	if (s_attr->chunk)
		free(s_attr->chunk);
	if (s_attr->chunk_lens)
		free(s_attr->chunk_lens);
	s_attr->chunk = NULL;
	s_attr->chunk_lens = NULL;
}

/**
 * @brief 		This function frees all memory alloc on heap
 * 
 * @param v 
 * @return int 
 */
void	ft_free_heap(t_var *v)
{
	ft_free_stk(&(v->s), &(v->a), &(v->b));
	ft_free_attr(&(v->a_attr));
	ft_free_attr(&(v->b_attr));
}
