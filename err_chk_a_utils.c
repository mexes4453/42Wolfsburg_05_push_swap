/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_chk_a_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 20:53:17 by cudoh             #+#    #+#             */
/*   Updated: 2022/08/04 20:53:17 by cudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "err_chk_a_utils.h"

int	ft_user_input_error_chk(int argcnt, char **args, char ***nbrs_ptr_str)
{
	if (argcnt == 1)
		return (0);
	if (argcnt >= 2)
	{
		*nbrs_ptr_str = ft_err_normalize_input(argcnt, args);
		if (!ft_err_nbr_str_chk(*nbrs_ptr_str))
		{
			ft_err_handler(*nbrs_ptr_str);
			return (0);
		}
		if (!ft_err_is_duplicate(*nbrs_ptr_str))
		{
			ft_err_handler(*nbrs_ptr_str);
			return (0);
		}
	}
	return (1);
}

/**
 * @brief 		This function checks that every character in a string
 * 				is numeric ('0' ... '9')
 * 
 * @param str 
 * @return int 
 */
int	ft_is_str_numeric(char *str)
{
	int	idx;

	idx = 0;
	while (str[idx] != '\0')
	{
		if (str[idx] < '0' || str[idx] > '9')
		{
			if (str[idx] != '-')
				return (0);
		}
		idx++;
	}
	return (1);
}

/**
 * @brief 	This function deallocates all char type pointers allocated
 * 			within a pointer.
 * 			All deallocated pointers are re-assigned to null.
 * !		The last pointer within the ptr to ptr must be null to indicate
 * !		the end of the ptr to ptr.
 * @param ptr_ptr 
 */
void	ft_clean_ptr_ptr(char **ptr_str)
{
	int	idx;

	idx = 0;
	if (ptr_str == NULL)
		return ;
	while (ptr_str[idx] != NULL)
	{
		free(ptr_str[idx]);
		ptr_str[idx] = NULL;
		idx++;
	}
}

/**
 * @brief 	This function counts the number of pointers (str) stored  within
 * 			a pointer (ptr to ptr).
 * !		The last pointer within the ptr to ptr must null to indicate
 * !		the end of the ptr to ptr.
 * 
 * @param ptr_str 
 * @return int 
 */
size_t	ft_strcnt(char **ptr_str)
{
	size_t	idx;

	idx = 0;
	if (ptr_str == NULL)
		return (0);
	while (ptr_str[idx] != NULL)
		idx++;
	return (idx);
}

/**
 * @brief 		This function checks that each input nbr is within MAXINT
 * 				using the ft_atoi and ft_itoa.
 * 				It also use both function for validate any negative nbr 
 * 				with more than one hyphen (-3: ok,  --3: not ok)
 * 
 * @param str 
 * @return int 
 */
int	ft_err_validate_nbr_str(char *str)
{
	int		nbr;
	char	*ascii;

	nbr = 0;
	ascii = NULL;
	if (str == NULL)
		return (0);
	nbr = ft_atoi(str);
	ascii = ft_itoa(nbr);
	if (ft_strlen(str) != ft_strlen(ascii))
	{
		free(ascii);
		return (0);
	}
	free(ascii);
	return (1);
}
