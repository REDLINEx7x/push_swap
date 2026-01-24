#include "push_swap.h"


int size_range(int size)
{
    if(size <= 100)
    {
        return(15);
    }
    return(35);
}

void main_sort(t_stack **stack_a, t_stack **stack_b)
{
    int i;
    int range;
    int size;

    size = ft_list_size(*stack_a);
    range = size_range(size);
    while(stack_a && i < size)
    {
        if((*stack_a)->index <= i)
        {
            pb(stack_a, satack_b);
            rb(stack_b);
            i++;
        }
        else if((*stack_a)->index >= i + range)
        {
            pb(stack_a, stack_b);
			i++;
        }
        else
            ra(stack_a);
    }
}
