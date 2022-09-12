/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 12:06:35 by cudoh             #+#    #+#             */
/*   Updated: 2022/07/31 12:06:35 by cudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_ops_utils.h"
#include "custom_srt_a_utils.h"

void	ft_ps_stk_pop(t_list **lst)
{
	t_list	*head;
	t_list	*nxt;

	head = *lst;
	nxt = NULL;
	if (head == NULL)
		return ;
	if (head->next != NULL)
		nxt = head->next;
	ft_lstdelone(head, ft_ps_del_node);
	*lst = nxt;
}

int	ft_ps_stk_push(t_list **a, t_attr *sa_attr, t_list **b)
{
	t_list	*next_a;

	next_a = NULL;
	if (*a == NULL)
	{
		return (0);
	}
	next_a = (*a)->next;
	if (*b == NULL)
	{
		*b = *a;
		(*b)->next = NULL;
	}
	else
		ft_lstadd_front(b, *a);
	*a = next_a;
	if (sa_attr->id == 'a')
		ft_printf("pb\n");
	else
		ft_printf("pa\n");
	return (1);
}

int	ft_ps_stk_rotate(t_list **stk, t_attr *s_attr)
{
	t_list	*tail;

	tail = NULL;
	if (*stk == NULL || (*stk)->next == NULL)
	{
		return (0);
	}
	tail = (*stk);
	(*stk) = (*stk)->next;
	tail->next = NULL;
	ft_lstadd_back(stk, tail);
	if (s_attr->id == 'a')
		ft_printf("ra\n");
	else
		ft_printf("rb\n");
	return (1);
}

int	ft_ps_stk_rrotate(t_list **stk, t_attr *s_attr)
{
	t_list	*head;
	t_list	*cur;

	head = NULL;
	cur = NULL;
	if (*stk == NULL || (*stk)->next == NULL)
	{
		return (0);
	}
	cur = *stk;
	head = ft_lstlast(*stk);
	while (cur->next->next != NULL)
		cur = cur->next;
	cur->next = NULL;
	head->next = *stk;
	ft_lstadd_front(stk, head);
	if (s_attr->id == 'a')
		ft_printf("rra\n");
	else
		ft_printf("rrb\n");
	return (1);
}

int	ft_ps_stk_swap(t_list **stk)
{
	t_list	*head;

	head = NULL;
	if (*stk == NULL || (*stk)->next == NULL)
	{
		return (0);
	}
	head = *stk;
	*stk = (*stk)->next;
	head->next = (*stk)->next;
	(*stk)->next = head;
	return (1);
}
