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
