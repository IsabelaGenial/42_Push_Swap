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

void create_list_if_str(t_main *stack, char **args)
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

void RRA_DCLL_list(t_main *stack)
{
	stack->A->head = stack->A->tail;
	stack->A->tail = stack->A->tail->prev;
    ft_printf("rra");
}

void RA_DCLL_list(t_main *stack)
{
	stack->A->tail = stack->A->head;
	stack->A->head = stack->A->head->next;
    ft_printf("ra");
}

void SA_DCLL_list(t_main *stack)
{
	t_node *temp;
	t_node *temp2;

	temp = stack->A->head;
	stack->A->head = stack->A->head->next;
	temp2 = stack->A->head->next;
	temp2->prev = temp;
	temp->next = stack->A->head->next;
	temp->prev = stack->A->head;
	stack->A->head->next = temp;
	stack->A->head->prev = stack->A->tail;
    ft_printf("sa");
}

void PA_DCLL_list(t_main *stack)
{
    t_node *temp;
    temp = stack->B->head;
    if (stack->A->head == NULL)
    {
        stack->B->head = stack->B->head->next;
        stack->B->head->prev = stack->B->tail;
        stack->B->tail->next = stack->B->head;
        stack->A->head = temp;
        stack->A->head->next = stack->A->head;
        stack->A->head->prev = stack->A->head;
    }
    else
    {
        stack->B->head = stack->B->head->next;
        stack->B->head->prev = stack->B->tail;
        stack->B->tail->next = stack->B->head;
        stack->A->tail = stack->A->head->prev;
        temp->next = stack->A->head;
        temp->prev = stack->A->tail;
        stack->A->tail->next = temp;
        stack->A->head->prev = temp;
        stack->A->head = temp;
    }
}