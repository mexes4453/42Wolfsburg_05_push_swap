/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_srt_d_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 15:18:00 by cudoh             #+#    #+#             */
/*   Updated: 2022/07/31 15:18:00 by cudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "quick_srt_d_utils.h"

/**
 * @brief	this function allocates the memory required for chunk operations
 * 			for stack a and b
 * 			This function depends on func (ft_chunk_alloc)
 * 	todo	Ensure that the s_attr is updated before func use.
 *
 * @param a_attr
 * @param b_attr
 * @return int
 */
int	ft_chunk_alloc_ab(t_attr *a_attr, t_attr *b_attr)
{
	a_attr->rc = 0;
	b_attr->rc = 0;
	a_attr->chunk_cnt = MAX_CHUNK_CNT_STK_A;
	b_attr->chunk_cnt = ft_get_chunk_sz_req(a_attr->stk_size);
	a_attr->rc = ft_chunk_alloc(a_attr);
	b_attr->rc = ft_chunk_alloc(b_attr);
	if (a_attr->rc == 0 || b_attr->rc == 0)
		return (0);
	return (1);
}

/**
 * @brief : return  1 if a chunk is already sorted
 * 			return -1 if a chunk is not sorted.
 * 			return  0 on error
 * 			This function uses hooks to changed the sort order between
 * 			ascending and descending.
 *
 * @param chunk
 * @param chunk_sz
 * @return int
 */

int	ft_is_chunk_sorted(t_list **s, t_attr *s_attr, int (*func)(int, int))
{
	int	idx;
	int	*chunk;
	int	chunk_sz;

	idx = 0;
	chunk = NULL;
	chunk = ft_retrieve_chunk(s, s_attr);
	if (chunk == NULL)
		return (0);
	chunk_sz = s_attr->chunk_lens[s_attr->chunk_idx - 1];
	while (idx < (chunk_sz - 1))
	{
		if (func(chunk[idx], chunk[idx + 1]))
			idx++;
		else
		{
			free(chunk);
			return (-1);
		}
	}
	free(chunk);
	return (1);
}

/**
 * @brief : A hook for sorting arrays in ascending order
 * 			returns negative integer
 *
 * @param a
 * @param b
 * @return int
 */
int	ft_sort_ascend(int a, int b)
{
	if (a < b)
		return (1);
	return (0);
}

/**
 * @brief : A hook for sorting arrays in descending order
 * 			returns positive integer
 *
 * @param a
 * @param b
 * @return int
 */
int	ft_sort_descend(int a, int b)
{
	if (a > b)
		return (1);
	return (0);
}

/**
 * @brief 	This function returns the median of an array of integers
 * 			given the pointer to the array and the array size.
 * 			A copy of the given array is created for this operation.
 *
 * @param nbrs
 * @param sz
 * @return int
 */
int	ft_get_midpoint_arr(int *nbrs, int sz)
{
	int	mp_idx;
	int	res;
	int	*arr_cpy;

	arr_cpy = NULL;
	if (nbrs == NULL || sz == 0)
		return (0);
	arr_cpy = (int *)malloc(sz * sizeof(int));
	if (arr_cpy == NULL)
		return (0);
	ft_memcpy((void *)arr_cpy, (void *)nbrs, (sizeof(int) * sz));
	if (sz % 2 == 0)
		mp_idx = (sz / 2) - 1;
	else
		mp_idx = (sz / 2);
	ft_arr_sort(arr_cpy, sz);
	res = arr_cpy[mp_idx];
	free(arr_cpy);
	return (res);
}
