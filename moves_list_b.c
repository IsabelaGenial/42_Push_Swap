/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_list_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igenial <igenial@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 23:02:27 by igenial           #+#    #+#             */
/*   Updated: 2023/11/14 23:02:28 by igenial          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb_dcll_list(t_main *stack)
{
	t_node	*temp;

	temp = stack->a->head;
	if (stack->b->head == NULL)
	{
		stack->a->head = stack->a->head->next;
		stack->a->tail->next = stack->a->head;
		stack->a->head->prev = stack->a->tail;
		stack->b->head = temp;
		stack->b->head->next = stack->b->tail;
		ft_printf("pb\n");
	}
	else
	{
		stack->a->head = stack->a->head->next;
		stack->a->head->prev = stack->a->tail;
		stack->a->tail->next = stack->a->head;
		temp->next = stack->b->head;
		stack->b->head->prev = temp;
		stack->b->head = temp;
		stack->b->stack = stack->b->head;
		ft_printf("pb\n");
	}
}

void	rrb_dcll_list(t_main *stack)
{
	stack->b->head = stack->b->tail;
	stack->b->tail = stack->b->tail->prev;
	stack->b->stack = stack->b->head;
	ft_printf("rrb\n");
}

void	rb_dcll_list(t_main *stack)
{
	stack->b->tail = stack->b->head;
	stack->b->head = stack->b->head->next;
	stack->b->stack = stack->b->head;
	ft_printf("rb\n");
}

void	sb_dcll_list(t_main *stack)
{
	int	a;

	a = stack->b->head->content;
	stack->b->head->content = stack->b->head->next->content;
	stack->b->head->next->content = a;
	ft_printf("sb\n");
}

void	check_overflow(int argc, char **arg)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (ft_atol(arg[i]) > INT_MAX || ft_atol(arg[i]) < INT_MIN)
			exit(write(2, "Error\n", 6));
		i++;
	}
}
