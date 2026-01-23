/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moamhouc <moamhouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 20:04:45 by moamhouc          #+#    #+#             */
/*   Updated: 2026/01/23 20:04:46 by moamhouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_new_node(int value)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->next = NULL;
	new->value = value;
	new->index = -1;
	return (new);
}

void	ft_add_back(t_stack **head, t_stack *new_node)
{
    t_stack *tmp;

	if (!head || !new_node)
		return ;
    if(*head == NULL)
    {
        *head = new_node;
        return;
    }
    tmp = *head;
    while(tmp->next)
        tmp = tmp->next;
    tmp->next = new_node;
}
int ft_list_size(t_stack *head)
{
    int count;
    t_stack *tmp;

    count = 0;
    if(!head)
        return (0);
    tmp = head;
    while(tmp)
    {
        tmp = tmp->next;
        count++;
    }
    return (count);
}
t_stack *ft_last_node(t_stack *head)
{
    if(!head)
        return(NULL);
    while(head->next)
        head = head->next;
    return(head);

}
void    ft_clear_list(t_stack **head)
{
    t_stack *tmp;

    while(*head)
    {
        tmp = (*head)->next;
        free(*head);
        *head = tmp;
    }
}
