/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esterna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 12:33:45 by esterna           #+#    #+#             */
/*   Updated: 2017/04/28 17:48:35 by dgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libfill.h"

int			main(int argc, char **argv)
{
	int 	i;
	int		numTetri;
	int		*place;
	char	**pieces;
	char	**board;
	int		*boardSize;

	i = -1;
	boardSize = (int *)malloc(sizeof(int) * 1);
	*boardSize = 2;
	if (argc != 2)
	{
		ft_putstr("usage: \nfillit file\n");
		return (0);
	}
	argv++;
	numTetri = file_checker(*argv);
	if (!numTetri)
	{
		ft_putstr("error in file_checker\n");
		return (0);
	}
	pieces = tetriTranslator(*argv, numTetri);
	if (!pieces || !*pieces)
	{
		ft_putstr("error in translator\n");
		return (0);
	}
	int n = 0;
	while (n < numTetri)
	{
		ft_putstr(pieces[n]);
		ft_putchar('\n');
		n++;
	}
	board = ft_2dstrnew(13, 13); 
	while (++i < 13)
		ft_memset(board[i], (int)'.', 13);
	place = (int *)malloc(sizeof(int) * 2);
	solve(board, boardSize, pieces, numTetri, place);
	i = 0;
	while (i < 13)
	{
		free(board[i]);
		i++;
	}
	free(board);
	i = 0;
	while (i < numTetri)
	{
		free(pieces[i]);
		i++;
	}
	free(place);
	free(boardSize);
	return (0);
}
