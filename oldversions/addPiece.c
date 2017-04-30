/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addPiece.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esterna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 12:04:46 by esterna           #+#    #+#             */
/*   Updated: 2017/04/20 20:11:44 by esterna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfill.h"
#include "libft.h"

char		**addPiece(char **board, char *piece, int p_order, int *place)
{
	int r;
	int c;
	char ch;

	r = place[0];
	c = place[1];
	ch = 'A' + p_order;
	*piece = 'P';
	while (*piece == 'P' || *piece == '.')
		piece++;
	board[r][c] = ch;
	r = r + nextNum(&piece);
	board[r][c = c + nextNum(&piece)] = ch;
	r = r + nextNum(&piece);
	board[r][c = c + nextNum(&piece)] = ch;
	r = r + nextNum(&piece);
	board[r][c = c + nextNum(&piece)] = ch;
	return (board);
}
