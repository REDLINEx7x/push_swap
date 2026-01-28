/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moamhouc <moamhouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 20:04:22 by moamhouc          #+#    #+#             */
/*   Updated: 2026/01/28 21:42:46 by moamhouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	size = ft_list_size(*stack_a);
	if (size == 2)
		two_sort(stack_a);
	else if (size == 3)
		three_sort(stack_a);
	else if (size == 5 || size == 4)
		four_five_sort(stack_a, stack_b);
	else
		main_sort(stack_a, stack_b);
}

static void	ft_swap(int *a, int *b)
{
	int	room;

	room = *a;
	*a = *b;
	*b = room;
}

void	sorted_arr(int *arr, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] > arr[j])
				ft_swap(&arr[i], &arr[j]);
			j++;
		}
		i++;
	}
}

void	indixing_stack(int *arr, t_stack *stack_a, int size)
{
	t_stack	*tmp;
	int		i;

	tmp = stack_a;
	i = 0;
	while (tmp != NULL)
	{
		i = 0;
		while (i < size)
		{
			if (arr[i] == tmp->value)
			{
				tmp->index = i;
				break ;
			}
			i++;
		}
		tmp = tmp->next;
	}
}

void	filling_arr(t_stack *stack_a)
{
	int		*arr;
	int		i;
	int		size;
	t_stack	*tmp;

	tmp = stack_a;
	i = 0;
	size = ft_list_size(stack_a);
	arr = malloc(size * sizeof(int));
	if (!arr)
		return ;
	while (tmp != NULL)
	{
		arr[i] = tmp->value;
		tmp = tmp->next;
		i++;
	}
	sorted_arr(arr, size);
	indixing_stack(arr, stack_a, size);
	free(arr);
}
