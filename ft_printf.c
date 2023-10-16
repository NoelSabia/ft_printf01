/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noel <noel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 15:41:15 by noel              #+#    #+#             */
/*   Updated: 2023/10/16 17:50:39 by noel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include "ft_printf.h"
#include <stdlib.h>

static void check_which(char c, int *i, va_list args)
{
	if (c == 'p')
		show_pointeradress(va_arg(args, size_t));
	else if (c == 'd' || c == 'i')
		print_decimal_or_int(va_arg(args, int));
	else if (c == 'u')
		print_unsigned_int(va_arg(args, unsigned int));
	else if (c == 'x')
		print_hex_lower(va_arg(args, size_t));
	else if (c == 'X')
		print_hex_upper(va_arg(args, size_t));
	else if(c == '%')
		write (1, "%%", 2);
	else if (c == 'c')
		print_one_char(va_arg(args, int));
	else if (c == 's')
		print_str(va_arg(args, char *));
	else 
	{
		(*i)--;
		write (1, "%", 1);
	}
}

int	ft_printf(const char *str, ...)
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
			ft_putchar(str[i]);
			i++;
		}
	}
	va_end(args);
	return 0; //hier sollte returnt werden, wie wiele zeichen kopiert wurden;
}

int main()
{
	ft_printf("hallo: %s \n", "hi whats upp");
}