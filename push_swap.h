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

# include 	"./libfstonk/libft.h"
# include 	<unistd.h>

# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef struct s_node
{
	int				content;
	struct s_node	*next;
	struct s_node	*prev;
	int				position;
}					t_node;

typedef struct s_stack
{
    t_node  *stack;
    t_node  *head;
    t_node  *tail;
}           t_stack;

typedef struct s_main
{
	t_stack     *A;
    t_stack     *B;
	int         len;
}			t_main;

void	create_list_if_str(t_main *stack, char **args);
t_node	*DCLL_lst_last(t_node *list, t_main *stack);
t_node	*DCLL_lstnew(int content);
void	DCLL_lst_add_back( t_node *yong, t_main *stack);
void	RRA_DCLL_list(t_main *stack);
void	RA_DCLL_list(t_main *stack);
void	SA_DCLL_list(t_main *stack);
void    PA_DCLL_list(t_main *stack);
void    PB_DCLL_list(t_main *stack);
void    RRB_DCLL_list(t_main *stack);
void    RB_DCLL_list(t_main *stack);
void    SB_DCLL_list(t_main *stack);
int     is_sorted(t_main *stack);
void    sorted_two(t_main *stack);
int     find_position_min(t_main *stack);
int     find_position_max(t_main *stack);
void    sorted_three(t_main *stack);
void    sorted_five(t_main *stack);
void    sorted_four(t_main *stack);
void    free_main(t_main *stack);
void    calloc_stack(t_main *stack);
int     is_not_digit(char **c);
int     is_duplicates(t_main *stack);
void	check_duplicated(int argc, char *argv[]);
void	check_overflow(int argc, char **arg);
int		DCLL_lst_size(t_node *lst, t_node *head);
void 	print_stack(t_main *stack);
void	position_numb(t_main *stack);
int		number_bits(int argc);
void	sorted_list(t_main *stack, int argc);
void	push_back(t_main *stack);
#endif