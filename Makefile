NAME = push_swap
FLAGS = -Wall -Werror -Wextra
LIBFT = libft/libft.a
SRC = 	main.c				\
		error.c				\
		stack.c				\
		swap.c				\
		push.c				\
		rotate.c			\
		reverse_rotate.c
OBJ = $(SRC:.c=.o)
ARG = 0 -1 -2
all: $(NAME)
	@./$(NAME) $(ARG) | wc -l
	@./$(NAME) $(ARG) | ./checker_Mac $(ARG)

$(NAME): $(LIBFT) push_swap.h $(OBJ)
	gcc $(FLAGS) -o $@ $(LIBFT) $(OBJ)

$(LIBFT):
	make -C libft

%.o: %.c
	gcc $(FLAGS) -c $^

clean:
	make fclean -C libft
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re
