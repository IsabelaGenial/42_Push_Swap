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

t_list create_list_if_str(char *str)
{
	char **split_str;
	t_list *stack_a;

	split_str = ft_split(str,' ');
	stack_a = ft_lstnew(ft_atoi(split_str[0]))
	while (*split_str)
	{
		free(*split_str);
		//TODO: criar função que recebe *f() e cria um nó novo aplicando a função desejada no content.
		//ft_lst_apply(&stack_a, ft_atoi, *(++split_str));
		//ft_lstadd_back(&stack_a, ft_lstnew(ft_atoi(*(++split_str))));
	}
	return (stack_a);
}
