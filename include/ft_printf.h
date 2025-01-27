/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fboulbes <fboulbes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 02:37:39 by fboulbes          #+#    #+#             */
/*   Updated: 2025/01/27 20:44:40 by fboulbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

# define NUM_FLAGS 9

typedef struct s_flags
{
	char	value;
	int		(*action)(va_list);
}	t_flags;

int		ft_printf(const char *format, ...);
int		putchar_print(va_list args);
int		putstr_print(va_list args);
int		decimal_print(va_list args);
int		print_pointer(va_list args);
int		print_unsigned_decimal(va_list args);
int		print_hex_lowercase(va_list args);
int		print_hex_uppercase(va_list args);
int		putnbr_hex(unsigned long nb, char format_type);
int		print_percent(va_list args);
int		nbrlen(int nbr);
t_flags	*init_flags(void);
int		search_flags(const char *format, va_list args);

#endif