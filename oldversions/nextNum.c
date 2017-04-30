/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nextNum.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esterna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 16:37:27 by esterna           #+#    #+#             */
/*   Updated: 2017/04/17 18:25:52 by esterna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfill.h"
#include "libft.h"

int            nextNum(char **str)
{
	int i;

	i = ft_atoi(*str);
	while ((**str == '-' || ft_isdigit(**str)) && **str)
		(*str)++;
	while (**str == '.' && **str)
		(*str)++;
	return (i);
}
