CC = cc
FLAGS = -Wall -Wextra -Werror

RM = rm -f

SRC = errors.c\
	ft_split.c\
	helpers.c \
	main.c \
	operations_1.c\
	operations_2.c\
	operations_3.c\
	operations_4.c\
	push_swap.c \
	small_sort.c \
	stack_.c \
	stack_utils.c \
	verify_args.c\
	butterfly_sort.c

BOSRC = bonus/checker.c \
	bonus/checker_main.c \
	bonus/get_next_line.c \
	bonus/get_next_line_utils.c \
	helpers.c \
	verify_args.c \
	ft_split.c \
	stack_.c\
	operations_1.c \
	operations_2.c \
	operations_3.c \
	operations_4.c \
	errors.c \
	stack_utils.c

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
	$(RM) $(NAME) $(BONUS_NAME)

re:fclean all

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(BOBJ)
	$(CC) $(FLAGS) $(BOBJ) -o $(BONUS_NAME)

.PHONY: all clean fclean re bonus
