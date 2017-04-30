#ifndef LIBFILL_H
# define LIBFILL_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>

int				**translator(char *file, int tetrominoes);
int				file_checker(char *filename);
void			displayBoard(char **board, int boardSize);

#endif
