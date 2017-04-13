/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_tetriTranslator.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 16:51:53 by dgerard           #+#    #+#             */
/*   Updated: 2017/04/13 11:48:03 by dgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				main(void)
{
	int i = -1;
	char **res;
	
	res = tetriTranslator("validfiles/allvalid", 18);
	while (i++ < 18)
		printf("%s\n", res[i]);
}
