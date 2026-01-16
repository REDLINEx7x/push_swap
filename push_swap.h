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
    struct s_stack *prev;
}	t_stack;

char	**ft_split(char *s, char c);
size_t	ft_strlen(char *s);
char	*ft_strdup(char *s1);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_strjoin(char *s1, char *s2);
int ft_atoi(char *s);
char *ft_addspace(char *s1, char *s2);
char **verify_args(int ac, char *av[]);
int str_checker(char *arg);
int ft_duplicated(int *numbers, int size);

#endif
