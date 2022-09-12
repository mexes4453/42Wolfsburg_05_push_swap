/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_srt_d_utils.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 15:13:37 by cudoh             #+#    #+#             */
/*   Updated: 2022/07/31 15:13:37 by cudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUICK_SRT_D_UTILS_H
# define QUICK_SRT_D_UTILS_H
# include "data_type_const.h"
# include "push_swap.h"

int		ft_chunk_alloc_ab(t_attr *a_attr, t_attr *b_attr);
int		ft_is_chunk_sorted(t_list **s, t_attr *s_attr, int (*func)(int, int));
int		ft_sort_ascend(int a, int b);
int		ft_sort_descend(int a, int b);
int		ft_get_midpoint_arr(int *nbrs, int sz);
#endif // QUICK_SRT_D_UTILS_H
