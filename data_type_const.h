/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_type_const.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 11:39:48 by cudoh             #+#    #+#             */
/*   Updated: 2022/07/31 11:39:48 by cudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_TYPE_CONST_H
# define DATA_TYPE_CONST_H
# define MAX_CHUNK_CNT_STK_A (1)
# define MIN_CHUNK_SZ_STK_A (2)
# define FLAG_QS_CHUNK_CREATE (1)
# define QS_MIN_RANGE (7)
# include "libft/libft.h"

// ---- DATA TYPES ----//
typedef struct s_sattr
{
	int		stk_size;
	int		*chunk;
	int		chunk_cnt;
	int		chunk_idx;
	int		chunk_sz;
	int		*chunk_lens;
	int		idx;
	int		nbr;
	int		rc;
	char	id;
	char	ops_flags;
	t_list	*head;
	t_list	*cur;
	t_list	*tail;
	int		nbr_prev;
	int		nbr_cur;
	int		nbr_nxt;
	void	*ptr;
}			t_attr;
typedef struct s_var
{
	t_list	*a;
	t_list	*b;
	t_list	*s;
	t_attr	a_attr;
	t_attr	b_attr;
	t_attr	s_attr;
	int		(*f_srt_a)(int, int);
	int		(*f_srt_d)(int, int);
	int		flag;
	int		rc;
	int		iter_cnt;
	int		iter_limit;
	int		size;
}			t_var;
#endif
