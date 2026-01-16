#include "push_swap.h"

char **verify_args(int ac, char *av[])
{
    char **args;
    char *s;
    int i;
    s = NULL;
    i = 1;

    while(i < ac)
    {
        if(av[i][0] == '\0')
            errors();
        s = ft_addspace(s, av[i]);

        i++;
    }
    args = ft_split(s, ' ');
    free(s);
    return (args);
}
int count_size(char **args)
{
    int size;
    size = 0;
    while(args[size] != NULL)
        size++;
    return(size);
}
int *convert_to_int(char **args, int count)
{
    int i;
    int j;
    int *numbers;

    i = 0;
    numbers = malloc(count * sizeof(int));
    if(!numbers)
        return (NULL);
    while(args[i] != NULL)
    {
        if (str_checker(args[i]))
            numbers[i] = ft_atoi(args[i]);
        else
            errors();
        i++;
    }
	if(ft_duplicated(numbers, count))
        free_all(numbers);
        errors();
    return(numbers);
}
static void	free_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

int ft_duplicated(int *numbers, int count)
{
    int j;
    int i;

    j = 0;
    i = 0;
    while(i < count - 1)
    {
        j = i + 1;
        while(j < count)
        {
            if(numbers[i] == numbers[j])
                return (1);
            j++;
        }
        i++;
    }
    return(0);
}
