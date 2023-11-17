/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igenial <igenial@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 22:50:42 by igenial           #+#    #+#             */
/*   Updated: 2023/11/17 17:30:50 by igenial          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(char **args)
{
	int		i;

	i = 1;
	while (args[i + 1] != NULL)
	{
		if (ft_atoi(args[i]) > ft_atoi(args[i + 1]))
			return (1);
		i++;
	}
	return (0);
}

int	find_position_max(t_main *stack)
{
	t_node	*major;
	int		pos;
	int		i;

	i = 1;
	pos = 1;
	major = stack->a->head;
	stack->a->stack = stack->a->head;
	while (i <= stack->len)
	{
		if (major->content < stack->a->stack->content)
		{
			major = stack->a->stack;
			pos = i;
		}
		stack->a->stack = stack->a->stack->next;
		i++;
	}
	stack->a->stack = stack->a->head;
	return (pos);
}

int	find_position_min(t_main *stack)
{
	t_node		*major;
	int			pos;
	int			i;

	i = 1;
	pos = 1;
	major = stack->a->head;
	stack->a->stack = stack->a->head;
	while (i <= stack->len)
	{
		if (major->content > stack->a->stack->content)
		{
			major = stack->a->stack;
			pos = i;
		}
		stack->a->stack = stack->a->stack->next;
		i++;
	}
	stack->a->stack = stack->a->head;
	return (pos);
}

int	is_not_digit(char **c)
{
	int	i;
	int	j;

	i = 1;
	while (c[i] != NULL)
	{
		j = 0;
		if (c[i][j] == '\0' && j == 0)
			return (1);
		while (c[i][j] != '\0')
		{
			if (j == 0 && c[i][j] == '-' && c[i][j++] == '\0')
				return (1);
			if (ft_isdigit(c[i][j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	check_duplicated(int argc, char **arg)
{
	int	i;
	int	j;

	i = 0;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (i != j && (ft_atoi(arg[i]) == ft_atoi(arg[j])))
				exit(write(2, "Error\n", 6));
			j++;
		}
		i++;
	}
}
