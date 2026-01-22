#include "push_swap.h"

void	sort(t_stack **stack_a, t_stack **stack_b)
{
	int size;

	size = ft_list_size(*stack_a);

	if(size == 2)
		two_sort(stack_a);
	if(size == 3)
		three_sort(stack_a);
	if(size == 5 || size == 4)
		four_five_sort(stack_a, stack_b);
	else
        main_sort(stack_a, stack_b);
}
void	indxing_nodes(t_stack *stack_a)
{
	int *arr;
	int i;
	int size;
	t_stack *tmp;

	i = 0;
	size = ft_list_size(stack_a);
	arr = malloc(size * sizeof(int));
	tmp = stack_a;
	while(tmp != NULL)
	{
		arr[i] = tmp->value;
		tmp = tmp->next;
		i++;
	}
	sorted_arr(arr, size);
	tmp = stack_a;
	i = 0;
	while(tmp != NULL)
	{
		i = 0;
		while (i < size)
		{
			if(arr[i] == tmp->value)
			{
				tmp->index = i;
				break;
			}
			i++;
		}
		tmp = tmp->next;
	}
	free(arr);
}
static void	ft_swap(int *a, int *b)
{
	int	room;

	room = *a;
	*a = *b;
	*b = room;
}
int *sorted_arr(int *arr, int size)
{
	int i;
	int j;

	i = 0;

	while(i < size - 1)
	{
		j = i + 1;
		while(j < size)
		{
			if(arr[i] > arr[j])
				ft_swap(&arr[i], &arr[j]);
			j++;
		}
		i++;
	}
	return (arr);
}

void main_sort(t_stack **stack_a, t_stack **satck_b)
{

}
