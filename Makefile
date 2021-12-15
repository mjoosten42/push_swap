NAME = push_swap
FLAGS = -Wall -Werror -Wextra
LIBFT = libft/libft.a
SRC = 	main.c				\
		stack.c				\
		swap.c				\
		push.c				\
		rotate.c			\
		reverse_rotate.c
OBJ = $(SRC:.c=.o)
ARG = "2 1 3 9 5 8 6 4 7 0"

all: $(NAME)
	./push_swap $(ARG)

$(NAME): $(LIBFT) push_swap.h $(OBJ)
	gcc -o $@ $(OBJ) $(LIBFT)

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

.PHONY: clean, fclean, re