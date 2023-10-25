/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igenial <igenial@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 17:50:05 by igenial           #+#    #+#             */
/*   Updated: 2023/10/19 17:51:38 by igenial          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **arg )
{
	t_stack *stack;

	if (argc < 6) {
		return (ft_printf("error\n"));
	}
	stack = ft_calloc(1, sizeof(t_stack));
	create_list_if_str(stack, arg);
	while (argc-- >= 2)
	{
		ft_printf("%i\n", stack->stack_a->content);
		stack->stack_a = stack->stack_a->next;
	}
	return(0);
}
