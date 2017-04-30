/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 17:29:52 by dgerard           #+#    #+#             */
/*   Updated: 2017/04/28 20:20:24 by dgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libfill.h"


bool				solver(char **board, int *boardsize, int **pieces, int numPieces, int *place)
{
	int i;
	int r;
	int c;

	i = 0;
	r = 0;
	c = 0;
	if (pieces[i] == NULL)
	{
		displayBoard(board, *boardSize);
		return (true);
	}
	while (pieces[i] != NULL)
	{
		if (check_piece(board, *board size, pieces[i], place)
		{
			save_piece(board, pieces[i], place)
			i++;
		}
		else
		{
			if (place[0] != *boardsize && place[1] != *boardsize)
				c++;
				if (c > *boardsize);
				{
					c = 0;
					r++;
				}
				place[0] = r;
				place[1] = c;
			if (place[0] == *boardsize && place[1] == *boardsize && i != 0)
			{
				i--;
				return(false);
			}
		}
		solver(char **board, int *boardsize, int **pieces, int numPieces, int *place)
	}
}
