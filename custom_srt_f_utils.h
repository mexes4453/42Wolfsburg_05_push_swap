/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom_srt_f_utils.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 13:41:53 by cudoh             #+#    #+#             */
/*   Updated: 2022/07/31 13:41:53 by cudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUSTOM_SRT_F_UTILS_H
# define CUSTOM_SRT_F_UTILS_H
# include "data_type_const.h"
# include "push_swap.h"

void	ft_on_ordered(t_var *v);
int		ft_fetch_seq(int nbr, t_list **ss, t_attr *ss_attr);
int		ft_is_nbr_in_stk(int nbr, t_list **stk, t_attr *s_attr);
int		ft_on_next(t_var *v);
int		ft_on_prev(t_var *v);
#endif // CUSTOM_SRT_F_UTILS_H
