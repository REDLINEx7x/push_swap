CC = cc
FLAGS = -Wall -Wextra -Werror
RM = rm -f

SRC = errors.c ft_split.c helpers.c main.c \
	operations.c push_swap.c small_sort.c \
	stack_.c stack_utils.c verify_args.c\
	butterfly_sort.c\

BOSRC = /bonus/checker.c /bonus/helpers.c /bonus/verify_args.c /bonus/ft_split.c /bonus/stack_.c /bonus/errors.c /bonus/


OBJ = $(SRC:.c=.o)

BOBJ = $(BOSRC:.c=.o)

NAME = push_swap

BONUS_NAME = checker

all :$(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

%.o:%.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ) $(BOBJ)

fclean:clean
	$(RM) $(NAME)

re:fclean all

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(BOBJ)
	$(CC) $(FLAGS) $(BOBJ) -o $(BONUS_NAME)

.PHONY: all clean fclean re bonus
