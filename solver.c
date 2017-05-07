/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 17:29:52 by dgerard           #+#    #+#             */
/*   Updated: 2017/05/06 20:16:24 by dgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libfill.h"

void			increment_place(int *place, int bsize)
{
	int y;
	int x;

	y = place[0];
	x = place[1];
	if (x + 1 < bsize)
		place[1] = place[1] + 1;
	else if (x + 1 == bsize && y + 1 <= bsize)
	{
		place[0] = place[0] + 1;
		place[1] = 0;
	}
}

bool			fill_board(char **board, int **pieces, int **place, int *bsize)
{
	add_piece(board, *pieces, *place);
	if (solver(board, bsize, pieces + 1))
		return (true);
	remove_piece(board);
	increment_place(*place, *bsize);
	return (false);
}

bool			grow_board(char **board, int **place, int **pieces, int *bsize)
{
	increment_place(*place, *bsize);
	if (*place[0] >= *bsize &&
			(check_alpha(board) + 1 == 'A' ||
				!ft_memcmp(pieces, pieces - 1, 6)))
	{
		*bsize = *bsize + 1;
		(*place)[0] = 0;
		(*place)[1] = 0;
		return (true);
	}
	else if ((*place)[0] >= *bsize)
		return (false);
	return (true);
}

bool			solver(char **board, int *bsize, int **pieces)
{
	int *place;

	place = ft_intarraynew(2);
	if (*pieces == NULL)
	{
		display_board(board, *bsize);
		free(place);
		return (true);
	}
	while (*pieces != NULL)
		if (check_piece(board, *bsize, *pieces, place))
		{
			if (fill_board(board, pieces, &place, bsize))
			{
				free(place);
				return (true);
			}
		}
		else if (!(grow_board(board, &place, pieces, bsize)))
		{
			free(place);
			return (false);
		}
	return (false);
}
