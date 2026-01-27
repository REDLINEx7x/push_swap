/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moamhouc <moamhouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 20:04:27 by moamhouc          #+#    #+#             */
/*   Updated: 2026/01/27 18:52:16 by moamhouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

typedef struct s_stack
{
    int value;
    int index;
    struct s_stack *next;
}	t_stack;

char	**ft_split(char *s, char c);
size_t	ft_strlen(char *s);
char	*ft_strdup(char *s1);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_strjoin(char *s1, char *s2);
int ft_atoi(char *s);
void    ft_errors();
void    free_args(char **args);
int count_size(char **args);
char *ft_addspace(char *s1, char *s2);
char **verify_args(int ac, char **av);
int str_checker(char *arg);
int ft_duplicated(int *numbers, int size);
int sorted(t_stack *stack);
int *convert_to_int(char **args, int count);

t_stack    *ft_new_node(int value);
void       ft_add_back(t_stack **head, t_stack *new_node);
int        ft_list_size(t_stack *head);
t_stack    *ft_last_node(t_stack *head);
void    ft_clear_list(t_stack **head);
t_stack *transfer_to_stack(int *numbers, int size);


//sort
void	sort(t_stack **stack_a, t_stack **stack_b);
void    main_sort(t_stack **stack_a, t_stack **stack_b);
void	main_sort_part2(t_stack **stack_a, t_stack **stack_b);
void	filling_arr(t_stack *stack_a);
void	two_sort(t_stack **stack);
void	three_sort(t_stack **stack);
void	four_five_sort(t_stack **stack_a, t_stack **stack_b);
void	indixing_stack(int *arr, t_stack *stack_a, int size);
void free_and_exit(char **args, int *numbers, t_stack **a, t_stack **b);

// Swap
void    swap(t_stack **stack);
void    sa(t_stack **stack_a);
void    sb(t_stack **stack_b);
void    ss(t_stack **stack_a, t_stack **stack_b);
// Rotate
void    rotate(t_stack **stack);
void    ra(t_stack **stack_a);
void    rb(t_stack **stack_b);
void    rr(t_stack **stack_a, t_stack **stack_b);
// Reverse Rotate
void    reverse_rotate(t_stack **stack);
void    rra(t_stack **stack_a);
void    rrb(t_stack **stack_b);
void    rrr(t_stack **stack_a, t_stack **stack_b);
// Push
void    push(t_stack **stack1, t_stack **stack2);
void    pa(t_stack **stack_a, t_stack **stack_b);
void    pb(t_stack **stack_a, t_stack **stack_b);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

#endif
