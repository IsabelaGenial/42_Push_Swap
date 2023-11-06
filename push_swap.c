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

int     main(int argc, char **arg )
{
	t_main *stack;

	int len = argc;

	if (argc < 6) {
		return (ft_printf("error\n"));
	}
	stack = ft_calloc(1, sizeof(t_main));
    stack->A = ft_calloc(1, sizeof(t_stack));
    stack->B = ft_calloc(1, sizeof(t_stack));
	create_list_if_str(stack, arg);
	t_node *start_tail = stack->A->tail;
	t_node *start_head = stack->A->head;
	while (len-- >= 2)
	{
		ft_printf("%i | %i\n", start_head->content,  start_tail->content);
		start_tail = start_tail->prev;
		start_head = start_head->next;
	}
	PB_DCLL_list(stack);
    PB_DCLL_list(stack);
    PB_DCLL_list(stack);
    PB_DCLL_list(stack);
	start_tail = stack->A->tail;
	start_head = stack->A->head;
    t_node *start_b = stack->B->head;
	len = argc/2;
	while (len-- >= 1)
	{
		ft_printf("*%i | %i\n", start_head->content,  start_b->content);
        start_b = start_b->next;
        start_head = start_head->next;
    }
	return(0);
}
