/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noel <noel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 15:59:46 by noel              #+#    #+#             */
/*   Updated: 2023/10/16 11:38:56 by noel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FT_PRINT_H
#define FT_PRINT_H

#include <unistd.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>

void	ft_putchar(char c);
void	show_pointeradress(size_t m);
void	print_decimal_or_int(int n);
void	print_unsigned_int(unsigned int u);
void	print_hex_lower();
void	print_hex_upper();
void	print_one_char();
void	print_str();

#endif