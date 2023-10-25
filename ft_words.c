/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_words.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabia <nsabia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 15:41:18 by noel              #+#    #+#             */
/*   Updated: 2023/10/25 12:46:02 by nsabia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

int	ft_putchar(char c, int *ptr_len)
{
	write (1, &c, 1);
	return ((*ptr_len)++);
}

int	print_one_char(int c, int *ptr_len)
{
	write (1, &c, 1);
	return ((*ptr_len)++);
}

void	print_str(char *str, int *ptr_len)
{
	int	i;

	i = 0;
	if (str == 0)
	{
		write (1, "(null)", 6);
		(*ptr_len) += 6;
		return ;
	}
	while (str[i] != 0)
	{
		write (1, &str[i], 1);
		i++;
		(*ptr_len)++;
	}
}
