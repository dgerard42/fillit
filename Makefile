NAME = fillit
CFLAGS = -Wall -Wextra -Werror
DEPS = libft
FUNCTIONS = main.c\
			file_checker.c\
			translator.c\
			solver.c\
			check_add_remove.c

OBJ = $(FUNCTIONS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	gcc $(CFLAGS) -o $@ $(OBJ) $(DEPS).a
%.o: %.c
	gcc $(CFLAGS) -c $^ -o $@
clean:
	/bin/rm -f rm $(OBJ)

fclean: clean
	/bin/rm -f rm $(NAME)

re: fclean all
