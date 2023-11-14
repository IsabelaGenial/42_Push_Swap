#include "push_swap.h"

void free_list(t_stack *stack)
{
    t_node	*for_free;

    while (stack->head != stack->tail)
    {
        for_free = stack->head;
        stack->head = stack->head->next;
        free(for_free);
    }
    stack->head = NULL;
}

void free_main(t_main *stack)
{
    free_list(stack->A);
    free(stack->A->tail);
    free(stack->A);
    free(stack->B);
    free(stack);
}

void calloc_stack(t_main *stack)
{
    stack->A = ft_calloc(1, sizeof(t_stack));
    stack->B = ft_calloc(1, sizeof(t_stack));
}