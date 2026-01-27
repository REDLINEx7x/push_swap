#include "push_swap.h"

void    push(t_stack **stack1, t_stack **stack2)
{
    t_stack *tmp;
    if(!stack1 || !*stack1)
        return;
    tmp = *stack1;

    *stack1 = (*stack1)->next;
    tmp->next = *stack2;
    *stack2 = tmp;
}

void pa(t_stack **stack_a, t_stack **stack_b)
{
    push(stack_b, stack_a);
    write(1, "pa\n", 3);
}
void pb(t_stack **stack_a, t_stack **stack_b)
{
    push(stack_a, stack_b);
    write(1, "pb\n", 3);
}
