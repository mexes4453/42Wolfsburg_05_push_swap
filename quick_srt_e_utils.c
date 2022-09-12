/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_srt_e_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 13:06:29 by cudoh             #+#    #+#             */
/*   Updated: 2022/07/31 13:08:29 by cudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "quick_srt_e_utils.h"

/**
 * @brief 	returns the median of the most top chunk for a stack
 *
 * @param s_attr
 * @return int
 */
int	ft_get_midpt_chunk(t_list **s, t_attr *s_attr)
{
	int	*nbrs;
	int	sz;
	int	res;

	nbrs = ft_retrieve_chunk(s, s_attr);
	if (nbrs == 0)
		return (0);
	sz = s_attr->chunk_lens[s_attr->chunk_idx - 1];
	res = ft_get_midpoint_arr(nbrs, sz);
	free(nbrs);
	return (res);
}

/**
 * @brief 	The function pushes nbrs from stack b to a.
 * 			its decision is based on array which is extend
 * 			to the stack for consistency.
 * 			operations on array are also implemented on stack
 * todo		pre-requisite func : ft_get_midpt_chunk
 * @brief	The pre-requisite func updates the attr.nbr with
 * 			the median value.
 * @param s_attr
 * @param median
 * @return int : returns the number of push operation performed
 */
int	ft_p_st_ch(t_list **b, t_attr *b_attr, t_list **a, int (*f)(int, int))
{
	int	push_cnt;

	push_cnt = 0;
	b_attr->rc = 0;
	b_attr->idx = 0;
	b_attr->chunk = ft_retrieve_chunk(b, b_attr);
	if (b_attr->chunk == NULL)
		return (0);
	ft_p_st_ch1(b, b_attr, a, f);
	ft_op_x(b_attr->rc, b, b_attr, ft_ps_stk_rrotate);
	free(b_attr->chunk);
	b_attr->chunk = NULL;
	push_cnt = b_attr->idx;
	return (push_cnt);
}

/**
 * @brief       This function is a refactor of ft_p_st_ch
 *              It pushes items from chunks on stk to chunks on another
 *              the push counter and rotate counter are updated within
 *              The no of push ops performed is stored in attr.idx
 *				The no of rotate ops performed is stored in attr.rc
 * @param b
 * @param b_attr
 * @param a
 */
void	ft_p_st_ch1(t_list **b, t_attr *b_attr, t_list **a, int (*f)(int, int))
{
	int	idx;
	int	sz;

	idx = 0;
	sz = b_attr->chunk_lens[b_attr->chunk_idx - 1];
	while (idx < sz)
	{
		if (f(b_attr->nbr, b_attr->chunk[idx]))
		{
			ft_ps_stk_push(b, b_attr, a);
			(b_attr->chunk_lens[b_attr->chunk_idx - 1])--;
			(b_attr->idx)++;
		}
		else
		{
			if (idx != (sz - 1))
			{
				ft_ps_stk_rotate(b, b_attr);
				(b_attr->rc)++;
			}
		}
		ft_update_stk_attr(b, b_attr);
		idx++;
	}
}

/**
 * @brief 			This function checks for the first unmatched nbr within
 * 					stack a list starting for the stack bottom.
 * 					The found idx and the rest of nbrs up to the stack top
 * 					is considered as the chunk in stack a.
 *
 * @param a
 * @param a_attr
 * @param ss
 * @param ss_attr
 * @return int
 */
void	ft_ch_n_sta(t_list **a, t_attr *a_attr, t_list **ss, t_attr *ss_attr)
{
	int	*stk_arr_a;
	int	*stk_arr_ss;

	a_attr->rc = 0;
	ft_update_stk_attr(a, a_attr);
	ft_update_stk_attr(ss, ss_attr);
	a_attr->idx = (a_attr->stk_size) - 1;
	ss_attr->idx = (ss_attr->stk_size) - 1;
	stk_arr_a = ft_conv_stk_arr(a, a_attr);
	stk_arr_ss = ft_conv_stk_arr(ss, ss_attr);
	if (stk_arr_a == 0 || stk_arr_ss == 0)
		return ;
	ft_ch_n_sta1(a_attr, ss_attr, stk_arr_a, stk_arr_ss);
	free(stk_arr_a);
	free(stk_arr_ss);
}

/**
 * @brief 		This function is a refactor func of ft_ch_n_sta
 * 				Check the func documentation for its operation.
 * 
 * @param a_attr 
 * @param s_attr 
 * @param a 
 * @param s 
 */
void	ft_ch_n_sta1(t_attr *a_attr, t_attr *s_attr, int *a, int *s)
{
	while (a_attr->idx >= 0)
	{
		if (a[a_attr->idx] != s[s_attr->idx])
		{
			a_attr->chunk_lens[a_attr->chunk_idx] = (a_attr->idx + 1);
			(a_attr->chunk_idx)++;
			a_attr->rc = 1;
			break ;
		}
		a_attr->idx--;
		s_attr->idx--;
	}
}
