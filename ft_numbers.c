/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numbers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noel <noel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 14:29:36 by noel              #+#    #+#             */
/*   Updated: 2023/10/16 17:51:08 by noel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>
#include <unistd.h>

#include <unistd.h>
#include <stdlib.h>

void	show_pointeradress(size_t ptr)
{
	char	*base;
	char	*placeholder;
	int		i;

	i = 0;
	base = "0123456789abcdef";
	write (1, "0x", 2);
	if (ptr == 0)
	{
		write (1, "0", 1);
		return ;
	}
	placeholder = (char *)malloc(sizeof(ptr));
	while (ptr != 0)
	{
		placeholder[i] = base[ptr % 16];	
		ptr /= 16;
		i++;
	}
	while (i > 0)
	{
		i--;
		write (1, &placeholder[i], 1);
	}
	free(placeholder);
}

void	print_decimal_or_int(int n)
{
	char	*temp;
	int		i;

	temp = (char *)malloc(12);	
	i = 0;
	if (n == -2147483648)
		write (1, "-2147483648", 12);
	if (n == 0)
		write (1, "0", 1);
	while (n < 0)
	{
		n *= -1;
		write (1, "-", 1);
	}
	while (n > 0)
	{
		temp[i] = (n % 10) + '0';
		n /= 10;
		i++;
	}
	while (i > 0)
	{
		i--;
		write (1, &temp[i], 1);
	}
	free(temp);
}

void print_unsigned_int(unsigned int u)
{
	char	*temp;
	int		i;

	i = 0;
	if ((u & 0x80000000) != 0)
		return ;
	if (u == 0)
	{
		write (1, "0", 1);
		return ;
	}	
	temp = (char *)malloc(12);
	while (u > 0)
	{
		temp[i] = (u % 10) + '0';
		u /= 10;
		i++;
	}
	while (i > 0)
	{
		i--;
		write (1, &temp[i], 1);
	}
	free(temp);
}

void print_hex_lower(size_t num)
{
	char	*base;
	char	*

	base = "0123456789abcdef";

}

void print_hex_upper(size_t number)
{
	
}
//bei malloc maybe checken ob malloc funktioniert hat mit if(!temp)...