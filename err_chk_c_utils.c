/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_chk_c_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 21:00:30 by cudoh             #+#    #+#             */
/*   Updated: 2022/08/04 21:00:30 by cudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "err_chk_c_utils.h"

/**
 * @brief 			This function splits each arg in the user input and populate
 * 					each break out into a new argument structure.
 * 
 * @param reg_idx 
 * @param reg 
 * @param strip_str 
 */
void	ft_err_str_register(size_t *reg_idx, char ***reg, char *strip_str)
{
	int		idx;
	int		no_split;
	char	**splitted_str;

	idx = 0;
	splitted_str = ft_split(strip_str, ' ');
	no_split = ft_strcnt(splitted_str);
	while (idx < no_split)
	{
		(*reg)[(*reg_idx)] = ft_strtrim(splitted_str[idx], " ");
		(*reg_idx)++;
		idx++;
	}
	ft_clean_ptr_ptr(splitted_str);
	free(splitted_str);
}

/**
 * @brief 		This function cleanup the memory allocated on heap on Error.
 * 
 * @param ptr_str 
 */
void	ft_err_handler(char **ptr_str)
{
	ft_printf("Error\n");
	ft_clean_ptr_ptr(ptr_str);
	free(ptr_str);
}

/**
 * @brief   This function intialises all pointers with a pointer array to null
 *         
 * @param ptr_ptr 
 * @param ptr_cnt 
 * @return int 
 */
int	ft_err_set_null_ptr_ptr(void **ptr_ptr, int ptr_cnt)
{
	int	idx;

	idx = 0;
	if (ptr_ptr == NULL)
		return (0);
	while (idx < ptr_cnt)
	{
		ptr_ptr[idx] = NULL;
		idx++;
	}
	return (1);
}
