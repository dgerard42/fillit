/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_pieceAdd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esterna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/09 15:39:23 by esterna           #+#    #+#             */
/*   Updated: 2017/04/13 11:16:53 by dgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <xlocale.h>
#include <ctype.h>
#include "libft.h"

#define BOARD_SIZE 13

char		**makeBoard()
{
	int i;
	char **board;

	i = 0;
	board = (char **)malloc(sizeof(char *) * (BOARD_SIZE + 1));
	board[BOARD_SIZE] = NULL;
	while (i < BOARD_SIZE)
	{
		board[i] = (char *)malloc(sizeof(char) * (BOARD_SIZE + 1));
		board[i][BOARD_SIZE] = '\0';
		memset(board[i], (int)'.', BOARD_SIZE);
		i++;
	}
	return (board);
}

int			nextNum(char **str)
{
	while (isdigit(**str) && **str)
		(*str)++;
	while (!isdigit(**str) && **str)
		(*str)++;
	return (atoi(*str));
}

bool				pieceFits(char **board, int boardSize, char *piece, int *place)
{
	int r;
	int c;
	int t1;
	int t2;
	char *p_tmp;

	r = 0;
	c = 0;
	p_tmp = piece;
	if (!*piece || !piece)
		return (false);
	while (c < boardSize && board[r] && r < boardSize)
	{
		while (c < boardSize && board[r][c] != '.' && board[r][c])
			c++;
		if (c >= boardSize || !board[r][c])
		{
			c = 0;
			r++;
		}
		else if ((t1 = r + atoi(p_tmp)) < boardSize && (t2 = c + nextNum(&p_tmp)) < boardSize 
				&& t1 >= 0 && t2 >= 0 && board[t1][t2] == '.'
				&&(t1 = r + nextNum(&p_tmp)) < boardSize && (t2 = c + nextNum(&p_tmp)) < boardSize 
				&& t1 >= 0 && t2 >= 0 && board[t1][t2] == '.'
				&&(t1 = r + nextNum(&p_tmp)) < boardSize && (t2 = c + nextNum(&p_tmp)) < boardSize 
				&& t1 >= 0 && t2 >= 0 && board[t1][t2] == '.')
		{

			place[0] = r;
			place[1] = c;
			return (true);
		}
		else
			c++;
	}
	place[0] = 0;
	place[1] = 0;
	return (false);
}

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
		write(1, "\n", 1);
		c = 0;
		r++;
	}
}



int main()
{
	int *place = (int *)malloc(sizeof(int) * 2);
	int i = 0;
	char **tetris = (char **)malloc(sizeof(char *) * 17);
	tetris[16] = "0.1.1.-1.1.0";
	tetris[15] = "0.1.1.0.2.0";
	tetris[14] = "0.1.1.1.1.2";
	tetris[13] = "0.1.1.1.2.1";
	tetris[12] = "0.1.1.0.1.1";
	tetris[11] = "0.1.0.2.1.1";
	tetris[10] = "0.1.0.2.1.2";
	tetris[9] = "0.1.0.2.1.0";
	tetris[8] = "0.1.0.2.0.3";
	tetris[7] = "1.0.1.1.2.1";
	tetris[6] = "1.-1.1.0.2.-1";
	tetris[5] = "1.-1.1.0.1.1";
	tetris[4] = "1.-1.1.0.2.0";
	tetris[3] = "1.0.1.1.2.0";
	tetris[2] = "1.0.2.-1.2.0";
	tetris[1] = "1.0.2.0.2.1";
	tetris[0] = "1.0.2.0.3.0";
	while (i < 17)
	{
		if (!strcmp(tetris[i], "1.4.5"))
	 		displayBoard(addPiece(makeBoard(), 4, tetris[i], i), 5);
	 	else if (!strcmp(tetris[i], "4.8.12") || !ft_strcmp(tetris[i], "1.2.3"))
	 		displayBoard(addPiece(makeBoard(), 4, tetris[i], i), 5);
	 	else
	 		displayBoard(addPiece(makeBoard(), 4, tetris[i], i), 5);
	 		i++;
	 		printf("\n");
	}
	while (i < 17)
	{
		printf("%d : %d\n", i, pieceFits(makeBoard(), 2, tetris[i], place));
		i++;
	}
	return 0;
}

