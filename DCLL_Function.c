/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DCLL_Function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igenial <igenial@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 16:29:32 by igenial           #+#    #+#             */
/*   Updated: 2023/10/24 16:29:35 by igenial          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	dcll_lst_add_back( t_node *yong, t_main *stack)
{
	if (stack->a->stack == NULL)
	{
		stack->a->head = yong;
		stack->a->tail = stack->a->head;
		stack->a->head->next = stack->a->tail;
		stack->a->head->prev = stack->a->tail;
		stack->a->tail->next = stack->a->head;
		stack->a->tail->prev = stack->a->head;
		stack->a->stack = stack->a->head;
	}
	else
	{
		stack->a->tail = dcll_lst_last(stack->a->stack, stack);
		yong->next = stack->a->head;
		stack->a->tail->next = yong;
		yong->prev = stack->a->tail;
		stack->a->head->prev = yong;
		stack->a->tail = yong;
	}
}

t_node	*dcll_lst_last(t_node *list, t_main *stack)
{
	while (list->next != stack->a->head)
	{
		list = list->next;
	}
	return (list);
}

t_node	*dcll_lstnew(int content)
{
	t_node	*node;

	node = ft_calloc(1, sizeof(t_node));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

int	dcll_lst_size(t_node *lst, t_node *head)
{
	int	i;

	i = 0;
	while (lst->next != head)
	{
	lst = lst->next;
	i++;
	}
	return (i);
}

int	number_bits(int argc)
{
	unsigned int	number_bits;
	int				number;

	number = (argc - 2);
	number_bits = 0;
	while (number > 0)
	{
		number_bits++;
		number = number / 2;
	}
	return ((int)number_bits);
}
