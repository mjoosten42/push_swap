NAME = push_swap
FLAGS = -Wall -Werror -Wextra
LIBFT = libft/libft.a
SRC = 	main.c				\
		error.c				\
		stack.c				\
		swap.c				\
		push.c				\
		rotate.c			\
		reverse_rotate.c	\
		init.c				\
		utils.c
OBJ =$(SRC:.c=.o)
ARG = 2 1 3 0

all: $(NAME)
	@./$(NAME) $(ARG)
#	@./$(NAME) $(ARG) | ./checker_Mac $(ARG)

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
