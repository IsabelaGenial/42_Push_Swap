# include "push_swap.h"

int is_sorted(t_main *stack)
{
    int i;
    t_node *temp;

    temp = stack->A->head;
    if (stack->B->head == NULL)
    {
        i = 1;
        while (i < stack->len)
        {
            if (temp->content > temp->next->content)
                return (1);
            temp = temp->next;
            i++;
        }
    }
    return (0);
}

int    find_position_max(t_main *stack)
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

int    find_position_min(t_main *stack)
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

int is_not_digit(char **c)
{
    int i;
    int j;

    i = 0;
    while(c[i] != NULL)
    {
        j = 0;
        while(c[i][j] != '\0')
        {
            if (!ft_isdigit(c[i][j]))
                return(1);
            j++;
        }
        i++;
    }
    return (0);
}

int is_duplicates(t_main *stack)
{
    t_node *aux;

    stack->A->stack = stack->A->head;
    while(stack->A->stack != stack->A->head)
    {
        aux = stack->A->stack->next;
        while(aux != stack->A->head)
        {
            if(stack->A->stack->content == aux->content)
                return (1);
            aux = aux->next;
        }
        stack->A->stack = stack->A->stack->next;
    }
    return (0);
}