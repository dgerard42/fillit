/* ************************************************************************* */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esterna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 12:33:32 by esterna           #+#    #+#             */
/*   Updated: 2017/04/17 17:40:07 by esterna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libfill.h"

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
				return (0);
			i--;	
		}
		if (*str != '\n')
			return (0);
		if (*(str + 1) == '\n')
			str++;
		str++;
	}
	return (1);
}

int		checktets(char *str)
{
	int conxs;

	conxs = 0;
	while (*str)
	{
		while (*str == '.' || *str == '\n')
			str++;
		if (*str == '#')
		{
			if (*(str - 1) == '#')
				conxs++;
			if (*(str + 1) == '#')
				conxs++;
			if (*(str + 5) == '#')
			   conxs++;	
			if (*(str - 5) == '#')
				conxs++;
		}
		str++;
	}
	return (((conxs == 6) || (conxs == 8)) ? 1 : 0);
}

int		file_checker(char *filename)
{
	int		fd;
	int		rd;
	int		numTetri;
	int		last;
	char	*buf;

	numTetri = 0;
	buf = (char *)malloc(sizeof(char) * (22));
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (0);
	while ((rd = read(fd, buf, 21)) && rd > 0)
	{	
		last = rd;	
		buf[rd] = 0;
		if (fd == -1)
		{
			free(buf);
			return (0);
		}
		if (!checkchrs(buf) || !checkrows(buf) || !checktets(buf) || numTetri > 26)
		{
			free(buf);
			close(fd);
			return (0);
		}
		numTetri++;
	}
	free(buf);
	if (last != 20 || numTetri > 26)
	{
		close(fd);
		return (0);
	}
	if (close(fd) == -1)
		return (0);
	return (numTetri);	
}
