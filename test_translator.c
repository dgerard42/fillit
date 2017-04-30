/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_translator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 16:51:53 by dgerard           #+#    #+#             */
/*   Updated: 2017/04/29 17:48:48 by dgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfill.h"
#include "libft.h"
#include <stdio.h>

/*
char			**tetri_translator(char *file, int numTetri);

int				main(void)
{
	int i = -1;
	char **res;
	
	res = tetri_translator("validfiles/allvalid", 19);
	while (i++ < 18)
		printf("%s\n", res[i]);
}
*/

/**/
int				main(void)
{
	int		**res;
	size_t	y = 0;
	int		x = 0;
	size_t	tetrominoes = 19;

	res = translator("validfiles/allvalid", tetrominoes);
	while (y < tetrominoes)
	{
		while (x < 6)
		{
			printf("%d", res[y][x]);
			x++;
		}
		printf("\n");
		y++;
		x = 0;
	}
}
/**/
