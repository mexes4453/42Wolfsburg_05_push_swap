/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_srt_c_utils.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 15:12:49 by cudoh             #+#    #+#             */
/*   Updated: 2022/07/31 15:12:49 by cudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUICK_SRT_C_UTILS_H
# define QUICK_SRT_C_UTILS_H
# include "data_type_const.h"
# include "push_swap.h"

int		ft_p_st_ab(t_list **a, t_attr *a_attr, t_list **b, t_attr *b_attr);
int		ft_upd_chunk_data(t_attr *s_attr);
int		*ft_retrieve_chunk(t_list **s, t_attr *s_attr);
void	ft_check_chunks(t_list **s, t_attr *s_attr);
int		ft_chunk_alloc(t_attr *s_attr);
#endif // QUICK_SRT_C_UTILS_H
