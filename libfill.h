#ifndef LIBFILL_H
# define LIBFILL_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# define BOARD_SIZE 13

char			**tetriTranslator(char *file, int numTetri);
int				filechecker(char *filename);

#endif
