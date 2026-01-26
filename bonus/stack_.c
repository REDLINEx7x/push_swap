/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moamhouc <moamhouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 20:04:38 by moamhouc          #+#    #+#             */
/*   Updated: 2026/01/26 17:58:29 by moamhouc         ###   ########.fr       */
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
            ft_clear_list(&stack_a);
			return (NULL);
		}
		ft_add_back(&stack_a, node);
		i++;
    }
	return (stack_a);
}

void    free_args(char **args)
{
    int i;

    if (!args)
        return ;
    i = 0;
    while (args[i])
    {
        free(args[i]);
        i++;
    }
    free(args);
}

int sorted(t_stack *stack)
{
    if (!stack)
        return (1);
    while(stack->next)
    {
        if(stack->value > stack->next->value)
            return(0);
        stack = stack->next;
    }
    return (1);
}
