/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   REAL_test_addPiece.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 12:19:00 by dgerard           #+#    #+#             */
/*   Updated: 2017/04/17 16:11:58 by dgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfill.h"
#include "libft.h"

/**/
int			main(void)
{
	int		i = -1;
	int 	j = 0;
	char 	**board;
	int		p_order = 0;
	int place[2] = {4, 4};
	char *pieces [19] = {
		"1.0.2.0.2.1", "0.1.0.2.1.0", "0.1.1.1.2.1", "1.-2.1.-1.1.0",
		"1.0.2.-1.2.0", "1.0.1.1.1.2", "0.1.1.0.2.0", "0.1.0.2.1.2",
		"1.-1.1.0.1.1", "1.0.1.1.2.0", "0.1.0.2.1.1", "1.-1.1.0.2.0",
		"0.1.1.0.1.1", "0.1.1.1.1.2", "1.0.1.-1.2.-1", "0.1.1.0.1.-1",
		"1.0.1.1.2.1", "1.0.2.0.3.0", "0.1.0.2.0.3"
	};
	

 	board = ft_2dstrnew(BOARD_SIZE, BOARD_SIZE);
	while (j++ < 18)
	{	
		while (i++ < BOARD_SIZE)
			ft_memset(board[i], (int)'.', BOARD_SIZE);
		i = -1;
		printf("_____________test%d_______piece%s_____________\n", j, pieces[j]);
		addPiece(board, pieces[j], p_order, place);
		displayBoard(board, 13);
	}
}
/**/

/*
int			main(void)
{
	int		i = -1;
	char 	**board;
	int		p_order = 0;
	int place[2] = {3, 3};
	char	*piece = "1.-2.1.-1.1.0";

	board = ft_2dstrnew(BOARD_SIZE, BOARD_SIZE);
	while (i++ < BOARD_SIZE)
		ft_memset(board[i], (int)'.', BOARD_SIZE);
	addPiece(board, piece, p_order, place);
	displayBoard(board, 13);
}
*/
