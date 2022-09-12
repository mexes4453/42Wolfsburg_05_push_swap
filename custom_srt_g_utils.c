/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom_srt_g_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 14:12:41 by cudoh             #+#    #+#             */
/*   Updated: 2022/07/31 14:12:41 by cudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "custom_srt_g_utils.h"

int	ft_op_x(int c, t_list **a, t_attr *at, int (*f)(t_list **, t_attr *))
{
	int	rc;

	rc = 0;
	while (c--)
	{
		rc = f(a, at);
	}
	return (rc);
}

int	*ft_conv_stk_arr(t_list **sa, t_attr *sa_attr)
{
	int	size;
	int	*nbrs;

	size = 0;
	nbrs = NULL;
	sa_attr->idx = 0;
	if (*sa == NULL)
		return (0);
	ft_update_stk_attr(sa, sa_attr);
	ft_fetch_stk_data(sa_attr);
	size = sa_attr->stk_size;
	if (size)
		nbrs = (int *)malloc(sizeof(int) * (size + 1));
	if (nbrs == NULL)
		return (0);
	ft_bzero((void *)nbrs, (size + 1));
	*(nbrs + size) = '\0';
	while (sa_attr->idx < size)
	{
		sa_attr->nbr = *(int *)sa_attr->cur->content;
		*(nbrs + sa_attr->idx) = sa_attr->nbr;
		sa_attr->cur = sa_attr->cur->next;
		sa_attr->idx++;
	}
	return (nbrs);
}

int	ft_find_pos_in_stk(int nbr, t_list **sa, t_attr *sa_attr)
{
	int	*nbrs;
	int	idx_prev;

	nbrs = ft_conv_stk_arr(sa, sa_attr);
	if (nbrs == 0)
		return (0);
	sa_attr->idx = 0;
	while (sa_attr->idx < sa_attr->stk_size)
	{
		sa_attr->nbr = nbrs[sa_attr->idx];
		if (sa_attr->idx == 0 && sa_attr->stk_size == 1)
			idx_prev = sa_attr->idx;
		else if (sa_attr->idx == 0 && (sa_attr->stk_size) > 1)
			idx_prev = (sa_attr->stk_size) - 1;
		else
			idx_prev = (sa_attr->idx) - 1;
		if ((nbrs[sa_attr->idx] > nbr && nbrs[idx_prev] < nbr))
		{
			free(nbrs);
			return (1);
		}
		sa_attr->idx++;
	}
	free(nbrs);
	return (0);
}

int	ft_custom_sort(t_var *v)
{
	v->rc = ft_is_ordered(&(v->a), &(v->a_attr), &(v->s), &(v->s_attr));
	if (v->rc == 1 && v->b == NULL)
		ft_on_ordered(v);
	else if (v->rc == -1 || v->b != NULL)
	{
		ft_fetch_seq((v->a_attr).nbr, &(v->s), &(v->s_attr));
		ft_move_nbr_to_stk_top(&(v->a), &(v->a_attr));
		ft_upd_get_seq(&(v->a), &(v->a_attr), &(v->s), &(v->s_attr));
		ft_check_sa(&(v->a), &(v->a_attr), &(v->s), &(v->s_attr));
		ft_sa_action(v);
	}
	return (1);
}
