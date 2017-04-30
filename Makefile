NAME = fillit
CFLAGS = -Wall -Wextra -Werror -g
DEPS = libft.a
FUNCTIONS = main.c\
			pieceFits.c\
			addPiece.c\
			nextNum.c\
			file_checker.c\
			displayBoard.c\
			tetriTranslator.c\
			solve.c\

all: $(NAME)

$(NAME):
	gcc $(CFLAGS) -o $@ $(FUNCTIONS) libft.a

clean:
	/bin/rm -f rm $(NAME)

fclean: clean

re: fclean all
