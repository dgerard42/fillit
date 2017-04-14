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

char			**tetriTranslator(char *file, int numTetri);
int				filechecker(char *filename);
char			**addPiece(char **board, char *piece, int p_order, int *place);
bool			pieceFits(char **board, int boardSize, char *piece, int *place);
bool			solve(char **board, int boardSize, char **pieces, int numPieces);
void			displayBoard(char **board, int boardSize);
int				nextNum(char **str);

#endif
