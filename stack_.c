/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moamhouc <moamhouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 20:04:38 by moamhouc          #+#    #+#             */
/*   Updated: 2026/01/23 20:04:39 by moamhouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *transfer_to_stack(int *numbers, int size)
{
    t_stack *stack_a;
	t_stack *node;
    int i;

    i = 0;
    stack_a = NULL;
    while(i < size)
    {
    	node =  ft_new_node(numbers[i]);
		if(!node)
		{
			return (NULL);
			ft_clear_list(&stack_a);
		}
		ft_add_back(&stack_a, node);
		i++;
    }
	return (stack_a);
}



