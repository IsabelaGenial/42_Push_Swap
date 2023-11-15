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

	if (argc < 3 || is_not_digit(arg))
    {
		write(2, "Error\n", 6);
		return (1);
	}
	check_overflow(argc,arg);
	check_duplicated(argc,arg);
	stack = ft_calloc(1, sizeof(t_main));
	calloc_stack(stack);
	stack->len = (argc - 1);
	create_list_if_str(stack, arg);
	position_numb(stack);
	print_stack(stack);
	if(stack->len < 6)
		sorted_five(stack);
	else
		sorted_list(stack, argc);
    print_stack(stack);
    free_main(stack);
    return(0);
}
