/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom_srt_e_utils.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 13:40:39 by cudoh             #+#    #+#             */
/*   Updated: 2022/07/31 13:40:39 by cudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUSTOM_SRT_E_UTILS_H
# define CUSTOM_SRT_E_UTILS_H
# include "data_type_const.h"

void	ft_sa_action(t_var *v);
void	ft_on_match_6(t_var *v);
void	ft_on_match_2(t_var *v);
int		ft_match_sa_nbr(t_attr *sa_attr, t_attr *ss_attr);
int		ft_is_ordered(t_list **a, t_attr *a_attr, t_list **s, t_attr *s_attr);
#endif // CUSTOM_SRT_E_UTILS_H
