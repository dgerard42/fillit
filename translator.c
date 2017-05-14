/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translator.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esterna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 12:34:15 by esterna           #+#    #+#             */
/*   Updated: 2017/05/09 18:02:10 by esterna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libfill.h"

static void		ft_codegen(char *buf, int *dest, int k1)
{
	int i;
	int k2;
	int r;
	int hashtags;

	i = 0;
	r = 0;
	hashtags = 0;
	k2 = k1 + 1;
	while (buf[k2] && hashtags < 3)
	{
		while (buf[k2] != '\n' && buf[k2] != '#' && buf[k2])
			k2++;
		if (buf[k2] == '\n')
			r++;
		else
		{
			hashtags++;
			dest[i++] = r;
			dest[i++] = (r > 0) ? ((k2 % 5) - (k1 % 5)) : (k2 - k1);
		}
		k2++;
	}
}

static int		read_loop(int fd, int **lst)
{
	int		i;
	int		k1;
	char	*buf;

	i = 0;
	k1 = 0;
	buf = (char *)malloc(sizeof(char) * 21);
	while (read(fd, buf, 21) > 0)
	{
		if (fd == -1)
		{
			free(buf);
			free(lst);
			return (0);
		}
		while (buf[k1] != '#')
			k1++;
		ft_codegen(buf, lst[i], k1);
		i++;
		k1 = 0;
	}
	free(buf);
	return (i);
}

int				**translator(char *file, int num_tetri)
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
