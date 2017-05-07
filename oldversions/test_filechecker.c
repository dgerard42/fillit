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
	char *files[23] = {
			"validfiles/jkvalid", "validfiles/allvalid+nl", "validfiles/allvalid", 
		"validfiles/valid00","invalidfiles/invalid02", "invalidfiles/invalid03", "invalidfiles/invalid04","invalidfiles/invalid05", 
			"invalidfiles/invalid06", "invalidfiles/invalid07", "invalidfiles/invalid08", "invalidfiles/invalid09", 
		"invalidfiles/invalid10", "invalidfiles/invalid11", "invalidfiles/invalid12", "validfiles/valid01",
			"validfiles/valid02", "validfiles/valid03", "validfiles/valid04", "invalidfiles/invalid13",
		"invalidfiles/invalid14", "invalidfiles/invalid15", "invalidfiles/invalid16"
	};
	while(i++ < 22)
	{
		res = filechecker(files[i]);
		printf("---------^^----|||test %s == %d|||----^^----------\n", files[i], res);
	}
}
