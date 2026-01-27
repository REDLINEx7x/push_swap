//#include "../push_swap.h"
//#include "get_next_line.h"

//void free_and_exit(char **args, int *numbers, t_stack **a, t_stack **b)
//{
//    free_args(args);
//    free(numbers);
//    ft_clear_list(a);
//	ft_clear_list(b);
//    exit(0);
//}

//int reading_operations(t_stack **a, t_stack **b ,int fd)
//{
//	char *move;

//	move = NULL;
//	move = get_next_line(fd);
//	while(move)
//	{
//		if(!((swap_check(move, a,b) || rotate_check(move, a, b)
//			|| reverse_rotate_check(move, a, b) || push_check(move, a, b))))
//		{
//			free (move);
//			ft_errors();
//		}
//		else
//		{
//			free(move);
//			move = get_next_line(fd);
//		}
//	}
//	return (1);
//}


//int main(int ac, char **av)
//{
//	char **args;
//	int *numbers;
//	t_stack *stack_a;
//	t_stack *stack_b;

//	stack_a = NULL;
//	stack_b = NULL;
//	if(ac == 1)
//		return (0);
//	args = verify_args(ac, av);
//	numbers = convert_to_int(args, count_size(args));
//	stack_a = transfer_to_stack(numbers, count_size(args));
//	if(reading_operations(&stack_a, &stack_b, 0))
//	{
//		if(sorted(stack_a) && stack_b == NULL)
//			write(1, "OK\n", 3);
//		else
//			write(1, "KO\n", 3);
//	}

//}
