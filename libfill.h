#ifndef LIBFILL_H
# define LIBFILL_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>

# define BOARD_SIZE 13

int				**translator(char *file, int tetrominoes);
int				file_checker(char *filename);
void			display_board(char **board, int boardSize);
bool			solver(char **board, int *board_size, int **pieces); 

#endif
