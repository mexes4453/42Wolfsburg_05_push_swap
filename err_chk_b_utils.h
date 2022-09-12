/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_chk_b_utils.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 20:43:36 by cudoh             #+#    #+#             */
/*   Updated: 2022/08/04 20:43:36 by cudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERR_CHK_B_UTILS_H
# define ERR_CHK_B_UTILS_H
# include "push_swap.h"

int		ft_err_is_duplicate(char **ptr_str);
int		ft_err_nbr_str_chk(char **ptr_str);
char	**ft_err_normalize_input(int argcnt, char **args);
size_t	ft_err_inp_actual_cnt(int argcnt, char **args);
char	**ft_err_collapse_inp(size_t cnt, int argcnt, char **args);
#endif