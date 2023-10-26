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

	int len = argc;

	if (argc < 6) {
		return (ft_printf("error\n"));
	}
	stack = ft_calloc(1, sizeof(t_stack));
	create_list_if_str(stack, arg);
	t_node *start_tail = stack->tail;
	t_node *start_head = stack->head;
	while (len-- >= 2)
	{
		ft_printf("%i | %i\n", start_head->content,  start_tail->content);
		start_tail = start_tail->prev;
		start_head = start_head->next;
	}
	SA_DCLL_list(stack);
	start_tail = stack->tail;
	start_head = stack->head;
	len = argc;
	while (len-- >= 2)
	{
		ft_printf("*%i | %i\n", start_head->content,  start_tail->content);
		start_tail = start_tail->prev;
		start_head = start_head->next;
	}

	return(0);
}
