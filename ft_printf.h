/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabia <nsabia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 15:59:46 by noel              #+#    #+#             */
/*   Updated: 2023/10/24 17:43:28 by nsabia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdlib.h>

int		ft_putchar(char c, int *ptr_len);
int		show_pointeradress(size_t m, int *ptr_len);
int		print_decimal_or_int(int n, int *ptr_len);
void	print_unsigned_int(unsigned int u, int *ptr_len);
int		print_hex_lower(size_t num, int *ptr_len);
int		print_hex_upper(size_t num, int *ptr_len);
int		print_one_char(int c, int *ptr_len);
void	print_str(char *str, int *ptr_len);

#endif
