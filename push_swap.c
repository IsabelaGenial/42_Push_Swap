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

void print_stack(t_main *stack)
{
    int i;

    i = 0;
    t_node *aux;
    aux = stack->A->head;
    while (i < stack->len)
    {
        ft_printf("\n%i°: %i\n", i, aux->content);
        i++;
        aux = aux->next;
    }
}

int     main(int argc, char **arg )
{
	t_main *stack;

	if (argc < 3) {
		return (ft_printf("error\n"));
	}
	stack = ft_calloc(1, sizeof(t_main));
    stack->A = ft_calloc(1, sizeof(t_stack));
    stack->B = ft_calloc(1, sizeof(t_stack));
    stack->len = (argc - 1);
	create_list_if_str(stack, arg);
    if(!is_sorted(stack))
        return(ft_printf("sorted!\n"));
    if ((argc - 1) < 4)
        sorted_three(stack);
    else if (argc - 1 == 4)
        sorted_four(stack);
    if(!is_sorted(stack))
        ft_printf("sorted!\n");
    print_stack(stack);
    return(0);
}
