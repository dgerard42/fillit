/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esterna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 12:33:32 by esterna           #+#    #+#             */
/*   Updated: 2017/04/06 22:08:57 by dgerard          ###   ########.fr       */
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
	if (!*str || i != 4)
		return (0);
	return (1);
}

int		checkrows(char *str)
{
	int i;

	while (*str)
	{
		i = 4;
		while (i)
		{
			if (*str == '.' || *str == '#')
			   str++;
			else
				return (0);
			i--;	
		}
		if (*str != '\n' || *(++str) != '\0')
			return (0);
		str++;
	}
	return (1);
}

int		checktets(char *str)
{
	while (*str)
	{
		while (*str == '.' || *str == '\n')
			str++;
		if (*str == '#')
		{
			if (*(str - 1) != '#' && *(str + 1) != '#' && *(str + 5) != '#'
					&& *(str - 5) != '#')
				return (0);
			str++;
		}
	}
	return (1);
}

int		filechecker(char *filename)
{
	int		i;
	int		fd;
	char	*buf;

	i = 0;	
//	fd = 0;
	buf = (char *)malloc(sizeof(char) * (21));
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr("error in opening file\n");
		return (0);
	}
	while (read(fd, buf, 21) > 0)
	{
		if (fd == -1)
		{
			ft_putstr("error in reading file\n");
			return (0);
		}
		i++;
		if (!checkchrs(buf) || !checkrows(buf) || !checktets(buf) || i > 26)
		{
			ft_putstr("error invalid tetrimino in file\n");
			return (0);
		}
	}
	if (i > 26)
	{
		ft_putstr("error too many tetriminos in file\n");
		return (0);
	}
	if (close(fd) == -1)
		return (0);
	return (i);	
}
