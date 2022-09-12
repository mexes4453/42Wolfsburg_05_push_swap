/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom_srt_d_utils.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 13:22:20 by cudoh             #+#    #+#             */
/*   Updated: 2022/07/31 13:22:20 by cudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUSTOM_SRT_D_UTILS_H
# define CUSTOM_SRT_D_UTILS_H
# include "data_type_const.h"
# include "push_swap.h"

void	*ft_conv_to_int(void *ptr);
void	ft_print_abstk(t_list **a, t_attr *a_attr, t_list **b, t_attr *b_attr);
int		ft_compute_stk_rotate_dir(t_attr *stk_attr);
void	ft_move_nbr_to_stk_top(t_list **sa, t_attr *stk_attr);
void	ft_check_sa(t_list **sa, t_attr *sa_attr, t_list **ss, t_attr *ss_attr);
#endif // CUSTOM_SRT_D_UTILS_H
