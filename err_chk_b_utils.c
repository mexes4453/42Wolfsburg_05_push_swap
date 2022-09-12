/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_chk_b_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 20:56:52 by cudoh             #+#    #+#             */
/*   Updated: 2022/08/04 20:56:52 by cudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "err_chk_b_utils.h"

/**
 * @brief 	This function checks that no single str within the ptr to strings
 * 			is duplicated within
 * !		The last pointer within the ptr to ptr must null to indicate
 * !		the end of the ptr to ptr.
 * 
 * @param ptr_str 
 * @return int 
 */
int	ft_err_is_duplicate(char **ptr_str)
{
	size_t	idx_x;
	size_t	idx_y;
	size_t	str_cnt;

	idx_x = 0;
	idx_y = 0;
	str_cnt = ft_strcnt(ptr_str);
	while (idx_x < (str_cnt - 1))
	{
		idx_y = idx_x + 1;
		while (idx_y < str_cnt)
		{
			if (ft_atoi(ptr_str[idx_x]) == ft_atoi(ptr_str[idx_y]))
				return (0);
			idx_y++;
		}
		idx_x++;
	}
	return (1);
}

/**
 * @brief 		This function performs all number check on each string
 * 				with the user input structure.
 * 				It checks that all characters are of int type (is_numeric).
 * 				It validates the str as an int number type (MAXINT) and signs.
 * 
 * @param ptr_str 
 * @return int 
 */
int	ft_err_nbr_str_chk(char **ptr_str)
{
	size_t	idx;
	size_t	str_cnt;

	if (ptr_str == NULL)
		return (0);
	idx = 0;
	str_cnt = ft_strcnt(ptr_str);
	while (idx < str_cnt)
	{
		if (!ft_is_str_numeric(ptr_str[idx]))
			return (0);
		if (!ft_err_validate_nbr_str(ptr_str[idx]))
			return (0);
		idx++;
	}
	return (1);
}

/**
 * @brief 	This function counts the actual number of arguments given by the
 * 			user which could be more or equal the value stored in argcnt because
 * 			input can be provided with or without quotation marks.
 * 			The collapse all inputs into a homogenous input by removing all
 * 			quotation marks. 
 * 			./push_swap 3 "4 9 1" 2 | count = 3
 * 			./push_swap 3 4 9 1 2   | actual_cnt = 5 
 * !		post-requisite function : ft_clean_ptr_ptr
 * !		malloc used within (char **)
 * 
 * @param argcnt
 * @param args 
 * @return char **
 */
char	**ft_err_normalize_input(int argcnt, char **args)
{
	size_t	actual_cnt;
	char	**ptr_str;

	actual_cnt = ft_err_inp_actual_cnt(argcnt, args);
	if (actual_cnt == 0)
		return (0);
	ptr_str = ft_err_collapse_inp(actual_cnt, argcnt, args);
	if (ptr_str == NULL)
		return (0);
	return (ptr_str);
}

/**
 * @brief 		This function counts the actual number of input given
 * 				by the user which not always equal to argcnt.
 * 
 * @param argcnt 
 * @param args 
 * @return size_t 
 */
size_t	ft_err_inp_actual_cnt(int argcnt, char **args)
{
	int		idx;
	size_t	actual_cnt;
	char	**ptr_str;

	idx = 1;
	actual_cnt = 0;
	ptr_str = NULL;
	while (idx < argcnt)
	{
		ptr_str = ft_split(args[idx], ' ');
		if (ptr_str == NULL)
			return (0);
		actual_cnt += ft_strcnt(ptr_str);
		ft_clean_ptr_ptr(ptr_str);
		free(ptr_str);
		ptr_str = NULL;
		idx++;
	}
	return (actual_cnt);
}

/**
 * @brief 		This function recreates the user input by combining all
 * 				input types (with or without double quotes)
 * 				(3 "1 4 5" 2) -> (3 1 4 5 2).
 * 				It strips each input of extra white spaces (ft_strtrim).
 *!				post-requiste function : ft_clean_ptr_ptr. 
 *!				malloc is used within and output must be freed.
 * 
 * @param cnt 
 * @param argcnt 
 * @param args 
 * @return char** 
 */
char	**ft_err_collapse_inp(size_t cnt, int argcnt, char **args)
{
	char	**g_ptr_str;
	int		idx;
	size_t	g_idx;

	g_ptr_str = NULL;
	idx = 1;
	g_idx = 0;
	g_ptr_str = (char **)malloc(sizeof(char *) * (cnt + 1));
	if (g_ptr_str == NULL)
		return (NULL);
	g_ptr_str[cnt] = NULL;
	ft_err_set_null_ptr_ptr((void **)g_ptr_str, cnt);
	while (idx < argcnt)
	{
		ft_err_str_register(&g_idx, &g_ptr_str, args[idx]);
		idx++;
	}
	return (g_ptr_str);
}
