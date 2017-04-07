/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_filechecker.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 21:29:26 by dgerard           #+#    #+#             */
/*   Updated: 2017/04/06 22:06:13 by dgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			main(void)
{
	int i = -1;
	int res = 42;
	char *files[10] = {
		"invalid00", "invalid01", "invalid02", "invalid03"
			"invalid04", "invalid05", "invalid06", "invalid07",
		"invalid08", "allvalid"
	};
	while(i++ < 10)
	{
		res = filechecker(files[i]);
		printf("test #%d == %d\n", i, res);
	}
}
