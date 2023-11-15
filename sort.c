/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igenial <igenial@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 23:22:53 by igenial           #+#    #+#             */
/*   Updated: 2023/11/14 23:22:54 by igenial          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	aux_five(t_main *stack, int pos)
{
	if (pos == 5)
		rra_dcll_list(stack);
	else if (pos == 4)
	{
		rra_dcll_list(stack);
		rra_dcll_list(stack);
	}
	else if (pos == 3)
	{
		rra_dcll_list(stack);
		rra_dcll_list(stack);
		rra_dcll_list(stack);
	}
	else if (pos == 2)
		sa_dcll_list(stack);
}

void	sorted_two(t_main *stack)
{
	t_node	*temp;

	temp = stack->a->head->next;
	if (stack->a->head->content > temp->content)
		sa_dcll_list(stack);
}

void	sorted_three(t_main *stack)
{
	int	pos;

	pos = find_position_max(stack);
	if (pos == 1)
		ra_dcll_list(stack);
	if (pos == 2)
		rra_dcll_list(stack);
	sorted_two(stack);
}

void	sorted_four(t_main *stack)
{
	int	pos;

	pos = find_position_min(stack);
	if (stack->len == 4)
	{
		if (pos == 4)
			rra_dcll_list(stack);
		else if (pos == 3)
		{
			rra_dcll_list(stack);
			rra_dcll_list(stack);
		}
		else if (pos == 2)
			sa_dcll_list(stack);
		pb_dcll_list(stack);
		stack->len -= 1;
		sorted_three(stack);
		pa_dcll_list(stack);
		stack->len += 1;
	}
	sorted_three(stack);
}

void	sorted_five(t_main *stack)
{
	int	pos;

	if (stack->len == 5)
	{
		pos = find_position_min(stack);
		aux_five(stack, pos);
		pb_dcll_list(stack);
		stack->len -= 1;
		sorted_four(stack);
		pa_dcll_list(stack);
	stack->len += 1;
	}
	sorted_four(stack);
}
