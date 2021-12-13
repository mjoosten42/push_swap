NAME = push_swap
FLAGS = -Wall -Werror -Wextra
LIBFT = libft/libft.a
HEADER = push_swap.h
SRC = 	main.c		\
		stack.c		\
		swap.c		\
		push.c		\
		rotate.c	
ARG = "2 1 3"

all: $(NAME)
	./push_swap $(ARG)

$(NAME): $(SRC) $(HEADER) $(LIBFT)
	gcc $(FLAGS) -o $(NAME) $(SRC) $(LIBFT)

$(LIBFT):
	make -C libft

clean:
	make fclean -C libft

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean, fclean, re