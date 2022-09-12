/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_srt_f_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 13:10:27 by cudoh             #+#    #+#             */
/*   Updated: 2022/08/04 19:50:17 by cudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "quick_srt_f_utils.h"

/**
 * @brief 		This function creates chunks on stack b by pushing
 * 				nbrs from stack a until there is only two nbrs
 * 				left on stack a.
 * 				This function should be executed only once.
 * !			Turn of flag on execution complete (bit 0)
 * @param v 
 * @return int 
 */
int	ft_qs_create_chk_on_b(t_var *v)
{
	if ((v->flag & FLAG_QS_CHUNK_CREATE) == 0)
		return (1);
	if (ft_chunk_alloc_ab(&(v->a_attr), &(v->b_attr)) == 0)
		return (0);
	(v->a_attr).nbr = ft_get_chunk_sz_req((v->a_attr).stk_size);
	while ((v->a_attr).stk_size > MIN_CHUNK_SZ_STK_A)
	{
		ft_get_midpoint_stk(&(v->a), &(v->a_attr));
		ft_p_st_ab(&(v->a), &(v->a_attr), &(v->b), &(v->b_attr));
		(v->b_attr).rc = ft_upd_chunk_data(&(v->b_attr));
		if ((v->b_attr).rc == 0)
		{
			ft_printf("\nError");
			return (0);
		}
		ft_upd_get_seq(&(v->a), &(v->a_attr), &(v->s), &(v->s_attr));
		ft_update_stk_attr(&(v->a), &(v->a_attr));
		ft_update_stk_attr(&(v->b), &(v->b_attr));
	}
	v->flag &= ~FLAG_QS_CHUNK_CREATE;
	return (1);
}

/**
 * @brief 	This function push all item on current chunk in stack b to a
 * 			if all item in chunk a sorted in descending order.
 * todo		pre-requisite function : ft_is_chunk_sorted
 * 
 * @param v 
 */
void	ft_qs_push_on_sort_ba(t_var *v)
{
	int	idx;

	idx = 0;
	(v->b_attr).idx = 0;
	idx = v->b_attr.chunk_idx - 1;
	(v->b_attr).chunk_sz = (v->b_attr).chunk_lens[idx];
	while ((v->b_attr).idx < (v->b_attr).chunk_sz)
	{
		ft_ps_stk_push(&(v->b), &(v->b_attr), &(v->a));
		(v->b_attr).idx++;
	}
	(v->b_attr).chunk_idx--;
}

/**
 * @brief 		This function pushes all item from chunk a to stk b
 * 				using the quick sort algorithm.
 * 				numbers greater than the chunk median nbr is pushed.
 * 
 * @param v 
 * @return int 
 */
int	ft_qs_empty_chk_a(t_var *v)
{
	int	nbr;

	nbr = 0;
	ft_ch_n_sta(&(v->a), &(v->a_attr), &(v->s), &(v->s_attr));
	if ((v->a_attr).rc)
	{
		while ((v->a_attr).chunk_lens[(v->a_attr).chunk_idx - 1] > 2)
		{
			(v->a_attr).nbr = ft_get_midpt_chunk(&(v->a), &(v->a_attr));
			nbr = ft_p_st_ch(&(v->a), &(v->a_attr), &(v->b), v->f_srt_d);
			if (nbr)
			{
				(v->b_attr).chunk_lens[(v->b_attr).chunk_idx] = nbr;
				(v->b_attr).chunk_idx++;
			}
			ft_exe_stk_op(&(v->a), &(v->a_attr), &(v->b), &(v->b_attr));
		}
		((v->a_attr).chunk_idx)--;
	}
	else
		return (0);
	return (1);
}

/**
 * @brief 		This function performs recursive push between stack a and b
 * 				starting from stack b to a if there is available chunk on 
 * 				stack b
 * 
 * @param v 
 * @return int 
 */
int	ft_qs_recurse_push_abba(t_var *v)
{
	int	rc;

	rc = 0;
	(v->b_attr).nbr = ft_get_midpt_chunk(&(v->b), &(v->b_attr));
	ft_p_st_ch(&(v->b), &(v->b_attr), &(v->a), v->f_srt_a);
	ft_exe_stk_op(&(v->a), &(v->a_attr), &(v->b), &(v->b_attr));
	rc = ft_qs_empty_chk_a(v);
	return (rc);
}

/**
 * @brief 	This function sorts recursively all items on current chk on stk b
 * 
 * @param v 
 */
int	ft_qs_sort_chk_on_b(t_var *v)
{
	int	sz;

	sz = (v->b_attr).chunk_lens[(v->b_attr).chunk_idx - 1];
	ft_exe_stk_op(&(v->a), &(v->a_attr), &(v->b), &(v->b_attr));
	if (sz <= 2)
	{
		while (sz-- > 0)
			ft_ps_stk_push(&(v->b), &(v->b_attr), &(v->a));
		(v->b_attr).chunk_idx--;
	}
	else if (sz > 2)
	{
		(v->b_attr).rc = ft_is_chunk_sorted(&(v->b), &(v->b_attr), v->f_srt_d);
		if ((v->b_attr).rc == 1)
			ft_qs_push_on_sort_ba(v);
		else if ((v->b_attr).rc == -1)
			ft_qs_recurse_push_abba(v);
		else
			return (0);
	}
	return (1);
}
