NAME = fillit
CFLAGS = -Wall -Wextra -Werror
DEPS = libft.a
FUNCTIONS = main.c\
			file_checker.c\
			display_board.c\
			translator.c\
			solver.c\
			auxillaries.c\
			check_add_remove.c\

all: $(NAME)

$(NAME):
	gcc -g $(CFLAGS) -o $@ $(FUNCTIONS) libft.a

clean:
	/bin/rm -f rm $(NAME)

fclean: clean

re: fclean all
