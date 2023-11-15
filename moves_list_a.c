/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_list_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igenial <igenial@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 17:05:38 by igenial           #+#    #+#             */
/*   Updated: 2023/10/20 17:05:40 by igenial          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	create_list_if_str(t_main *stack, char **args)
{
	int		i;
	t_node	*node;
	int		content;

	i = 1;
	while (args[i])
	{
		content = ft_atoi(args[i++]);
		node = dcll_lstnew(content);
		dcll_lst_add_back(node, stack);
	}
}

void	rra_dcll_list(t_main *stack)
{
	stack->a->head = stack->a->tail;
	stack->a->tail = stack->a->tail->prev;
	stack->a->stack = stack->a->head;
	ft_printf("rra\n");
}

void	ra_dcll_list(t_main *stack)
{
	stack->a->tail = stack->a->head;
	stack->a->head = stack->a->head->next;
	ft_printf("ra\n");
}

void	pa_dcll_list(t_main *stack)
{
	t_node	*temp;

	temp = stack->b->head;
	if (stack->b->head == NULL)
	{
		return ;
		temp->next = stack->a->head;
		temp->prev = stack->a->tail;
		stack->a->head->prev = temp;
		stack->a->tail->next = temp;
		stack->a->head = temp;
		stack->a->stack = stack->a->head;
		stack->b = NULL;
	}
	stack->b->head = stack->b->head->next;
	temp->next = stack->a->head;
	temp->prev = stack->a->tail;
	stack->a->head->prev = temp;
	stack->a->tail->next = temp;
	stack->a->head = temp;
	stack->a->stack = stack->a->head;
	ft_printf("pa\n");
}

void	sa_dcll_list(t_main *stack)
{
	int	a;

	a = stack->a->head->content;
	stack->a->head->content = stack->a->head->next->content;
	stack->a->head->next->content = a;
	ft_printf("sa\n");
}
