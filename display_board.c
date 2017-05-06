/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_board.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esterna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 12:32:43 by esterna           #+#    #+#             */
/*   Updated: 2017/05/05 17:58:53 by dgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libfill.h"

void		display_board(char **board, int board_size)
{
	int c;
	int r;

	c = 0;
	r = 0;
	while (r < 13 && r < board_size && board[r])
	{
		while (c < 13 && c < board_size && board[r][c])
		{
			ft_putchar(board[r][c]);
			c++;
		}
		ft_putchar('\n');
		c = 0;
		r++;
	}
}
