/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_srt_f_utils.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 15:15:32 by cudoh             #+#    #+#             */
/*   Updated: 2022/07/31 15:15:32 by cudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUICK_SRT_F_UTILS_H
# define QUICK_SRT_F_UTILS_H
# include "data_type_const.h"
# include "push_swap.h"

int		ft_qs_create_chk_on_b(t_var *v);
void	ft_qs_push_on_sort_ba(t_var *v);
int		ft_qs_empty_chk_a(t_var *v);
int		ft_qs_recurse_push_abba(t_var *v);
int		ft_qs_sort_chk_on_b(t_var *v);
#endif // QUICK_SRT_F_UTILS_H
