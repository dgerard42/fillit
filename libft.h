#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>


void			ft_putstr(const char *str);
char			*ft_strcpy(char *dst, const char *src);
char			**tetriTranslator(char *file, int numTetri);
char			**ft_2dstrnew(size_t x, size_t y);
char			*ft_strnew(size_t size);
int				filechecker(char *filename);
