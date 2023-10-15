/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numbers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noel <noel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 14:29:36 by noel              #+#    #+#             */
/*   Updated: 2023/10/15 19:45:41 by noel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>
#include <unistd.h>

void	show_pointeradress(size_t m)
{
	char	*base;

	base = "0123456789abcdef";
	write (1, "0x", 2);
	
}

void	print_decimal(int n)
{
	
}