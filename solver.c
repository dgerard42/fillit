/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 17:29:52 by dgerard           #+#    #+#             */
/*   Updated: 2017/04/29 21:45:09 by dgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libfill.h"

char			check_alpaha(char **board)
{
	int 	i;
	int 	j;
	char	alpha;

	i = 0;
	j = 0;
	alpha = '@';
	while (board[i])
	{
		while(board[i][j])
		{
			if (ft_isalpha((int)(board[i][j])))
				alpha = board[i][j];
			j++;
		}
		i++;
		j = 0;
	}
	return (alpha);
}

void 			remove_piece(/* arguments */)
{

}

void			save_piece(char **board, int *piece, int place)
{
	char alpha;

	alpha = (check_alpha(board)) + 1;
	board[place[0]][place[1]] == alpha;
	board[(place[0] + piece[0])][(place[1] + piece[1])] == alpha;
	board[(place[0] + piece[2])][(place[1] + piece[3])] == alpha;
	board[(place[0] + piece[4])][(place[1] + piece[5])] == alpha;
}

int 			*increment_place(int *place, int *board_size)
{
	int y;
	int x;

	place[0] = y;
	place[1] = x;
	while (y < *board_size)
	{
		while (x < *board_size)
		{
			x++;
		}
	}
}

bool			check_piece(char **board, int *size int *piece, int *place)
{
	if (board[place[0]][place[1]] == '.' && place[0] < size && place[1] < size)
		if (board[(place[0] + piece[0])][(place[1] + piece[1])] == '.' && (place[0] + piece[0]) < size && (place[1] + piece[1]) < size)
			if (board[(place[0] + piece[2])][(place[1] + piece[3])] == '.' && (place[0] + piece[2]) < size && (place[1] + piece[3]) < size)
				if (board[(place[0] + piece[4])][(place[1] + piece[5])] == '.' && (place[0] + piece[4]) < size && (place[1] + piece[5]) < size)
					return (true);
	return (false);
}

bool				recurse(char** board, int *board_size, int **pieces, int *place)
{
	if (*pieces == NULL)
	{
		displayBoard(board, *board_size);
		return (true);
	}
	while (*pieces != NULL)
	{
		if (check_piece(board, *board_size, *pieces, place)
		{
			save_piece(board, *pieces, place);
			if(solver(board, board_size, *pieces+1, place))
				return (true);
			remove_piece(board, *pieces);
		}
		else
		{
			if (place[0] < *board_size || place[1] < *board_size)
			{
				place = increment_place(place, board_size);
				if(solver(board, board_size, pieces, place))
					return (true);
			}
			else
				return(false);
		}
}

char				**solver(char **board, int *boardsize, int **pieces)
{
	int *place;

	place = (int *)malloc(sizeof(int) * 2);
	place[0] = 0;
	place[1] = 0;
	while (!(recurse(board, boardsize, pieces, place)))
		*boardsize++;
	return (board);
}
