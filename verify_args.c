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
int *convert_to_int(char **args)
{
    int i;
    int j;
    int *numbers;

    i = 0;
    while(args[i] != NULL)
        i++;
    numbers = malloc(i * sizeof(int));
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
    j = 0;
    while(j > (i - 1))
    {
        if(numbers[j] == numbers[j + 1])
    }
    return(numbers);
}

int duplicated(int numbers)
{
    int j;
    
    j = 0;
    while(j > (i - 1))
    {
        if(numbers[j] == numbers[j + 1])
    }
    return(numbers);
}
