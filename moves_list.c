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

void create_list_if_str(char *str, t_stack *stack)
{
	char **split_str;

	split_str = ft_split(str,' ');
	stack->stack_a->content = ft_atoi(split_str[0]);
	while (*split_str)
	{
		free(*split_str);
		ft_lstadd_back(&stack->stack_a, ft_lstnew(ft_atoi(*(++split_str))));
	}
}
