/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom_srt_b_utils.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 12:11:50 by cudoh             #+#    #+#             */
/*   Updated: 2022/07/31 12:11:50 by cudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUSTOM_SRT_B_UTILS_H
# define CUSTOM_SRT_B_UTILS_H
# include "data_type_const.h"
# include "custom_srt_c_utils.h"

void	ft_attr_init(t_attr *sattr, char stk_id);
int		ft_is_sorted(t_list *s_list, t_list **stk, t_attr *s_attr);
void	ft_update_stk_attr(t_list **stk, t_attr *sattr);
void	ft_fetch_stk_data(t_attr *s_attr);
void	ft_get_seq(t_list **ss, t_attr *ss_attr, t_list **sa, t_attr *sa_attr);
#endif // CUSTOM_SRT_B_UTILS_H