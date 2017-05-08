/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 17:29:52 by dgerard           #+#    #+#             */
/*   Updated: 2017/05/07 22:26:10 by dgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libfill.h"

char			check_alpha(char **board)
{
	int		i;
	int		j;
	char	alpha;

	i = 0;
	j = 0;
	alpha = '@';
	while (board[i])
	{
		while (board[i][j])
		{
			if (ft_isalpha((int)(board[i][j])) && board[i][j] > alpha)
				alpha = board[i][j];
			j++;
		}
		i++;
		j = 0;
	}
	return (alpha);
}

static void			increment_place(int *place, int bsize)
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

static bool			fill_brd(char **brd, int **pieces, int **place, int *bsize)
{
	add_piece(brd, *pieces, *place);
	if (solver(brd, bsize, pieces + 1))
		return (true);
	remove_piece(brd);
	increment_place(*place, *bsize);
	return (false);
}

static bool			grow_brd(char **brd, int **place, int **pieces, int *bsize)
{
	increment_place(*place, *bsize);
	if (*place[0] >= *bsize &&
			(check_alpha(brd) + 1 == 'A' ||
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

bool				solver(char **brd, int *bsize, int **pieces)
{
	int *place;

	place = ft_intarraynew(2);
	if (*pieces == NULL)
	{
		display_board(brd, *bsize);
		free(place);
		return (true);
	}
	while (*pieces != NULL)
		if (check_piece(brd, *bsize, *pieces, place))
		{
			if (fill_brd(brd, pieces, &place, bsize))
			{
				free(place);
				return (true);
			}
		}
		else if (!(grow_brd(brd, &place, pieces, bsize)))
		{
			free(place);
			return (false);
		}
	return (false);
}
