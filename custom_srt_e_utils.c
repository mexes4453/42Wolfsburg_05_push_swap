/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom_srt_e_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 13:52:19 by cudoh             #+#    #+#             */
/*   Updated: 2022/07/31 13:52:19 by cudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "custom_srt_e_utils.h"
#include "push_swap.h"

void	ft_sa_action(t_var *v)
{
	int	match_nbr;

	match_nbr = (v->a_attr).rc;
	if (match_nbr == 0)
		ft_on_prev(v);
	else if (match_nbr == 2)
		ft_on_match_2(v);
	else if (match_nbr == 4)
	{
		ft_ps_stk_swap(&(v->a));
		ft_printf("sa\n");
	}
	else if (match_nbr == 6)
		ft_on_match_6(v);
	else if (match_nbr == 8)
		ft_on_prev(v);
	else if (match_nbr == 1)
		ft_on_next(v);
	else if (match_nbr == 9)
		ft_ps_stk_rotate(&(v->a), &(v->a_attr));
	else if (match_nbr == 10)
	{
		ft_ps_stk_push(&(v->b), &(v->b_attr), &(v->a));
	}
}

/**
 * @brief 	This function execute the stack operations after
 * 			comparison of two stack state (stk a and stk s)
 * 			matches the value of 6
 * todo 	Pre-requisite function: ft_check_sa
 * !		This function is used for the custom sort algorithm
 */
void	ft_on_match_6(t_var *v)
{
	if ((v->a_attr).stk_size == 3)
	{
		ft_ps_stk_rrotate(&(v->a), &(v->a_attr));
		ft_ps_stk_swap(&(v->a));
		ft_printf("sa\n");
	}
	else
	{
		ft_ps_stk_swap(&(v->a));
		ft_printf("sa\n");
		ft_ps_stk_rrotate(&(v->a), &(v->a_attr));
		ft_ps_stk_swap(&(v->a));
		ft_printf("sa\n");
		ft_ps_stk_rotate(&(v->a), &(v->a_attr));
		ft_ps_stk_swap(&(v->a));
		ft_printf("sa\n");
	}
}

/**
 * @brief 	This function execute the stack operations after
 * 			comparison of two stack state (stk a and stk s)
 * 			matches the value of 2
 * todo 	Pre-requisite function: ft_check_sa
 * !		This function is used for the custom sort algorithm
 */
void	ft_on_match_2(t_var *v)
{
	ft_ps_stk_rrotate(&(v->a), &(v->a_attr));
	ft_ps_stk_swap(&(v->a));
	ft_printf("sa\n");
}

int	ft_match_sa_nbr(t_attr *sa_attr, t_attr *ss_attr)
{
	int	rc;

	rc = 0;
	if (sa_attr->nbr_prev == ss_attr->nbr_prev)
		rc |= (1 << 0);
	else
	{
		rc &= ~(1 << 0);
	}
	if (sa_attr->nbr_nxt == ss_attr->nbr_nxt)
		rc |= (1 << 1);
	else
		rc &= ~(1 << 1);
	return (rc);
}

/**
 * @brief 	This function checks the orderliness (ascending or descending)
 * 			of the nbrs on a given stack.
 * 			This is done in comparison with the sequence of nbr in the sorted
 * 			stack.
 * @param a 
 * @param a_attr 
 * @param s 
 * @param s_attr 
 * @return int
 */
int	ft_is_ordered(t_list **a, t_attr *a_attr, t_list **s, t_attr *s_attr)
{
	int	*nbrs;

	nbrs = NULL;
	nbrs = ft_conv_stk_arr(a, a_attr);
	if (nbrs == 0)
		return (0);
	a_attr->idx = 0;
	while (a_attr->idx < a_attr->stk_size)
	{
		ft_fetch_seq(*(nbrs + a_attr->idx), a, a_attr);
		ft_fetch_seq(*(nbrs + a_attr->idx), s, s_attr);
		if (ft_match_sa_nbr(a_attr, s_attr) != 3)
		{
			a_attr->nbr = *(nbrs + a_attr->idx);
			free(nbrs);
			return (-1);
		}
		a_attr->idx++;
	}
	free(nbrs);
	return (1);
}
