/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 12:39:51 by cudoh             #+#    #+#             */
/*   Updated: 2022/06/16 12:39:51 by cudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_var	ps_var;
	char	**str_arr_inp;

	str_arr_inp = NULL;
	if (ft_user_input_error_chk(argc, argv, &str_arr_inp) == 0)
		return (0);
	ft_ps_var_init(&ps_var);
	ft_create_init_stks(str_arr_inp, &ps_var);
	while (!ft_is_sorted(ps_var.s, &(ps_var.a), &(ps_var.a_attr)))
	{
		if (ps_var.size > QS_MIN_RANGE)
		{
		ps_var.rc = ft_qsort(&ps_var);
			if (ps_var.rc == 0)
				break ;
		}
		else
			ft_custom_sort(&ps_var);
	}
	ft_free_heap(&ps_var);
	free(str_arr_inp);
	return (0);
}
