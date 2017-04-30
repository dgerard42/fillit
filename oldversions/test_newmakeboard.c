/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_newmakeboard.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 12:41:05 by dgerard           #+#    #+#             */
/*   Updated: 2017/04/13 16:15:58 by dgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libfill.h"

char			**makeBoardmini()
{
	char **board;
	int i;

	i = -1;
	board = ft_2dstrnew(BOARD_SIZE, BOARD_SIZE);
	while (i++ < BOARD_SIZE)
		ft_memset(board[i], (int)'.', BOARD_SIZE);
	return (board);
}

int		main(void)
{
	char **board;

	board = makeBoardmini();
	displayBoard(board, BOARD_SIZE);
}
