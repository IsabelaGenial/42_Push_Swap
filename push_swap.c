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

	if (argc < 3 || !is_not_digit(arg))
    {
        write(2, "Error\n", 6);
        return (1);
	}
    stack = ft_calloc(1, sizeof(t_main));
    calloc_stack(stack);
    stack->len = (argc - 1);
	create_list_if_str(stack, arg);
    print_stack(stack);
    if(is_sorted(stack) || is_duplicates(stack))
    {
        free_main(stack);
        write(2, "Error\n", 6);
        return(1);
    }
    print_stack(stack);
    free_main(stack);
    return(0);
}
