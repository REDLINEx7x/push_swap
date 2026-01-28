/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moamhouc <moamhouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 21:35:25 by moamhouc          #+#    #+#             */
/*   Updated: 2026/01/28 21:35:26 by moamhouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	swap_check(char *move, t_stack **stack_a, t_stack **stack_b)
{
	if (ft_strcmp(move, "sa\n") == 0)
		swap(stack_a);
	else if (ft_strcmp(move, "sb\n") == 0)
		swap(stack_b);
	else if (ft_strcmp(move, "ss\n") == 0)
	{
		swap(stack_a);
		swap(stack_b);
	}
	else
		return (0);
	return (1);
}

int	rotate_check(char *move, t_stack **stack_a, t_stack **stack_b)
{
	if (ft_strcmp(move, "ra\n") == 0)
		rotate(stack_a);
	else if (ft_strcmp(move, "rb\n") == 0)
		rotate(stack_b);
	else if (ft_strcmp(move, "rr\n") == 0)
	{
		rotate(stack_a);
		rotate(stack_b);
	}
	else
		return (0);
	return (1);
}

int	reverse_rotate_check(char *move, t_stack **stack_a, t_stack **stack_b)
{
	if (ft_strcmp(move, "rra\n") == 0)
		reverse_rotate(stack_a);
	else if (ft_strcmp(move, "rrb\n") == 0)
		reverse_rotate(stack_b);
	else if (ft_strcmp(move, "rrr\n") == 0)
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
	if (ft_strcmp(move, "pa\n") == 0)
		push(stack_b, stack_a);
	else if (ft_strcmp(move, "pb\n") == 0)
		push(stack_a, stack_b);
	else
		return (0);
	return (1);
}
