NAME = push_swap
BONUS = checker
FLAGS = -Wall -Werror -Wextra
LIBFT = libft/libft.a

SRC = 		main.c					\
			stack.c					\
			sort.c					\
			utils.c					\
			swap.c					\
			push.c					\
			rotate.c				\
			reverse_rotate.c

BONUSSRC =	checker.c				\
			stack.c					\
			utils.c					\
			bonus_swap.c			\
			bonus_push.c			\
			bonus_rotate.c			\
			bonus_reverse_rotate.c

OBJ = $(SRC:.c=.o)
BONUSOBJ = $(BONUSSRC:.c=.o)

ARG =	\
4 3 0 1 2

all: $(NAME)

$(NAME): $(LIBFT) push_swap.h $(OBJ)
	gcc $(FLAGS) -o $@ $(LIBFT) $(OBJ)

$(LIBFT):
	make -C libft

$(BONUS): $(LIBFT) push_swap.h $(BONUSOBJ)
	gcc $(FLAGS) -o $@ $(LIBFT) $(BONUSOBJ)

%.o: %.c
	gcc $(FLAGS) -c $^

clean:
	make fclean -C libft
	rm -f $(OBJ)
	rm -f $(BONUSOBJ)

fclean: clean
	rm -f $(NAME)
	rm -f $(BONUS)

re: fclean all

test: all
	@./$(NAME) $(ARG) | wc -l
	@./$(NAME) $(ARG) | ./checker_Mac $(ARG)

bonus: $(BONUS)

.PHONY: clean fclean re test bonus
