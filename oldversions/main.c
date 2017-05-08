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

void		put_int_array(int **lst, int n, int l)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (j <= n)
	{
		if (lst[j] == NULL)
			ft_putstr("NULL");
		else
			while (i < l)
			{
				ft_putnbr(lst[j][i]);
				ft_putchar(' ');
				i++;
			}
		ft_putchar('\n');
		i = 0;
		j++;
	}
	ft_putchar('\n');
}

int			rough_sqrt(int n)
{
	int i;

	i = 1;
	while (i * i < n)
		i++;
	return (i);
}

int			main(int argc, char **argv)
{
	int 	i;
	int		numTetri;
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
	numTetri = file_checker(*argv);
	if (!numTetri)
	{
		ft_putstr("error\n");
		return (0);
	}
	board_size = (int *)malloc(sizeof(int) * 1);
	*board_size = rough_sqrt(4 * numTetri);
	pieces = translator(*argv, numTetri);
	if (!pieces || !*pieces)
	{
		ft_putstr("error\n");
		return (0);
	}
	/*put_int_array(pieces, numTetri, 6);*/	
	board = ft_2dstrnew(13, 13);
	while (++i < 13)
		ft_memset(board[i], (int)'.', 13);
	solver(board, board_size, pieces);
	free_array((void **)board, 13);
	free_array((void **)pieces, numTetri);
	return (0);
}
