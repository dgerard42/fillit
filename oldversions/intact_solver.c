/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 17:29:52 by dgerard           #+#    #+#             */
/*   Updated: 2017/05/04 14:41:38 by dgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libfill.h"

char			check_alpha(char **board)
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
			if (ft_isalpha((int)(board[i][j])) && board[i][j] > alpha)
				alpha = board[i][j];
			j++;
		}
		i++;
		j = 0;
	}
	return (alpha);
}

void 			remove_piece(char **board)
{
	int i;
	int j;
	char alpha;

	i = 0;
	j = 0;
	alpha = check_alpha(board);
	while (board[i])
	{
		while(board[i][j])
		{
			if (board[i][j] == alpha)
				board[i][j] = '.';
			j++;
		}
		i++;
		j = 0;
	}
}

void			add_piece(char **board, int *piece, int *place)
{
	char alpha;

	alpha = check_alpha(board) + 1;
	board[place[0]][place[1]] = alpha;
	board[(place[0] + piece[0])][(place[1] + piece[1])] = alpha;
	board[(place[0] + piece[2])][(place[1] + piece[3])] = alpha;
	board[(place[0] + piece[4])][(place[1] + piece[5])] = alpha;
}

void 			increment_place(int *place, int board_size)
{
	int y;
	int x;

	y = place[0];
	x = place[1];
	if (x + 1 < board_size)
		place[1] = place[1] + 1;
	else if (x + 1 == board_size && y + 1 <= board_size)
	{
		place[0] = place[0] + 1;
		place[1] = 0;
	}
}

bool			check_piece(char **board, int size, int *piece, int *place)
{
	if (board[place[0]][place[1]] == '.' && place[0] < size && place[1] < size)
		if (board[(place[0] + piece[0])][(place[1] + piece[1])] == '.' && (place[0] + piece[0]) < size && (place[1] + piece[1]) < size)
			if (board[(place[0] + piece[2])][(place[1] + piece[3])] == '.' && (place[0] + piece[2]) < size && (place[1] + piece[3]) < size)
				if (board[(place[0] + piece[4])][(place[1] + piece[5])] == '.' && (place[0] + piece[4]) < size && (place[1] + piece[5]) < size)
					return (true);
	return (false);
}

bool				solver(char **board, int *board_size, int **pieces)
{
	int *place;

	place = (int *)malloc(sizeof(int) * 2);
	place[0] = 0;
	place[1] = 0;
	if (*pieces == NULL)
	{
		display_board(board, *board_size);
		free(place);
		return (true);
	}
	while (*pieces != NULL)
	{
		if (check_piece(board, *board_size, *pieces, place))
		{
			add_piece(board, *pieces, place);
			if (solver(board, board_size, pieces + 1))
			{
				free(place);
				return (true);
			}
			remove_piece(board);
			increment_place(place, *board_size); 	
		}
		else
		{
			increment_place(place, *board_size);
			if (place[0] >= *board_size && (check_alpha(board) + 1 == 'A' || !ft_memcmp(pieces, pieces - 1, 6))) 
			{
				*board_size = *board_size + 1;
				place[0] = 0;
				place[1] = 0;
			}
			else if (place[0] >= *board_size)
			{
				free(place);
				return (false);
			}
		}
		display_board(board, *board_size);
		ft_putchar('\n');
	}
	return (false);
}
