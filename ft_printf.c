/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noel <noel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 15:41:15 by noel              #+#    #+#             */
/*   Updated: 2023/10/14 16:58:56 by noel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include "ft_printf.h"

void check_which(const char *c)
{
	if (&c == 'p')
		show_pointeradress();
}

int	printf(const char *str, ...)
{
	va_list	args;
	va_start(args, str);
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		if (str[i] == '%')
		{
			i++;
			check_which(&str[i]);
			i++;
		}
		else
			i++;
	}
	va_end(args);
	return 0; //platzhalter, es sollte was anderes returnen;
}
