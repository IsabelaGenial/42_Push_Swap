/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igenial <igenial@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 17:06:17 by igenial           #+#    #+#             */
/*   Updated: 2023/10/20 17:06:19 by igenial          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libfstonk/libft.h"

typedef struct s_stack
{
	t_list *stack_a;
	t_list *stack_b;
}			t_stack;

void create_list_if_str(char *str, t_stack *stack);

#endif