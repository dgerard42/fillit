/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addPiece.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esterna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 12:04:46 by esterna           #+#    #+#             */
/*   Updated: 2017/04/17 16:32:07 by dgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfill.h"
#include "libft.h"

int            nextNum(char **str)
{
	int i;
	i = ft_atoi(*str);
	while ((**str == '-' || ft_isdigit(**str)) && **str)
		(*str)++;
	while (**str == '.' && **str)
		(*str)++;
	return (i);
}

char		**addPiece(char **board, char *piece, int p_order, int *place)
{
	int r;
	int c;
	char ch;

	r = place[0];
	c = place[1];
	ch = 'A' + p_order;
	board[r][c] = ch;	
	board[r + nextNum(&piece)][c + nextNum(&piece)] = ch;
	board[r + nextNum(&piece)][c + nextNum(&piece)] = ch;
	board[r + nextNum(&piece)][c + nextNum(&piece)] = ch;
	return (board);
}
