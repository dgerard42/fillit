/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esterna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 12:33:45 by esterna           #+#    #+#             */
/*   Updated: 2017/05/10 20:43:57 by dgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libfill.h"

static int			rough_sqrt(int n)
{
	int i;

	i = 1;
	while (i * i < n)
		i++;
	return (i);
}

void				display_board(char **board, int board_size)
{
	int c;
	int r;

	c = 0;
	r = 0;
	while (r < 13 && r < board_size && board[r])
	{
		while (c < 13 && c < board_size && board[r][c])
		{
			ft_putchar(board[r][c]);
			c++;
		}
		ft_putchar('\n');
		c = 0;
		r++;
	}
}

void				free_array(void **lst, int n)
{
	int i;
	int **tmp;

	i = 0;
	tmp = (int **)lst;
	while (i < n)
	{
		free(tmp[i]);
		i++;
	}
	free(lst);
}

static int			check_inputs(int usage, char *filename)
{
	int num_tetri;

	if (usage != 2)
	{
		ft_putstr("usage:\nyou need to input fillit test files\n");
		return (0);
	}
	num_tetri = file_checker(filename);
	if (!num_tetri)
	{
		ft_putstr("error\n");
		return (0);
	}
	return (num_tetri);
}

int					main(int argc, char **argv)
{
	int		i;
	int		num_tetri;
	int		**pieces;
	char	**board;
	int		*board_size;

	i = -1;
	num_tetri = check_inputs(argc, *++argv);
	if (!num_tetri)
		return (0);
	pieces = translator(*argv, num_tetri);
	if (!pieces || !*pieces)
	{
		ft_putstr("error\n");
		return (0);
	}
	board = ft_2dstrnew(13, 13);
	while (++i < 13)
		ft_memset(board[i], (int)'.', 13);
	board_size = (int *)malloc(sizeof(int) * 1);
	*board_size = rough_sqrt(4 * num_tetri);
	solver(board, board_size, pieces);
	free_array((void **)board, 13);
	free_array((void **)pieces, num_tetri);
	return (0);
}
