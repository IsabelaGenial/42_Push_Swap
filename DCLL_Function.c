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

void DCLL_lst_add_back( t_node *yong, t_stack *stack)
{
	if (stack->stack_a == NULL)
	{
		stack->stack_a = yong;
		stack->head = stack->stack_a;
	}
	else
	{
		stack->tail = DCLL_lst_last(stack->stack_a, stack);
		yong->next = stack->head;
		stack->tail->next = yong;
		yong->prev = stack->tail;
		stack->head->prev = yong;
	}
}

t_node	*DCLL_lst_last(t_node *list, t_stack *stack)
{
	if (list->next == NULL)
		return (list);
	while (list->next != stack->head && list->next != NULL)
	{
		list = list->next;
	}
	return (list);
}

t_node	*DCLL_lstnew(int content)
{
	t_node 	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}
