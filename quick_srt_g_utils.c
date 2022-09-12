/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_srt_g_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 13:16:30 by cudoh             #+#    #+#             */
/*   Updated: 2022/07/31 14:16:57 by cudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "quick_srt_g_utils.h"

/*
	This function check that the value at the top of the stack
	and sorted list are the same.
	if the same, then it returns the previous and next item on
	the sorted list
	3			3 (head matches cur head on stack)
	5			4 (next)
	1			5 (prev)
	---		   ---
	stk		sorted

*/

int	ft_qsort(t_var *v)
{
	int	rc;

	rc = 1;
	rc = ft_qs_create_chk_on_b(v);
	if (rc == 0)
		return (0);
	rc = ft_qs_sort_chk_on_b(v);
	if (rc == 0)
		return (0);
	return (rc);
}
