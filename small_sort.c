/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moamhouc <moamhouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 20:04:32 by moamhouc          #+#    #+#             */
/*   Updated: 2026/01/26 17:37:59 by moamhouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
int	min_value(t_stack *stack)
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
void	move_node(t_stack **stack_a, int size)
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

	size = ft_list_size(*stack_a);
	while(ft_list_size(*stack_a) > 3)
	{
		size = ft_list_size(*stack_a);
		move_node(stack_a, size);
		pb(stack_a, stack_b);
		//printf("%d\n", size);
	}
	three_sort(stack_a);
    while(*stack_b)
    {
        pa(stack_a, stack_b);
    }
}

