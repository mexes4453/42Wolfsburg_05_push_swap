/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_srt_b_utils.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 15:11:56 by cudoh             #+#    #+#             */
/*   Updated: 2022/07/31 15:11:56 by cudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUICK_SRT_B_UTILS_H
# define QUICK_SRT_B_UTILS_H
# include "data_type_const.h"
# include "push_swap.h"

void	ft_log_stk_op(t_list **s, t_attr *sattr);
void	ft_exe_stk_op(t_list **a, t_attr *a_attr, t_list **b, t_attr *b_attr);
void	ft_free_stk(t_list **ss, t_list **sa, t_list **sb);
void	ft_free_attr(t_attr *s_attr);
void	ft_free_heap(t_var *v);
#endif // QUICK_SRT_B_UTILS_H
