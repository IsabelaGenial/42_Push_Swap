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

void DCLL_lst_add_back( t_node *yong, t_main *stack)
{
	if (stack->A->stack == NULL)
	{
		stack->A->stack = yong;
		stack->A->head = stack->A->stack;
	}
	else
	{
		stack->A->tail = DCLL_lst_last(stack->A->stack, stack);
		yong->next = stack->A->head;
		stack->A->tail->next = yong;
		yong->prev = stack->A->tail;
		stack->A->head->prev = yong;
		stack->A->tail = yong;
	}
}

t_node	*DCLL_lst_last(t_node *list, t_main *stack)
{
	if (list->next == NULL)
		return (list);
	while (list->next != stack->A->head && list->next != NULL)
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
