/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moamhouc <moamhouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 20:04:19 by moamhouc          #+#    #+#             */
/*   Updated: 2026/01/28 21:40:13 by moamhouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **stack)
{
	int	tmp;

	tmp = 0;
	if (!stack || !*stack || !(*stack)->next)
		return ;
	tmp = (*stack)->value;
	(*stack)->value = (*stack)->next->value;
	(*stack)->next->value = tmp;
}

void	sa(t_stack **stack_a)
{
	swap(stack_a);
	write(1, "sa\n", 3);
}

void	sb(t_stack **stack_b)
{
	swap(stack_b);
	write(1, "sb\n", 3);
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	write(1, "ss\n", 3);
}

// void rotate(t_stack **stack)
//{
//    t_stack *first_node;
//    t_stack *last_node;
//    if(!stack || !*stack || !(*stack)->next)
//        return ;
//    first_node = *stack;
//    last_node = ft_last_node(*stack);

//    *stack = first_node->next;
//    first_node->next = NULL;
//    last_node->next = first_node;
//}

// void ra(t_stack **stack_a)
//{
//    rotate(stack_a);
//    write(1, "ra\n", 3);
//}

// void rb(t_stack **stack_b)
//{
//    rotate(stack_b);
//    write(1, "rb\n", 3);
//}
// void rr(t_stack ** stack_a, t_stack **stack_b)
//{
//    rotate(stack_a);
//    rotate(stack_b);
//    write(1, "rr\n", 3);
//}

// void reverse_rotate(t_stack **stack)
//{
//    t_stack *last;
//    t_stack *before;

//    if(!stack || !*stack || !(*stack)->next)
//        return ;
//    last = *stack;
//    while(last->next != NULL)
//    {
//        before = last;
//        last = last->next;
//    }
//    before->next = NULL;

//    last->next = *stack;
//    *stack = last;
//}

// void rra(t_stack **stack_a)
//{
//    reverse_rotate(stack_a);
//    write(1, "rra\n", 4);
//}

// void rrb(t_stack **stack_b)
//{
//    reverse_rotate(stack_b);
//    write(1, "rrb\n", 4);
//}
// void rrr(t_stack **stack_a, t_stack **stack_b)
//{
//    reverse_rotate(stack_a);
//    reverse_rotate(stack_b);
//    write(1, "rrr\n", 4);
//}
// void    push(t_stack **stack1, t_stack **stack2)
//{
//    t_stack *tmp;
//    if(!stack1 || !*stack1)
//        return ;
//    tmp = *stack1;

//    *stack1 = (*stack1)->next;
//    tmp->next = *stack2;
//    *stack2 = tmp;
//}

// void pa(t_stack **stack_a, t_stack **stack_b)
//{
//    push(stack_b, stack_a);
//    write(1, "pa\n", 3);
//}
// void pb(t_stack **stack_a, t_stack **stack_b)
//{
//    push(stack_a, stack_b);
//    write(1, "pb\n", 3);
//}
