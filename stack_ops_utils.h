/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops_utils.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 12:01:23 by cudoh             #+#    #+#             */
/*   Updated: 2022/07/31 12:01:23 by cudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_OPS_UTILS_H
# define STACK_OPS_UTILS_H
# include "data_type_const.h"

void	ft_ps_stk_pop(t_list **lst);
int		ft_ps_stk_push(t_list **a, t_attr *sa_attr, t_list **b);
int		ft_ps_stk_rotate(t_list **stk, t_attr *s_attr);
int		ft_ps_stk_rrotate(t_list **stk, t_attr *s_attr);
int		ft_ps_stk_swap(t_list **stk);
#endif
