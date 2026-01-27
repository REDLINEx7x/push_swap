#include "../push_swap.h"
#include "get_next_line.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}
int swap_check(char *move, t_stack **stack_a, t_stack **stack_b)
{
	if(ft_strcmp(move, "sa\n") == 0)
		swap(stack_a);
	else if(ft_strcmp(move, "sb\n") == 0)
		swap(stack_b);
	else if(ft_strcmp(move, "ss\n") == 0)
	{
		swap(stack_a);
		swap(stack_b);
	}
	else
		return(0);
	return (1);
}
int rotate_check(char *move, t_stack **stack_a, t_stack **stack_b)
{
	if(ft_strcmp(move, "ra\n") == 0)
		rotate(stack_a);
	else if(ft_strcmp(move, "rb\n") == 0)
		rotate(stack_b);
	else if(ft_strcmp(move, "rr\n") == 0)
	{
		rotate(stack_a);
		rotate(stack_b);
	}
	else
		return (0);
	return (1);
}
int reverse_rotate_check(char *move, t_stack **stack_a, t_stack **stack_b)
{

	if(ft_strcmp(move, "rra\n") == 0)
		reverse_rotate(stack_a);
	else if (ft_strcmp(move, "rrb\n") == 0)
		reverse_rotate(stack_b);
	else if(ft_strcmp(move, "rrr") == 0)
	{
		reverse_rotate(stack_a);
		reverse_rotate(stack_b);
	}
	else
		return (0);
	return (1);
}
int	push_check(char *move, t_stack **stack_a, t_stack **stack_b)
{
	if(ft_strcmp(move, "pa\n") == 0)
		push(stack_b, stack_a);
	else if (ft_strcmp(move, "pb\n") == 0)
		push(stack_a, stack_b);
	return (1);
}

int reading_operations(t_stack **a, t_stack **b ,int fd)
{
	char *move;

	move = NULL;
	move = get_next_line(fd);
	while(move)
	{
		if(!((swap_check(move, a,b) || rotate_check(move, a, b)
			|| reverse_rotate_check(move, a, b) || push_check(move, a, b))))
		{
			free (move);
			ft_errors();
		}
		else
		{
			free(move);
			move = get_next_line(fd);
		}
	}
	return (1);
}
void free_and_exit(char **args, int *numbers, t_stack **a, t_stack **b)
{
    free_args(args);
    free(numbers);
    ft_clear_list(a);
	ft_clear_list(b);
    exit(0);
}


int main(int ac, char **av)
{
	char **args;
	int *numbers;
	t_stack *stack_a;
	t_stack *stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if(ac == 1)
		return (0);
	args = verify_args(ac, av);
	numbers = convert_to_int(args, count_size(args));
	stack_a = transfer_to_stack(numbers, count_size(args));
	if(reading_operations(&stack_a, &stack_b, 0))
	{
		if(sorted(stack_a) && stack_b == NULL)
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
	}
	free_and_exit(args, numbers, &stack_a, &stack_b);
}
