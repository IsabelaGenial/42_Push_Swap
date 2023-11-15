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
    stack->A->stack = stack->A->head;
    ft_printf("rra\n");
}

void RA_DCLL_list(t_main *stack)
{
	stack->A->tail = stack->A->head;
	stack->A->head = stack->A->head->next;
    ft_printf("ra\n");
}

void PA_DCLL_list(t_main *stack)
{
    t_node *temp;
    temp = stack->B->head;

	if(stack->B->head == NULL)
	{
		return;
		temp->next = stack->A->head;
		temp->prev = stack->A->tail;
		stack->A->head->prev = temp;
		stack->A->tail->next = temp;
		stack->A->head = temp;
		stack->A->stack = stack->A->head;
		stack->B = NULL;

	}
	stack->B->head = stack->B->head->next;
	temp->next = stack->A->head;
	temp->prev = stack->A->tail;
	stack->A->head->prev = temp;
	stack->A->tail->next = temp;
	stack->A->head = temp;
	stack->A->stack = stack->A->head;

    ft_printf("pa\n");
}

void SA_DCLL_list(t_main *stack)
{
    int a;

    a = stack->A->head->content;
    stack->A->head->content = stack->A->head->next->content;
    stack->A->head->next->content = a;
    ft_printf("sa\n");
}