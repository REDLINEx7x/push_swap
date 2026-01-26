#include "push_swap.h"

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
    printf("done");
}
