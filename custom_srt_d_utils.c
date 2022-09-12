/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom_srt_d_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 13:23:41 by cudoh             #+#    #+#             */
/*   Updated: 2022/07/31 13:23:41 by cudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "custom_srt_d_utils.h"

/**
 * @brief 		This function fetches the corresponding sequence of nbrs
 * 				from the sorted stack according to the nbr at the top of stack
 * 				A. 	
 * 				It updates the sequence variable (cur) to match nbr on stack A
 * 				top and search within the sorted stack to find its next & prev
 * 				nbrs in the sequence. Sorted stack attr variables are updated
 * 				accordingly.
 * 
 * 
 * @param ss 
 * @param ss_attr 
 * @param sa 
 * @param sa_attr 
 */
/*
	This function update the stack state (attr)
*/

void	*ft_conv_to_int(void *ptr)
{
	int	*int_ptr;

	int_ptr = (int *)malloc(sizeof(int));
	if (int_ptr != NULL)
	{
		*int_ptr = ft_atoi((char *)ptr);
		free(ptr);
	}
	return ((void *)int_ptr);
}

// This function prints the value contents of both stacks
void	ft_print_abstk(t_list **a, t_attr *a_attr, t_list **b, t_attr *b_attr)
{
	ft_update_stk_attr(a, a_attr);
	ft_update_stk_attr(b, b_attr);
	while (a_attr->cur != NULL || b_attr->cur != NULL)
	{
		if (a_attr->cur == NULL)
			ft_printf("\nx ");
		else
		{
			ft_printf("\n%d ", *(int *)a_attr->cur->content);
			a_attr->cur = a_attr->cur->next;
		}
		if (b_attr->cur == NULL)
			ft_printf("x");
		else
		{
			ft_printf("%d", *(int *)b_attr->cur->content);
			b_attr->cur = b_attr->cur->next;
		}
	}
	ft_printf("\n- -\na b\n");
	ft_update_stk_attr(a, a_attr);
	ft_update_stk_attr(b, b_attr);
}

// compute stk rotate direction within
int	ft_compute_stk_rotate_dir(t_attr *stk_attr)
{
	int	dist_r;

	dist_r = stk_attr->stk_size - stk_attr->idx;
	if (stk_attr->idx <= dist_r)
		return (0);
	else
		return (1);
	return (1);
}

// move/rotate node to top of stack if not in idx 0 of stack
void	ft_move_nbr_to_stk_top(t_list **sa, t_attr *stk_attr)
{
	int	dir;

	if (stk_attr->idx == 0)
		return ;
	dir = ft_compute_stk_rotate_dir(stk_attr);
	while (stk_attr->nbr_cur != stk_attr->nbr)
	{
		if (dir)
			ft_ps_stk_rrotate(sa, stk_attr);
		else
			ft_ps_stk_rotate(sa, stk_attr);
		stk_attr->nbr_cur = *(int *)(*sa)->content;
	}
}

void	ft_check_sa(t_list **sa, t_attr *sa_attr, t_list **ss, t_attr *ss_attr)
{
	ft_update_stk_attr(sa, sa_attr);
	ft_fetch_stk_data(sa_attr);
	ft_update_stk_attr(ss, ss_attr);
	ft_get_seq(ss, ss_attr, sa, sa_attr);
	sa_attr->rc = 0;
	if (sa_attr->nbr_prev == ss_attr->nbr_prev)
		sa_attr->rc |= (1 << 0);
	else
		sa_attr->rc &= ~(1 << 0);
	if (sa_attr->nbr_prev == ss_attr->nbr_nxt)
		sa_attr->rc |= (1 << 1);
	else
		sa_attr->rc &= ~(1 << 1);
	if (sa_attr->nbr_nxt == ss_attr->nbr_prev)
		sa_attr->rc |= (1 << 2);
	else
	{
		sa_attr->rc &= ~(1 << 2);
	}
	if (sa_attr->nbr_nxt == ss_attr->nbr_nxt)
		sa_attr->rc |= (1 << 3);
	else
		sa_attr->rc &= ~(1 << 3);
}
