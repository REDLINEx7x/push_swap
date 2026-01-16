CC = cc
FLAGS = -Wall -Wextra -Werror
RM = rm -f
AR = ar rcs

SRC = checkers.c errors.c ft_split.c helpers.c main.c push_swap.c verify_args.c

OBJ = (SRC:.c=.o)

NAME: push_swap

%.o:%.c
	$(CC) $(FLAGS) -c $< -o $@

all :$(NAME)
	$(AR) $(NAME) $(OBJ)

clean:
	$(RM) (OBJS)

fclean:clean
	$(RM) $(NAME)

re:fclean all

.PHONY: all clean fclean re
