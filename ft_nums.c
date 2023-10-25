/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nums.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabia <nsabia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 14:29:36 by noel              #+#    #+#             */
/*   Updated: 2023/10/25 18:56:35 by nsabia           ###   ########.fr       */
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
	if (write (1, "0x", 2) == -1)
		return ((*ptr_len) = -1);
	(*ptr_len) += 2;
	if (ptr == 0)
	{
		if (write (1, "0", 1) == -1)
			return ((*ptr_len) = -1);
		(*ptr_len)++;
	}
	placeholder = (char *)malloc(16);
	if (!placeholder)
		return ((*ptr_len) = -1);
	while (ptr != 0)
	{
		placeholder[i++] = base[ptr % 16];
		ptr /= 16;
	}
	while (i--)
	{
		if (write (1, &placeholder[i], 1) == -1)
			return ((*ptr_len) = -1);
		(*ptr_len)++;
	}
	free(placeholder);
	return (*ptr_len);
}

static int	print_dec_or_int_helper(int n, int *ptr_len)
{
	if (n == -2147483648)
	{
		if (write (1, "-2147483648", 11) == -1)
			return ((*ptr_len) = -1);
		return ((*ptr_len) += 11);
	}
	if (n == 0)
	{
		if (write (1, "0", 1) == -1)
			return ((*ptr_len) = -1);
		(*ptr_len)++;
	}
	return (*ptr_len);
}

int	print_decimal_or_int(int n, int *ptr_len)
{
	char	*temp;
	int		i;

	temp = (char *)malloc(12);
	if (!temp)
		return ((*ptr_len) = -1);
	i = 0;
	print_dec_or_int_helper(n, ptr_len);
	while (n < 0 && !(n == -2147483648))
	{
		n *= -1;
		if (write (1, "-", 1) == -1)
		{
			free (temp);
			return ((*ptr_len) = -1);
		}
		(*ptr_len)++;
	}
	while (n > 0 && !(n == -2147483648))
	{
		temp[i++] = (n % 10) + '0';
		n /= 10;
	}
	while (i--)
	{
		if (write (1, &temp[i], 1) == -1)
		{
			free (temp);
			return ((*ptr_len) = -1);
		}
		(*ptr_len)++;
	}
	free(temp);
	return (*ptr_len);
}

int	print_unsigned_int(unsigned int u, int *ptr_len)
{
	char	*temp;
	int		i;

	i = 0;
	if (u < 0)
		u -= 4294967295;
	if (u == 0)
	{
		if (write (1, "0", 1) == -1)
			return ((*ptr_len) = -1);
		(*ptr_len)++;
	}
	temp = (char *)malloc(12);
	if (!temp)
		return ((*ptr_len) = -1);
	while (u > 0)
	{
		temp[i++] = (u % 10) + '0';
		u /= 10;
	}
	while (i--)
	{
		if (write (1, &temp[i], 1) == -1)
		{
			free(temp);
			return ((*ptr_len) = -1);
		}
		(*ptr_len)++;
	}
	free(temp);
	return (*ptr_len);
}
 