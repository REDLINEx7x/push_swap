#include "push_swap.h"

int str_checker(char *arg)
{
    int i;

    i = 0;
    if((arg[0] == '-' || arg[0] == '+'))
        i++;
    if(arg[i] == '\0')
        return 0;
    while(arg[i] != '\0')
    {
        if(!(arg[i] >= '0' && arg[i] <= '9'))
            return (0);
        i++;
    }
    return (1);
}
