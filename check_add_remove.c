/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_add_remove.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/06 19:24:51 by dgerard           #+#    #+#             */
/*   Updated: 2017/05/07 20:43:42 by dgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libfill.h"

void			remove_piece(char **board)
{
	int		i;
	int		j;
	char	alpha;

	i = 0;
	j = 0;
	alpha = check_alpha(board);
	while (board[i])
	{
		while (board[i][j])
		{
			if (board[i][j] == alpha)
				board[i][j] = '.';
			j++;
		}
		i++;
		j = 0;
	}
}

void			add_piece(char **board, int *piece, int *plc)
{
	char alpha;

	alpha = check_alpha(board) + 1;
	board[plc[0]][plc[1]] = alpha;
	board[(plc[0] + piece[0])][(plc[1] + piece[1])] = alpha;
	board[(plc[0] + piece[2])][(plc[1] + piece[3])] = alpha;
	board[(plc[0] + piece[4])][(plc[1] + piece[5])] = alpha;
}

bool			check_piece(char **board, int sz, int *piece, int *plc)
{
	if (board[plc[0]][plc[1]] == '.' && plc[0] < sz && plc[1] < sz)
		if (board[(plc[0] + piece[0])][(plc[1] + piece[1])] == '.' &&
				(plc[0] + piece[0]) < sz && (plc[1] + piece[1]) < sz)
			if (board[(plc[0] + piece[2])][(plc[1] + piece[3])] == '.' &&
					(plc[0] + piece[2]) < sz && (plc[1] + piece[3]) < sz)
				if (board[(plc[0] + piece[4])][(plc[1] + piece[5])] == '.' &&
						(plc[0] + piece[4]) < sz && (plc[1] + piece[5]) < sz)
					return (true);
	return (false);
}
