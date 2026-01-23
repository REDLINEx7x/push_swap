/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moamhouc <moamhouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 20:04:14 by moamhouc          #+#    #+#             */
/*   Updated: 2026/01/23 20:04:15 by moamhouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	int i = 0;
	while (i < count_size(args))
	{
		printf("%d\n", numbers[i]);
		i++;
	}
	stack_a = transfer_to_stack(numbers, count_size(args));
	sort(&stack_a, &stack_b);

}
