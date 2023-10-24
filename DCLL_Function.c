/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DCLL_Function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igenial <igenial@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 16:29:32 by igenial           #+#    #+#             */
/*   Updated: 2023/10/24 16:29:35 by igenial          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void DCLL_lst_add_back(t_node *old, t_node *yong)
{
	t_node *last;

	if (old == NULL)
		*old = *yong;
	else
	{
		last = DCLL_lst_last(old);
		last -> next = yong;
		last = last->next;
		last->prev = old;
	}
}

t_node	*DCLL_lst_last(t_node *list)
{
	t_node *start;

	if (list->next == NULL)
		return (list);
	start = list;
	while (list->next == start)
		list = list->next;
	return (list);
}

t_node	*DCLL_lstnew(int content)
{
	t_node 	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}
