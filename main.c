/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esterna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 12:33:45 by esterna           #+#    #+#             */
/*   Updated: 2017/05/03 19:46:07 by esterna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libfill.h"

void		free_array(void **lst, int n)
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

int			main(int argc, char **argv)
{
	int 	i;
	int		num_tetri;
	int		**pieces;
	char	**board;
	int		*board_size;

	i = -1;
	if (argc != 2)
	{
		ft_putstr("usage:\nyou need to input fillit test files\n");
		return (0);
	}
	argv++;
	num_tetri = file_checker(*argv);
	if (!num_tetri)
	{
		ft_putstr("error\n");
		return (0);
	}
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
