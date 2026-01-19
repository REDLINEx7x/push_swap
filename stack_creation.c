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

//void	sort(t_stack **stack_a)
//{
//	int size;

//	size = ft_list_size(*stack_a);

//	if(size == 2)

//	if(size == 3)

//	if(size == 5);

//}

//void two_sort(t_stack **stack)
//{

//}


