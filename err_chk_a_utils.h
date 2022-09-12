/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_chk_a_utils.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 20:39:00 by cudoh             #+#    #+#             */
/*   Updated: 2022/08/04 20:39:00 by cudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERR_CHK_A_UTILS_H
# define ERR_CHK_A_UTILS_H
# include "push_swap.h"

int		ft_user_input_error_chk(int argcnt, char **args, char ***nbrs_ptr_str);
int		ft_is_str_numeric(char *str);
void	ft_clean_ptr_ptr(char **ptr_str);
size_t	ft_strcnt(char **ptr_str);
int		ft_err_validate_nbr_str(char *str);
#endif