/* ************************************************************************** */
/*                                                        :::      ::::::::   */
/*   test_filechecker.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 21:29:26 by dgerard           #+#    #+#             */
/*   Updated: 2017/04/10 17:55:24 by dgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			main(void)
{
	int i = -1;
	int res = 42;
	char *files[20] = {
			"jkvalid", "allvalid+nl", "allvalid", 
		"valid00","invalid02", "invalid03", "invalid04","invalid05", 
			"invalid06", "invalid07", "invalid08", "invalid09", 
		"invalid10", "invalid11", "invalid12", "valid01",
			"valid02", "valid03", "valid04", "invalid13"
	};
	while(i++ < 19)
	{
		res = filechecker(files[i]);
		printf("---------^^----|||test %s == %d|||----^^----------\n", files[i], res);
	}
}
