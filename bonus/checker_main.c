/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moamhouc <moamhouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 21:33:39 by moamhouc          #+#    #+#             */
/*   Updated: 2026/01/29 10:05:23 by moamhouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "get_next_line.h"

void	free_allocated(char **args, int *numbers, t_stack **a, t_stack **b)
{
	free_args(args);
	free(numbers);
	ft_clear_list(a);
	ft_clear_list(b);
}

int	reading_operations(t_stack **a, t_stack **b, int fd)
{
	char	*move;

	move = NULL;
	move = get_next_line(fd);
	while (move)
	{
		if ((swap_check(move, a, b) || rotate_check(move, a, b)
				|| reverse_rotate_check(move, a, b) || push_check(move, a, b)))
		{
			free(move);
			move = get_next_line(fd);
		}
		else
		{
			free(move);
			return (0);
		}
	}
	return (1);
}

int	main(int ac, char **av)
{
	char	**args;
	int		*numbers;
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ac == 1)
		return (0);
	args = verify_args(ac, av);
	numbers = convert_to_int(args, count_size(args));
	stack_a = transfer_to_stack(numbers, count_size(args));
	if (reading_operations(&stack_a, &stack_b, 0) == 0)
	{
		free_allocated(args, numbers, &stack_a, &stack_b);
		ft_errors();
	}
	if (sorted(stack_a) && !stack_b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_allocated(args, numbers, &stack_a, &stack_b);
	return (0);
}
