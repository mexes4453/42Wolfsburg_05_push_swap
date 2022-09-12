/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_srt_a_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 12:43:22 by cudoh             #+#    #+#             */
/*   Updated: 2022/07/31 13:57:08 by cudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "quick_srt_a_utils.h"

/**
 * @brief 	This func converts a stack to array, sort it & fetch the median
 * 			The median is stored in a_attr.nbr
 * @param a
 * @param a_attr
 * @return int -> returns 1 if successful
 */
int	ft_get_midpoint_stk(t_list **a, t_attr *a_attr)
{
	int	mp_idx;
	int	*nbrs;

	nbrs = NULL;
	ft_update_stk_attr(a, a_attr);
	if (a_attr->stk_size <= 2)
		return (0);
	if (a_attr->stk_size % 2 == 0)
		mp_idx = (a_attr->stk_size / 2) - 1;
	else
		mp_idx = (a_attr->stk_size / 2);
	nbrs = ft_conv_stk_arr(a, a_attr);
	if (nbrs == 0)
		return (0);
	ft_arr_sort(nbrs, a_attr->stk_size);
	a_attr->nbr = nbrs[mp_idx];
	free(nbrs);
	return (1);
}

/**
 * Sort array of integers using bubble sort algorithm
 */
int	ft_arr_sort(int *nbrs, int arr_sz)
{
	int	temp;
	int	x;
	int	y;

	temp = 0;
	x = 0;
	if (nbrs == NULL)
		return (0);
	while (x < arr_sz - 1)
	{
		y = x + 1;
		while (y < arr_sz)
		{
			if (nbrs[y] < nbrs[x])
			{
				temp = nbrs[y];
				nbrs[y] = nbrs[x];
				nbrs[x] = temp;
			}
			y++;
		}
		x++;
	}
	return (1);
}

void	ft_arr_print(int *nbrs, int sz)
{
	int	idx;

	idx = 0;
	while (idx < sz)
	{
		ft_printf("\nARR_IDX: %d <-> %d", idx, nbrs[idx]);
		idx++;
	}
}

void	ft_sort_stk(t_list **s, t_attr *sattr)
{
	int	mp_idx;
	int	*nbrs;

	nbrs = NULL;
	ft_update_stk_attr(s, sattr);
	if (sattr->stk_size <= 2)
		return ;
	if (sattr->stk_size % 2 == 0)
		mp_idx = (sattr->stk_size / 2) - 1;
	else
		mp_idx = (sattr->stk_size / 2);
	nbrs = ft_conv_stk_arr(s, sattr);
	if (nbrs == 0)
		return ;
	sattr->nbr = nbrs[mp_idx];
	ft_arr_sort(nbrs, sattr->stk_size);
	free(nbrs);
}

/**
 *	This function returns the number of chunk
 *  required for a given array of size
 *  The computed count includes a safe margin.
 *  Input : int	-> Array size
 */
int	ft_get_chunk_sz_req(int size)
{
	int	count;
	int	safe;

	count = 0;
	safe = 5;
	while (size > 2)
	{
		size = ((size / 2) + 1);
		count++;
	}
	return ((count + safe) * 2);
}
