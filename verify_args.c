#include "push_swap.h"

char **verify_args(int ac, char *av[])
{
    char **args;
    if(ac < 2 || (ac == 2 && av[1][0] == '\0'))
        errors();
    if(ac == 2)
    {
        args = ft_split(av[1], ' ');
        if(!args)
            return(NULL);
    }
    if(ac > 2)
    {
        
    }




}
