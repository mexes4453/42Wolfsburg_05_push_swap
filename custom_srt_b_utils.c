/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom_srt_b_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 12:14:11 by cudoh             #+#    #+#             */
/*   Updated: 2022/07/31 12:14:11 by cudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "custom_srt_b_utils.h"

void	ft_attr_init(t_attr *sattr, char stk_id)
{
	sattr->stk_size = 0;
	sattr->idx = 0;
	sattr->nbr = 0;
	sattr->rc = 0;
	sattr->id = stk_id;
	sattr->ops_flags = 0;
	sattr->head = NULL;
	sattr->cur = NULL;
	sattr->tail = NULL;
	sattr->nbr_prev = 0;
	sattr->nbr_cur = 0;
	sattr->nbr_nxt = 0;
	sattr->ptr = NULL;
	sattr->chunk = NULL;
	sattr->chunk_sz = 0;
	sattr->chunk_cnt = 0;
	sattr->chunk_idx = 0;
}

int	ft_is_sorted(t_list *s_list, t_list **stk, t_attr *s_attr)
{
	t_list	*h_sort;
	int		n_sort;

	s_attr->cur = *stk;
	h_sort = s_list;
	s_attr->idx = 0;
	s_attr->rc = 0;
	while (s_attr->idx < s_attr->stk_size)
	{
		s_attr->nbr = *((int *)s_attr->cur->content);
		n_sort = *((int *)h_sort->content);
		if (s_attr->nbr != n_sort)
			return (0);
		s_attr->cur = s_attr->cur->next;
		h_sort = h_sort->next;
		s_attr->idx++;
	}
	ft_update_stk_attr(stk, s_attr);
	return (1);
}

void	ft_update_stk_attr(t_list **stk, t_attr *sattr)
{
	t_list	*header;

	if (*stk == NULL)
	{
		ft_attr_init(sattr, sattr->id);
		return ;
	}
	header = *stk;
	sattr->stk_size = ft_lstsize(header);
	sattr->tail = ft_lstlast(header);
	sattr->head = header;
	sattr->cur = sattr->head;
	sattr->nbr_cur = *((int *)sattr->cur->content);
}

void	ft_fetch_stk_data(t_attr *s_attr)
{
	if (!s_attr->head)
		return ;
	s_attr->nbr_cur = *((int *)s_attr->head->content);
	if (s_attr->head->next == NULL)
	{
		s_attr->nbr_nxt = s_attr->nbr_cur;
	}
	else
	{
		s_attr->nbr_nxt = *((int *)s_attr->head->next->content);
	}
	if (s_attr->tail == s_attr->head)
	{
		s_attr->nbr_prev = s_attr->nbr_cur;
	}
	else
	{
		s_attr->nbr_prev = *((int *)s_attr->tail->content);
	}
}

void	ft_get_seq(t_list **ss, t_attr *ss_attr, t_list **sa, t_attr *sa_attr)
{
	ft_update_stk_attr(sa, sa_attr);
	ft_update_stk_attr(ss, ss_attr);
	if (ft_is_headcur(ss_attr, sa_attr))
		return ;
	else
	{
		ss_attr->nbr_cur = sa_attr->nbr_cur;
		ss_attr->cur = ss_attr->head;
		while (ss_attr->cur->next != ss_attr->tail)
		{
			ss_attr->nbr = *((int *)ss_attr->cur->next->content);
			if (ss_attr->nbr == sa_attr->nbr_cur)
			{
				ss_attr->nbr_prev = *((int *)ss_attr->cur->content);
				ss_attr->nbr_nxt = *((int *)ss_attr->cur->next->next->content);
				return ;
			}
			ss_attr->cur = ss_attr->cur->next;
		}
		ss_attr->nbr_prev = *((int *)ss_attr->cur->content);
		ss_attr->nbr_nxt = *((int *)ss_attr->head->content);
	}
}
