#include "push_swap.h"

void radix_sort(t_main *stack, int bits)
{
	unsigned int index;
	unsigned int len;
	int bit;

	bit = 0;
	stack->A->stack = stack->A->head;
	len = (stack->len);
	while (bit < bits)
	{
		index = 0;
		while (index < len)
		{
			if ((stack->A->head->position >> bit) % 2 == 1)
				RA_DCLL_list(stack);

			else
				PB_DCLL_list(stack);
			index++;
		}
		push_back(stack);
		bit++;
	}
}

void print_stack(t_main *stack)
{
	int i;

	i = 0;
	t_node *aux;
	aux = stack->A->head;
	stack->B->stack  = stack->B->head;
	while (i < stack->len)
	{
		i++;
		aux = aux->next;
		if(stack->B->stack != NULL)
			stack->B->stack = stack->B->stack->next;
	}
}

void position_numb(t_main *stack)
{
	t_node *aux;

	aux = stack->A->head;
	while (aux->next != stack->A->head)
	{
		stack->A->stack = stack->A->head;
		while(stack->A->stack->next != stack->A->head)
		{
			if(aux->content > stack->A->stack->content)
				aux->position++;
			stack->A->stack = stack->A->stack->next;
			if(stack->A->stack->next == stack->A->head && aux->content > stack->A->stack->content)
				aux->position++;
		}
		aux = aux->next;
		if(aux->next == stack->A->head)
		{
			stack->A->stack = stack->A->head;
			while (stack->A->stack->next != stack->A->head)
			{
				if (aux->content > stack->A->stack->content)
					aux->position++;
				stack->A->stack = stack->A->stack->next;
				if(stack->A->stack->next == stack->A->head && aux->content > stack->A->stack->content)
					aux->position++;
			}
		}
	}
}

void sorted_list(t_main *stack, int argc)
{
	int bits;

	bits = number_bits (argc);
	radix_sort(stack, bits);
}


int	number_bits(int argc)
{
	unsigned int	number_bits;
	int				number;

	number = (argc - 2);
	number_bits = 0;
	while (number > 0)
	{
		number_bits++;
		number = number / 2;
	}
	return (number_bits);
}

void	push_back(t_main *stack)
{
	stack->B->stack = stack->B->head;
	while (stack->B->head != NULL)
	{
		PA_DCLL_list(stack);
	}
}