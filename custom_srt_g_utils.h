/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom_srt_g_utils.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 13:42:53 by cudoh             #+#    #+#             */
/*   Updated: 2022/07/31 13:42:53 by cudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUSTOM_SRT_G_UTILS_H
# define CUSTOM_SRT_G_UTILS_H
# include "data_type_const.h"
# include "push_swap.h"

int		ft_op_x(int c, t_list **a, t_attr *at, int (*f)(t_list **, t_attr *));
int		*ft_conv_stk_arr(t_list **sa, t_attr *sa_attr);
int		ft_find_pos_in_stk(int nbr, t_list **sa, t_attr *sa_attr);
int		ft_custom_sort(t_var *v);
#endif // CUSTOM_SRT_G_UTILS_H
