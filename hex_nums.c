/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_nums.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noel <noel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 09:15:57 by noel              #+#    #+#             */
/*   Updated: 2023/10/22 09:16:20 by noel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void print_hex_lower(size_t num)
{
	char	*base;
	int		result[19];
	int		i;

	i = 0;
	base = "0123456789abcdef";
	if (num == 0)
	{
		write (1, "0", 1);
		return ;
	}
	while (num > 0)
	{
		result[i] = base[num % 16];
		num /= 16;
		i++;
	}
	while (i--)
		write (1, &result[i], 1);
}

void print_hex_upper(size_t num)
{
	char	*base;
	int		result[19];
	int		i;

	i = 0;
	base = "0123456789ABCDEF";
	if (num == 0)
	{
		write (1, "0", 1);
		return ;
	}
	while (num > 0)
	{
		result[i] = base[num % 16];
		num /= 16;
		i++;
	}
	while (i--)
		write (1, &result[i], 1);
}
