/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom_srt_c_utils.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 12:45:53 by cudoh             #+#    #+#             */
/*   Updated: 2022/07/31 12:45:53 by cudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUSTOM_SRT_C_UTILS_H
# define CUSTOM_SRT_C_UTILS_H
# include "data_type_const.h"
# include "custom_srt_b_utils.h"

void	ft_upd_get_seq(t_list **a, t_attr *a_attr, t_list **s, t_attr *s_attr);
int		ft_is_stk_full(t_list **stk, t_attr *s_attr, t_attr *ss_attr);
int		ft_is_headcur(t_attr *ss_attr, t_attr *sa_attr);
int		ft_is_nbr_n_stkhead(int nbr, t_attr *s_attr);
void	ft_print_stkdata(t_attr *sattr);
#endif // CUSTOM_SRT_C_UTILS_H
