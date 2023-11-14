#include "push_swap.h"

void PB_DCLL_list(t_main *stack)
{
    t_node *temp;
    temp = stack->A->head;
    if (stack->B->head == NULL)
    {
        stack->A->head = stack->A->head->next;
        stack->A->head->prev = stack->A->tail;
        stack->A->tail->next = stack->A->head;
        stack->B->head = temp;
        ft_printf("pb\n");
    }
    else
    {
        stack->A->head = stack->A->head->next;
        stack->A->head->prev = stack->A->tail;
        stack->A->tail->next = stack->A->head;
        temp->next = stack->B->head;
        temp->prev = stack->B->head->prev;
        stack->B->head = temp;
        stack->B->stack = stack->B->head;
        ft_printf("pb\n");
    }
}

void RRB_DCLL_list(t_main *stack)
{
    stack->B->head = stack->B->tail;
    stack->B->tail = stack->B->tail->prev;
    stack->B->stack = stack->B->head;
    ft_printf("rrb\n");
}

void RB_DCLL_list(t_main *stack)
{
    stack->B->tail = stack->B->head;
    stack->B->head = stack->B->head->next;
    stack->B->stack = stack->B->head;
    ft_printf("rb\n");
}

void SB_DCLL_list(t_main *stack)
{
    int a;

    a = stack->B->head->content;
    stack->B->head->content = stack->B->head->next->content;
    stack->B->head->next->content = a;
    ft_printf("sb\n");
}