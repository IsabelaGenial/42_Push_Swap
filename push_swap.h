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

typedef struct s_node
{
	int				content;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

typedef struct s_stack
{
	t_node *stack_a;
	t_node *stack_b;
	t_node *head;
	t_node *tail;
	int len;
}			t_stack;



void	create_list_if_str(t_stack *stack, char **args);
t_node	*DCLL_lst_last(t_node *list, t_stack *stack);
t_node	*DCLL_lstnew(int content);
void DCLL_lst_add_back( t_node *yong, t_stack *stack);
#endif