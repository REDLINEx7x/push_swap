#include "push_swap.h"

t_stack *transfer_to_stack(int *numbers, int size)
{
    t_stack *stack_a;
	t_stack *node;
    int i;

    i = 0;
    stack_a = NULL;
    while(i < size)
    {
    	node =  ft_new_node(numbers[i]);
		if(!node)
		{
			return (NULL);
			ft_clear_list(&stack_a);
		}
		ft_add_back(&stack_a, node);
		i++;
    }
	return (stack_a);
}

void	sort(t_stack **stack_a, t_stack **stack_b)
{
	int size;

	size = ft_list_size(*stack_a);

	if(size == 2)
		two_sort(stack_a);
	if(size == 3)
		three_sort(stack_a);
	if(size == 5 || size == 4)
		four_five_sort(stack_a, stack_b);
	else;
}

void	two_sort(t_stack **stack)
{
	if((*stack)->value > (*stack)->next->value)
		sa(stack);
}

void	three_sort(t_stack **stack)
{
	if((*stack)->value > (*stack)->next->value
		&& (*stack)->value > (*stack)->next->next->value)
		ra(stack);
	else if ((*stack)->next->value > (*stack)->next->next->value)
		rra(stack);
	if((*stack)->value > (*stack)->next->value)
		sa(stack);

}
int min_value(t_stack *stack)
{
	int min;

	min = stack->value;
	while(stack->next)
	{
		if(stack->next->value < min)
		{
			min = stack->next->value;
		}
		stack = stack->next;
	}
	return (min);
}
void move_node(t_stack **stack_a, int size)
{
	int min;
	int i;

	i = 0;
	min = min_value(*stack_a);
	t_stack *tmp = *stack_a;
	while(tmp->value != min)
	{
		i++;
		tmp = tmp->next;
	}
	while((*stack_a)->value != min)
	{
		if(i <= size / 2)
			ra(stack_a);
		else
			rra(stack_a);
	}
}


void	four_five_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	size;
	int i;

	i = 0;
	int min = min_value(*stack_a);
	size = ft_list_size(*stack_a);
	while(size > 3)
	{
		move_node(*stack_a, size);
		pb(stack_a, stack_b);
	}
	three_sort(stack_a);
	pa(stack_b, stack_a);
	pa(stack_b, stack_a);
}

