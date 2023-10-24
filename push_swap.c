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
	t_stack stack;
	
	if (argc < 6) {
		return (ft_printf("error\n"));
	}
	create_list_if_str(&stack, arg);
	return(0);
}
