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
        stack->B->head->next = stack->B->head;
        stack->B->head->prev = stack->B->head;
    }
    else
    {
        stack->A->head = stack->A->head->next;
        stack->A->head->prev = stack->A->tail;
        stack->A->tail->next = stack->A->head;
        stack->B->tail = stack->B->head->prev;
        temp->next = stack->B->head;
        temp->prev = stack->B->tail;
        stack->B->tail->next = temp;
        stack->B->head->prev = temp;
        stack->B->head = temp;
    }
}

void RRB_DCLL_list(t_main *stack)
{
    stack->B->head = stack->B->tail;
    stack->B->tail = stack->B->tail->prev;
}

void RB_DCLL_list(t_main *stack)
{
    stack->B->tail = stack->B->head;
    stack->B->head = stack->B->head->next;
}

void SB_DCLL_list(t_main *stack)
{
    t_node *temp;
    t_node *temp2;

    temp = stack->B->head;
    stack->B->head = stack->B->head->next;
    temp2 = stack->B->head->next;
    temp2->prev = temp;
    temp->next = stack->B->head->next;
    temp->prev = stack->B->head;
    stack->B->head->next = temp;
    stack->B->head->prev = stack->B->tail;
}