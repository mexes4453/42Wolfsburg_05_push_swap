/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom_srt_a_utils.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 11:17:28 by cudoh             #+#    #+#             */
/*   Updated: 2022/07/31 11:17:28 by cudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUSTOM_SRT_A_UTILS_H
# define CUSTOM_SRT_A_UTILS_H
# include "data_type_const.h"
# include "push_swap.h"

void	ft_ps_var_init(t_var *v);
void	ft_create_init_stks(char **str_arr_inp, t_var *v);
void	ft_sort(t_list *sort_list);
void	ft_ps_del_node(void *adr);
void	ft_ps_printlst(t_list *list);
#endif // CUSTOM_SRT_A_UTILS_H
