/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   butterfly_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moamhouc <moamhouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 22:44:56 by redline           #+#    #+#             */
/*   Updated: 2026/01/29 18:26:34 by moamhouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	size_range(int size)
{
	if (size <= 10)
		return (2);
	if (size <= 100)
		return (16);
	return (35);
}

void	main_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	i;
	int	range;
	int	size;

	i = 0;
	size = ft_list_size(*stack_a);
	range = size_range(size);
	while (*stack_a && i < size)
	{
		if ((*stack_a)->index <= i)
		{
			pb(stack_a, stack_b);
			rb(stack_b);
			i++;
		}
		else if ((*stack_a)->index <= i + range)
		{
			pb(stack_a, stack_b);
			i++;
		}
		else
			ra(stack_a);
	}
	main_sort_part2(stack_a, stack_b);
}

int	max_index(t_stack *stack)
{
	int	max;

	max = stack->index;
	while (stack)
	{
		if (stack->index > max)
			max = stack->index;
		stack = stack->next;
	}
	return (max);
}

int	max_index_spot(t_stack *stack, int max)
{
	int	spot;

	spot = 0;
	while (stack)
	{
		if (stack->index == max)
		{
			return (spot);
		}
		stack = stack->next;
		spot++;
	}
	return (spot);
}

void	main_sort_part2(t_stack **stack_a, t_stack **stack_b)
{
	int	max;
	int	spot;
	int	size;

	while (*stack_b)
	{
		size = ft_list_size(*stack_b);
		max = max_index(*stack_b);
		spot = max_index_spot(*stack_b, max);
		while ((*stack_b)->index != max)
		{
			if (spot <= size / 2)
				rb(stack_b);
			else if (spot > size / 2)
				rrb(stack_b);
		}
		pa(stack_a, stack_b);
	}
}
