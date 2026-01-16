#include "push_swap.h"

int main(int ac, char **av)
{
	char **args;
	int *numbers;

	args = verify_args(ac, av);
	numbers = convert_to_int(args, count_size(args));
	ft_duplicated(numbers, count_size(args));




}
