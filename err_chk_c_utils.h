/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_chk_c_utils.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 20:45:13 by cudoh             #+#    #+#             */
/*   Updated: 2022/08/04 20:45:13 by cudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERR_CHK_C_UTILS_H
# define ERR_CHK_B_UTILS_H
# include "push_swap.h"

void	ft_err_str_register(size_t *reg_idx, char ***reg, char *strip_str);
void	ft_err_handler(char **ptr_str);
int		ft_err_set_null_ptr_ptr(void **ptr_ptr, int ptr_cnt);
#endif