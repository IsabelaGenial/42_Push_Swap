/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igenial <igenial@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 17:05:38 by igenial           #+#    #+#             */
/*   Updated: 2023/10/20 17:05:40 by igenial          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void create_list_if_str(t_stack *stack, char **args)
{
	int i;
	t_node node;
	int content;

	i = 1;
	while (args[i])
	{
		content = ft_atoi(args[i++]);
		node = *DCLL_lstnew(content);
		DCLL_lst_add_back(stack->stack_a, &node);
	}
}
