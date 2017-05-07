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
void			display_board(char **board, int boardSize);
bool			solver(char **board, int *board_size, int **pieces);
char			check_alpha(char **board);
int				rough_sqrt(int n);
void 			remove_piece(char **board);
void 			add_piece(char **board, int *piece, int *place);
void			increment_place(int *place, int board_size);
bool			check_piece(char **board, int size, int *piece, int *place);
bool			grow_board(char **board, int **place, int **pieces, int *board_size);
bool			fill_board(char **board, int **pieces, int **place, int *board_size);

#endif
