/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_srt_e_utils.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 15:14:26 by cudoh             #+#    #+#             */
/*   Updated: 2022/07/31 15:14:26 by cudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUICK_SRT_E_UTILS_H
# define QUICK_SRT_E_UTILS_H
# include "data_type_const.h"
# include "push_swap.h"

int		ft_get_midpt_chunk(t_list **s, t_attr *s_attr);
int		ft_p_st_ch(t_list **b, t_attr *b_attr, t_list **a, int (*f)(int, int));
void	ft_p_st_ch1(t_list **b, t_attr *b_attr, t_list **a, int (*f)(int, int));
void	ft_ch_n_sta(t_list **a, t_attr *a_attr, t_list **ss, t_attr *ss_attr);
void	ft_ch_n_sta1(t_attr *a_attr, t_attr *s_attr, int *a, int *s);
#endif // QUICK_SRT_E_UTILS_H
