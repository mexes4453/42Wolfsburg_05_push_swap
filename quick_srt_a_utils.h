/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_srt_a_utils.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 15:08:31 by cudoh             #+#    #+#             */
/*   Updated: 2022/07/31 15:08:31 by cudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUICK_SRT_A_UTILS_H
# define QUICK_SRT_A_UTILS_H
# include "data_type_const.h"
# include "push_swap.h"

int		ft_get_midpoint_stk(t_list **a, t_attr *a_attr);
int		ft_arr_sort(int *nbrs, int arr_sz);
void	ft_arr_print(int *nbrs, int sz);
void	ft_sort_stk(t_list **s, t_attr *sattr);
int		ft_get_chunk_sz_req(int size);
#endif // QUICK_SRT_A_UTILS_H
