/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom_srt_a_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 11:16:49 by cudoh             #+#    #+#             */
/*   Updated: 2022/07/31 11:16:49 by cudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "custom_srt_a_utils.h"

/**
 * @brief  	This function initalise all variables required
 * 			for the push swap program
 * 
 * @param v 
 */
void	ft_ps_var_init(t_var *v)
{
	v->s = NULL;
	v->a = NULL;
	v->b = NULL;
	v->f_srt_a = ft_sort_ascend;
	v->f_srt_d = ft_sort_descend;
	v->flag |= FLAG_QS_CHUNK_CREATE;
	v->rc = 0;
	v->iter_cnt = 0;
	v->iter_limit = 70;
	ft_attr_init(&(v->a_attr), 'a');
	ft_attr_init(&(v->b_attr), 'b');
	ft_attr_init(&(v->s_attr), 's');
	v->a_attr.chunk_lens = NULL;
	v->b_attr.chunk_lens = NULL;
	v->s_attr.chunk_lens = NULL;
	v->size = 0;
}

/**
 * @brief		This function creates and initial all stack lists
 * 				given the argument count and argument strings pointers
 * 
 * @param argc 
 * @param v 
 */
void	ft_create_init_stks(char **str_arr_inp, t_var *v)
{
	int	idx;

	idx = 0;
	(v->a_attr.stk_size) = ft_strcnt(str_arr_inp);
	idx = ft_strcnt(str_arr_inp);
	while (--idx >= 0)
	{
		v->a_attr.ptr = (void *)(str_arr_inp[idx]);
		v->s_attr.ptr = (void *)(ft_strdup(str_arr_inp[idx]));
		v->a_attr.ptr = ft_conv_to_int(v->a_attr.ptr);
		v->s_attr.ptr = ft_conv_to_int(v->s_attr.ptr);
		ft_lstadd_front(&(v->s), ft_lstnew(v->s_attr.ptr));
		ft_lstadd_front(&(v->a), ft_lstnew(v->a_attr.ptr));
	}
	ft_attr_init(&(v->b_attr), v->b_attr.id);
	ft_sort(v->s);
	ft_update_stk_attr(&(v->s), &(v->s_attr));
	ft_update_stk_attr(&(v->a), &(v->a_attr));
	ft_fetch_stk_data(&(v->a_attr));
	v->size = ft_lstsize(v->a);
}

// Sort array of number using bubble sort
void	ft_sort(t_list *sort_list)
{
	t_list	*head;
	t_list	*tail;
	void	*data;

	if (sort_list == NULL)
		return ;
	head = sort_list;
	while (head->next != NULL)
	{
		tail = head->next;
		while (tail != NULL)
		{
			if (*((int *)head->content) > *((int *)tail->content))
			{
				data = tail->content;
				tail->content = head->content;
				head->content = data;
			}
			tail = tail->next;
		}
		head = head->next;
	}
}

void	ft_ps_del_node(void *adr)
{
	free(adr);
	adr = NULL;
}

void	ft_ps_printlst(t_list *list)
{
	t_list	*head;

	head = list;
	if (head == NULL)
	{
		ft_printf("\nNULL - Empty list\n");
		return ;
	}
	while (head != NULL)
	{
		ft_printf("\n%d", *((int *)(head->content)));
		head = head->next;
	}
	ft_printf("\n");
}
