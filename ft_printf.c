/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noel <noel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 15:41:15 by noel              #+#    #+#             */
/*   Updated: 2023/10/15 19:15:10 by noel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include "ft_printf.h"
#include <stdlib.h>

static void check_which(char c, int *i, va_list args)
{
	char	percent;

	percent = '%';
	if (c == 'p')
		show_pointeradress(va_arg(args, size_t));
	else if (c == 'd')
		print_decimal();
	else if (c == 'i')
		print_int();
	else if (c == 'u')
		print_unsigned_int();
	else if (c == 'x')
		print_hex_lower();
	else if (c == 'X')
		print_hex_upper();
	else if(c == '%')
		write (1, &percent, 1);
	else if (c == 'c')
		print_one_char();
	else if (c == 's')
		print_str();
	else 
	{
		(*i)--;
		write (1, &percent, 1);
	}
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
			check_which(str[i], &i, args);
			i++;
		}
		else
		{
			putchar(str[i]);
			i++;
		}
	}
	va_end(args);
	return 0; //platzhalter, es sollte was anderes returnen;
}
