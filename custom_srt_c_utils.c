/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom_srt_c_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 12:48:04 by cudoh             #+#    #+#             */
/*   Updated: 2022/07/31 12:48:04 by cudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "custom_srt_c_utils.h"

void	ft_upd_get_seq(t_list **a, t_attr *a_attr, t_list **s, t_attr *s_attr)
{
	ft_update_stk_attr(a, a_attr);
	ft_fetch_stk_data(a_attr);
	ft_update_stk_attr(s, s_attr);
	ft_get_seq(s, s_attr, a, a_attr);
}

int	ft_is_stk_full(t_list **stk, t_attr *s_attr, t_attr *ss_attr)
{
	ft_update_stk_attr(stk, s_attr);
	if (s_attr->stk_size != ss_attr->stk_size)
		return (0);
	return (1);
}

int	ft_is_headcur(t_attr *ss_attr, t_attr *sa_attr)
{
	if (ss_attr->nbr_cur == sa_attr->nbr_cur)
	{
		ss_attr->nbr_prev = *((int *)ss_attr->tail->content);
		if (ss_attr->head->next == NULL)
			ss_attr->nbr_nxt = ss_attr->nbr_cur;
		else
			ss_attr->nbr_nxt = *((int *)ss_attr->head->next->content);
		return (1);
	}
	return (0);
}

/**
 * @brief 		This function checks if a nbr is at the top of a stack
 * 				The stack attr must be update before use.
 * todo			pre-requisite function : ft_update_stk_attr
 * 
 * @param nbr 
 * @param s_attr 
 * @return int 
 */
int	ft_is_nbr_n_stkhead(int nbr, t_attr *s_attr)
{
	if (s_attr->head == NULL)
		return (0);
	s_attr->nbr_cur = *((int *)s_attr->head->content);
	if (s_attr->nbr_cur == nbr)
	{
		s_attr->nbr_prev = *((int *)s_attr->tail->content);
		if (s_attr->head->next == NULL)
			s_attr->nbr_nxt = s_attr->nbr_cur;
		else
			s_attr->nbr_nxt = *((int *)s_attr->head->next->content);
		return (1);
	}
	return (0);
}

void	ft_print_stkdata(t_attr *sattr)
{
	ft_printf("\nPREV: %d", sattr->nbr_prev);
	ft_printf("\nCURR: %d <-", sattr->nbr_cur);
	ft_printf("\nNEXT: %d\n", sattr->nbr_nxt);
}
