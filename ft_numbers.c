/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numbers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabia <nsabia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 14:29:36 by noel              #+#    #+#             */
/*   Updated: 2023/10/24 18:29:52 by nsabia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>
#include <unistd.h>

int	show_pointeradress(size_t ptr, int *ptr_len)
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
		return ((*ptr_len)++);
	}
	placeholder = (char *)malloc(sizeof(ptr));
	while (ptr != 0)
	{
		placeholder[i++] = base[ptr % 16];
		ptr /= 16;
	}
	while (i--)
	{
		write (1, &placeholder[i], 1);
		(*ptr_len)++;
	}
	free(placeholder);
	return (*ptr_len);
}

static int	print_dec_or_int_helper(int n, int *ptr_len)
{
	if (n == -2147483648)
	{
		write (1, "-2147483648", 12);
		return ((*ptr_len) + 12);
	}
	if (n == 0)
	{
		write (1, "0", 1);
		(*ptr_len)++;
		return (*ptr_len);
	}
	return (*ptr_len);
}

int	print_decimal_or_int(int n, int *ptr_len)
{
	char	*temp;
	int		i;

	temp = (char *)malloc(12);
	i = 0;
	print_dec_or_int_helper(n, ptr_len);
	while (n < 0 && !(n == -2147483648))
	{
		n *= -1;
		write (1, "-", 1);
		(*ptr_len)++;
	}
	while (n > 0 && !(n == -2147483648))
	{
		temp[i++] = (n % 10) + '0';
		n /= 10;
	}
	while (i--)
	{
		write (1, &temp[i], 1);
		(*ptr_len)++;
	}
	free(temp);
	return (*ptr_len);
}

void	print_unsigned_int(unsigned int u, int *ptr_len)
{
	char	*temp;
	int		i;

	i = 0;
	if (u < 0)
		u -= 4294967295;
	if (u == 0)
	{
		write (1, "0", 1);
		(*ptr_len)++;
	}
	temp = (char *)malloc(12);
	while (u > 0)
	{
		temp[i++] = (u % 10) + '0';
		u /= 10;
	}
	while (i--)
	{
		write (1, &temp[i], 1);
		(*ptr_len)++;
	}
	free(temp);
}
