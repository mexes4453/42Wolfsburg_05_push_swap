/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_srt_c_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 12:55:39 by cudoh             #+#    #+#             */
/*   Updated: 2022/07/31 13:48:35 by cudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "quick_srt_c_utils.h"

/**
 * @brief
 *		pivot stack operation
 *		ft_p_st_ab : push stack operation between stack a and b
 * 		The number of push performed in store in (a_attr.chunk_sz)
 * todo	The function ft_get_midpoint_stk must be called before use.
 * todo The pre-requisite function stores the median value in s_attr.nbr
 *
 *
 * @param a
 * @param a_attr
 * @param b
 * @returns - the number of push operation performed
 */
int	ft_p_st_ab(t_list **a, t_attr *a_attr, t_list **b, t_attr *b_attr)
{
	int	sz;
	int	cnt;
	int	median;

	cnt = 0;
	median = a_attr->nbr;
	ft_update_stk_attr(a, a_attr);
	sz = a_attr->stk_size;
	while (sz > 0)
	{
		if (median > *(int *)a_attr->cur->content)
		{
			ft_ps_stk_push(a, a_attr, b);
			cnt++;
		}
		else
			ft_ps_stk_rotate(a, a_attr);
		ft_update_stk_attr(a, a_attr);
		sz--;
	}
	b_attr->chunk_sz = cnt;
	return (cnt);
}

/**
 * @brief
 * 			This function updates the following chunks data.
 * 			chunk_idx  : the idx is incremented after update.
 * 			chunk_lens : stored in the buffer the chunk_sz given the idx
 * todo 	pre-requisite function : ft_p_st_ab
 * todo		The chunk size equals the number of push operations performed
 * todo		under a given midpoint value. (ft_p_st_ab)
 * !		The chunk_sz is updated by the pre-requisite function
 * @param s_attr
 * @return int 		: returns 1 if successful
 */
int	ft_upd_chunk_data(t_attr *s_attr)
{
	int	idx;

	idx = s_attr->chunk_idx;
	if (s_attr->chunk_sz == 0)
		return (0);
	s_attr->chunk_lens[idx] = s_attr->chunk_sz;
	s_attr->chunk_idx = idx + 1;
	return (1);
}

/**
 * @brief 	returns an array which reproduces the chunk from the stack
 * 			given the chunk size
 *
 * @param s
 * @param s_attr
 * @return int*
 */
int	*ft_retrieve_chunk(t_list **s, t_attr *s_attr)
{
	int	idx;
	int	*nbrs;

	idx = 0;
	nbrs = NULL;
	s_attr->idx = s_attr->chunk_idx - 1;
	s_attr->chunk_sz = s_attr->chunk_lens[s_attr->idx];
	nbrs = (int *)malloc(sizeof(int) * s_attr->chunk_sz);
	if (nbrs == NULL)
		return (NULL);
	ft_update_stk_attr(s, s_attr);
	while (idx < s_attr->chunk_sz)
	{
		nbrs[idx] = *(int *)s_attr->cur->content;
		s_attr->cur = s_attr->cur->next;
		idx++;
	}
	return (nbrs);
}

void	ft_check_chunks(t_list **s, t_attr *attr)
{
	int	x;
	int	y;
	int	*nbrs;

	x = attr->chunk_idx - 1;
	y = 0;
	nbrs = ft_conv_stk_arr(s, attr);
	if (nbrs == 0)
		return ;
	attr->idx = 0;
	while (x >= 0)
	{
		attr->chunk_sz = (attr->chunk_lens)[x];
		while (y < attr->chunk_sz)
		{
			y++;
			(attr->idx)++;
		}
		x--;
		y = 0;
	}
	free(nbrs);
}

/**
 * @brief	this function allocates the memory required for chunk operations
 * 			on a stack given the stack attribute struct.
 * 	todo	Ensure that the s_attr.chunk_cnt is updated
 *
 * @param s_attr
 * @return int
 */
int	ft_chunk_alloc(t_attr *s_attr)
{
	s_attr->chunk_lens = (int *)malloc(sizeof(int) * s_attr->chunk_cnt);
	if (s_attr->chunk_lens == NULL)
		return (0);
	return (1);
}
