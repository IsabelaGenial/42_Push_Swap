/* ************************************************************************** */
/*....                                                                        */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igenial <igenial@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 22:51:56 by igenial           #+#    #+#             */
/*   Updated: 2023/11/14 22:52:38 by igenial          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_list(t_stack *stack)
{
	t_node	*for_free;

	while (stack->head != stack->tail)
	{
		for_free = stack->head;
		stack->head = stack->head->next;
		free(for_free);
	}
	stack->head = NULL;
}

void	free_main(t_main *stack)
{
	free_list(stack->a);
	free(stack->a->tail);
	free(stack->a);
	free(stack->b);
	free(stack);
}

void	calloc_stack(t_main *stack)
{
	stack->a = ft_calloc(1, sizeof(t_stack));
	stack->b = ft_calloc(1, sizeof(t_stack));
}

void	sorted_list(t_main *stack, int argc)
{
	int	bits;

	bits = number_bits (argc);
	radix_sort(stack, bits);
}
