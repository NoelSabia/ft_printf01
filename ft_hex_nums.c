/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_nums.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabia <nsabia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 09:15:57 by noel              #+#    #+#             */
/*   Updated: 2023/10/24 14:27:59 by nsabia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

int	print_hex_lower(size_t num, int *ptr_len)
{
	char	*base;
	int		result[19];
	int		i;

	i = 0;
	base = "0123456789abcdef";
	if (num == 0)
	{
		write (1, "0", 1);
		return ((*ptr_len)++);
	}
	while (num > 0)
	{
		result[i] = base[num % 16];
		num /= 16;
		i++;
	}
	while (i--)
	{
		write (1, &result[i], 1);
		(*ptr_len)++;
	}
	return (*ptr_len);
}

int	print_hex_upper(size_t num, int *ptr_len)
{
	char	*base;
	int		result[19];
	int		i;

	i = 0;
	base = "0123456789ABCDEF";
	if (num == 0)
	{
		write (1, "0", 1);
		return ((*ptr_len)++);
	}
	while (num > 0)
	{
		result[i] = base[num % 16];
		num /= 16;
		i++;
	}
	while (i--)
	{
		write (1, &result[i], 1);
		(*ptr_len)++;
	}
	return (*ptr_len);
}
