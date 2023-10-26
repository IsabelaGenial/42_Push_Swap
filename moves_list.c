/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igenial <igenial@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 17:05:38 by igenial           #+#    #+#             */
/*   Updated: 2023/10/20 17:05:40 by igenial          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void create_list_if_str(t_stack *stack, char **args)
{
	int i;
	t_node *node;
	int content;

	i = 1;
	while (args[i])
	{
		content = ft_atoi(args[i++]);
		node = DCLL_lstnew(content);
		DCLL_lst_add_back(node, stack);
	}
}

void RRA_DCLL_list(t_stack *stack)
{
	stack -> head = stack -> tail;
	stack -> tail = stack -> tail -> prev;
}

void RA_DCLL_list(t_stack *stack)
{
	stack -> tail = stack -> head;
	stack -> head = stack -> head -> next;
}

void SA_DCLL_list(t_stack *stack)
{
	t_node *temp;
	t_node *temp2;

	temp = stack->head;
	stack->head = stack->head->next;
	temp2 = stack->head->next;
	temp2->prev = temp;
	temp->next = stack->head->next;
	temp->prev = stack->head;
	stack->head->next = temp;
	stack->head->prev = stack->tail;
}
