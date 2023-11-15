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
		stack->A->head = yong;
		stack->A->tail = stack->A->head;
		stack->A->head->next = stack->A->tail;
		stack->A->head->prev = stack->A->tail;
		stack->A->tail->next = stack->A->head;
		stack->A->tail->prev = stack->A->head;
		stack->A->stack = stack->A->head;
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
	while (list->next != stack->A->head)
	{
		list = list->next;
	}
	return (list);
}

t_node	*DCLL_lstnew(int content)
{
	t_node 	*node;

	node = ft_calloc(1, sizeof(t_node));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

int	DCLL_lst_size(t_node *lst, t_node *head)
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