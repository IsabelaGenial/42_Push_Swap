#include "push_swap.h"

void sorted_two(t_main *stack)
{
    t_node *temp;

    temp = stack->A->head->next;
    if (stack->A->head->content > temp->content)
        SA_DCLL_list(stack);
}

void sorted_three(t_main *stack)
{
    int pos;

    pos = find_content_max(stack);
    if (pos == 1)
        RA_DCLL_list(stack);
    if (pos == 2)
        RRA_DCLL_list(stack);
    sorted_two(stack);
}

void sorted_four(t_main *stack)
{
    int pos;

    pos = find_content_min(stack);
    if(pos == 4)
        RRA_DCLL_list(stack);
    else if (pos == 3)
    {
        RRA_DCLL_list(stack);
        RRA_DCLL_list(stack);
    }
    else if(pos == 2)
        SA_DCLL_list(stack);
    PB_DCLL_list(stack);
    stack->len -= 1;
    sorted_three(stack);
    PA_DCLL_list(stack);
    stack->len += 1;
}

void sorted_five(t_main *stack)
{
    int pos;

    pos = find_content_min(stack);
    if(pos == 5)
        RRA_DCLL_list(stack);
    else if(pos == 4)
    {
        RRA_DCLL_list(stack);
        RRA_DCLL_list(stack);
    }
    else if(pos == 3)
    {
        RRA_DCLL_list(stack);
        RRA_DCLL_list(stack);
        RRA_DCLL_list(stack);
    }
    else if(pos == 2)
        SA_DCLL_list(stack);
    PB_DCLL_list(stack);
    stack->len -= 1;
    sorted_four(stack);
    PA_DCLL_list(stack);
    stack->len += 1;
}

int    find_content_min(t_main *stack)
{
    t_node *major;
    int     pos;
    int     i;

    i = 1;
    pos = 1;
    major = stack->A->head;
    stack->A->stack = stack->A->head;
    while (i <= stack->len)
    {
        if (major->content > stack->A->stack->content)
        {
            major = stack->A->stack;
            pos = i;
        }
        stack->A->stack = stack->A->stack->next;
        i++;
    }
    stack->A->stack = stack->A->head;
    return (pos);
}

int    find_content_max(t_main *stack)
{
    t_node *major;
    int     pos;
    int     i;

    i = 1;
    pos = 1;
    major = stack->A->head;
    stack->A->stack = stack->A->head;
    while (i <= stack->len)
    {
        if (major->content < stack->A->stack->content)
        {
            major = stack->A->stack;
            pos = i;
        }
        stack->A->stack = stack->A->stack->next;
        i++;
    }
    stack->A->stack = stack->A->head;
    return (pos);
}