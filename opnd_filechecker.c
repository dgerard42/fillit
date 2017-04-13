/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esterna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 12:33:32 by esterna           #+#    #+#             */
/*   Updated: 2017/04/11 20:40:04 by dgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		checkchrs(char *str)
{
	int i;

	i = 0;
	while (*str && (*str == '.' || *str == '#' || *str == '\n'))
	{
		if (*str == '#')
			i++;
		str++;
	}
	if (*str || i != 4)
		return (0);
	return (1);
}

int		checkrows(char *str)
{
	int i;

	while (*str)
	{
		i = 4;
		while (i > 0 && *str)
		{
			if (*str == '.' || *str == '#')
			   str++;
			else
			{
//				printf("INVALIDHERE0\n");
//				printf("val of str that threw it off = %d\n", (int)*str);
				return (0);
			}
			i--;	
		}
		if (*str != '\n')
		{
//			printf("INVALIDHERE1\n");
			return (0);
		}
//		if (*(str + 2) == '\0')
//			return (0);
//		printf("*(str + 2) = %d\n", (int)*(str + 2));
//		printf("*(str + 1) = %d\n", (int)*(str + 1));
		if (*(str + 1) == '\n')
			str++;
		str++;
	}
//	printf("returnhere\n");
	return (1);
}

int		checktets(char *str)
{
//	printf("%s\n", str);
	int conxs;

	conxs = 0;
	while (*str)
	{
		while (*str == '.' || *str == '\n')
			str++;
		if (*str == '#')
		{
			/*
			printf("*(str - 1) = %c\n", *(str - 1));
			printf("*(str + 1) = %c\n", *(str + 1));
			printf("*(str - 5) = %c\n", *(str - 5));
			printf("*(str + 5) = %cEND BLOCK\n", *(str + 5));
			*/
			if (*(str - 1) == '#')
			{
//				printf("incr -1\n");
				conxs++;
			}
			if (*(str + 1) == '#')
			{
//				printf("incr + 1\n");
				conxs++;
			}
			if (*(str + 5) == '#')
			{
//				printf("incr +5\n");
			   conxs++;	
			}
			if (*(str - 5) == '#')
			{
//				printf("incr - 5\n");
				conxs++;
			}
		}
		str++;
	}
	return (((conxs == 6) || (conxs == 8)) ? 1 : 0);
}

/*
int		nlCount(char *filename)
{
	int		fd;
	int		rd;
	int		nls;
	char	*buf;

	nls = 0;
	buf = (char *)malloc(sizeof(char) * (547));
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		printf("fd is less than zero\n");
		return (0);
	}
	rd = read(fd, buf, 546);
	buf[rd] = '\0';
	if (fd == -1)
	{
		printf("fd is -1 after read attempt!\n");
		return (0);
	}
	while (*buf)
	{
		buf++;
		if (*buf == '\n')
			nls++;
	}
	if (close(fd) == -1)
	{
		printf("it did not close!!!1\n");
		return (0);
	}
	if (nls % 5 == 4)
		return (1);
	return (0);
}
*/

int		filechecker(char *filename)
{
	int		fd;
	int		rd;
	int		numTetri;
	int		last;
	char	*buf;

	numTetri = 0;
//	if (!(nlCount(filename)))
//	{
//		printf ("it here, the newline count was off.\n");
//		return (0);
//	}
	buf = (char *)malloc(sizeof(char) * (22));
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		printf("fd = %d\n", fd);
		ft_putstr("error in opening file\n");
		return (0);
	}
	while ((rd = read(fd, buf, 21)) && rd > 0)
	{	
		last = rd;	
		buf[rd] = 0;
//		printf("%s\n", buf);
		if (fd == -1)
		{
			ft_putstr("error in reading file\n");
			return (0);
		}
		if (!checkchrs(buf) || !checkrows(buf) || !checktets(buf) || numTetri > 26)
		{
			if (!checkchrs(buf))
				ft_putstr("invalid chars in this file\n");
			if (!checkrows(buf))
				ft_putstr("invalid row numbers\n");
			if (!checktets(buf))
				ft_putstr("invalid tetrimino\n");
			if (numTetri > 26)
				ft_putstr("i is > 26\n");
//			printf("the invalid tetrimino:\n%s", buf);
			return (0);
		}
		numTetri++;
//		printf("i val%d", i);
	}
	//combo these next two if statements after debugging
	if (last != 20)
	{
		printf ("it here, the newline count was off.\n");
		return (0);
	}
	if (numTetri > 26)
	{
		ft_putstr("error too many tetriminos in file\n");
		return (0);
	}
	if (close(fd) == -1)
		return (0);
	return (numTetri);	
}
