/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   displayBoard.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esterna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 12:32:43 by esterna           #+#    #+#             */
/*   Updated: 2017/04/17 16:47:27 by esterna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libfill.h"

void		displayBoard(char **board, int boardSize)
{
	int c;
	int r;

	c = 0;
	r = 0;
	while (r < BOARD_SIZE && r < boardSize && board[r])
	{
		while (c < BOARD_SIZE && c < boardSize && board[r][c])
		{
			ft_putchar(board[r][c]);
			c++;
		}
		ft_putchar('\n');
		c = 0;
		r++;
	}
}
