/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Radix_Sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igenial <igenial@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 23:05:22 by igenial           #+#    #+#             */
/*   Updated: 2023/11/14 23:26:47 by igenial          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	radix_sort(t_main *stack, int bits)
{
	unsigned int	index;
	unsigned int	len;
	int				bit;

	bit = 0;
	stack->a->stack = stack->a->head;
	len = (stack->len);
	while (bit < bits)
	{
		index = 0;
		while (index < len)
		{
			if ((stack->a->head->position >> bit) % 2 == 1)
				ra_dcll_list(stack);
			else
				pb_dcll_list(stack);
			index++;
		}
		push_back(stack);
		bit++;
	}
}

void	print_stack(t_main *stack)
{
	int		i;
	t_node	*aux;

	i = 0;
	aux = stack->a->head;
	stack->b->stack = stack->b->head;
	while (i < stack->len)
	{
		i++;
		aux = aux->next;
		if (stack->b->stack != NULL)
			stack->b->stack = stack->b->stack->next;
	}
}

void	position_numb(t_main *stack)
{
	t_node	*aux;

	aux = stack->a->head;
	while (aux->next != stack->a->head)
	{
		stack->a->stack = stack->a->head;
		while (stack->a->stack->next != stack->a->head)
		{
			if (aux->content > stack->a->stack->content)
				aux->position++;
			stack->a->stack = stack->a->stack->next;
			if (stack->a->stack->next == stack->a->head
				&& aux->content > stack->a->stack->content)
				aux->position++;
		}
		aux = aux->next;
		position_aux(stack, aux);
	}
}

void	push_back(t_main *stack)
{
	stack->b->stack = stack->b->head;
	while (stack->b->head != NULL)
	{
		pa_dcll_list(stack);
	}
}

void	position_aux(t_main *stack, t_node *aux)
{
	if (aux->next == stack->a->head)
	{
		stack->a->stack = stack->a->head;
		while (stack->a->stack->next != stack->a->head)
		{
			if (aux->content > stack->a->stack->content)
				aux->position++;
			stack->a->stack = stack->a->stack->next;
			if (stack->a->stack->next == stack->a->head
				&& aux->content > stack->a->stack->content)
				aux->position++;
		}
	}
}
