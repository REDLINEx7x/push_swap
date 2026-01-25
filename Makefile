CC = cc
FLAGS = -Wall -Wextra -Werror
RM = rm -f

SRC = errors.c ft_split.c helpers.c main.c operations.c push_swap.c small_sort.c stack_.c stack_utils.c verify_args.c butterfly_sort.c

OBJ = $(SRC:.c=.o)

NAME = push_swap

all :$(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

%.o:%.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean:clean
	$(RM) $(NAME)

re:fclean all

.PHONY: all clean fclean re
