/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addPiece.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esterna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 12:04:46 by esterna           #+#    #+#             */
/*   Updated: 2017/04/14 00:38:12 by dgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfill.h"
#include "libft.h"


int			DGnextNum(char **str)
{	
	int i = ft_atoi(*str);
	(*str) = (*str) + 2;
	return (i);
}

//i rewrote next num, I fixed add piece, but it mostly works now, butdoesn't work 
//with the number codes with negatives :(
//also theres a test main u can use (REAL_test_addPiece.c)
//also have a great weekend i <3 u

char		**addPiece(char **board, char *piece, int p_order, int *place)
{
	int r;
	int c;
	char ch;

	r = place[0];
	c = place[1];
	ch = 'A' + p_order;
	board[r][c] = ch;	
	board[r + DGnextNum(&piece)][c + DGnextNum(&piece)] = ch;
	board[r + DGnextNum(&piece)][c + DGnextNum(&piece)] = ch;
	board[r + DGnextNum(&piece)][c + DGnextNum(&piece)] = ch;
	return (board);
}
