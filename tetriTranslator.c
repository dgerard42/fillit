/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetriTranslator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esterna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 12:34:15 by esterna           #+#    #+#             */
/*   Updated: 2017/04/06 21:59:58 by dgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*trans_g1(char *buf)
{
	if (*(buf + 5) == '#' && *(buf + 10) == '#' && *(buf + 15) == '#')
		return ("5.5.5");
	else if (*(buf + 10) == '#')
	{
		if (*(buf + 11) == '#')
			return ("5.5.1");
		else if (*(buf + 9) == '#')
			return ("5.4.1");
		else if (*(buf + 6) == '#')
			return ("5.1.4");
		return ("4.1.5");
	}
	if (*(buf + 4) == '#' && *(buf + 6) == '#')
		return ("4.1.1");
	else if (*(buf + 3) == '#')
		return ("3.1.1");
	else if (*(buf + 4) == '#')
		return ("4.1.4");
	else if (*(buf + 7) == '#')
		return ("5.1.1");
	return ("5.1.5");
}

char		*trans_g2(char *buf)
{
	if (*(buf + 1) == '#' && *(buf + 2) == '#' && *(buf + 3) == '#')
		return ("1.1.1");
	else if (*(buf + 2) == '#')
	{
		if (*(buf + 5) == '#')
			return ("1.1.3");
		else if (*(buf + 6) == '#')
			return ("1.1.4");
		return ("1.1.5");
	}
	else
	{
		if (*(buf + 5) == '#')
		{
			if (*(buf + 4) == '#')
				return ("1.3.1");
			else if (*(buf + 10) == '#')
				return ("1.4.5");
			return ("1.4.1");
		}
		return (*(buf + 11) == '#' ? "1.5.5" : "1.5.1");
	}
}

char		*translate(char *buf)
{
	while (*buf != '#')
		buf++;
	if (*(buf + 1) != '#')
		return (trans_g1(buf));
	return (trans_g2(buf));
}

char		**tetriTranslator(char *file, int numTetri)
{
	int		i;
	int		fd;
	char	*buf;
	char	**lst;

	i = 0;
	buf = (char *)malloc(sizeof(char) * (0));
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr("error in opening file\n");
		return (NULL);
	}
	lst = ft_2dstrnew((numTetri), 6);
	while (read(fd, buf, 21) > 0)
	{
		if (fd == -1)
		{
			ft_putstr("error in reading file\n");
			return (NULL);
		}
		ft_strcpy(lst[i++], translate(buf));
	}
	if (i != numTetri + 1)
		ft_putstr("Couldn't find all Tetrimonos.\n");
	return (lst);
}
