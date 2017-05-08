/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translator.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esterna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 12:34:15 by esterna           #+#    #+#             */
/*   Updated: 2017/05/07 22:27:14 by dgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libfill.h"

static void			ft_codegen(char *buf, int *dest)
{
	int i;
	int k1;
	int k2;
	int r;
	int hashtags;

	i = 0;
	k1 = 0;
	k2 = 0;
	r = 0;
	hashtags = 0;
	while (*buf != '#')
	{
		k1++;
		buf++;
	}
	k2 = k1 + 1;
	buf++;
	while (*buf && hashtags < 3)
	{
		while (*buf != '\n' && *buf != '#' && *buf)
		{
			buf++;
			k2++;
		}
		if (*buf == '#')
			hashtags++;
		if (*buf == '\n')
		{
			r++;
			k2++;
			buf++;
		}
		else
		{
			dest[i++] = r;
			if (r > 0)
			{
				if ((k2 % 5) - (k1 % 5) < 0)
					dest[i++] = -((k1 % 5) - (k2 % 5));
				else
					dest[i++] = ((k2 % 5) - (k1 % 5));
			}
			else
			{
				if (k2 - k1 < 0)
					dest[i++] = -(k1 - k2);
				else
					dest[i++] = (k2 - k1);
			}
			k2++;
			buf++;
		}
	}
}
static int	read_loop(int fd, int **lst)
{
	int		i;
	char	*buf;

	i = 0;
	buf = (char *)malloc(sizeof(char) * 21);
	while (read(fd, buf, 21) > 0)
	{
		if (fd == -1)
		{
			free(buf);
			free(lst);
			return (0);
		}
		ft_codegen(buf, lst[i]);
		i++;
	}
	free(buf);
	return (i);
}
int			**translator(char *file, int num_tetri)
{
	int		i;
	int		fd;
	int		**lst;

	lst = ft_2dintarray((size_t)num_tetri, (size_t)6);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (NULL);
	i = read_loop(fd, lst);
	if (i != num_tetri)
	{
		free(lst);
		return (NULL);
	}
	lst[num_tetri] = NULL;
	return (lst);
}
