/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florianb <florianb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 02:37:39 by florianb          #+#    #+#             */
/*   Updated: 2024/11/13 14:01:44 by florianb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

# define NUM_FLAGS 9

int		ft_printf(const char *format, ...);
void	ft_putchar_print(va_list args);
void	ft_putstr_print(va_list args);
void	ft_decimal_print(va_list args);
void	ft_print_pointer(va_list args);
void	ft_print_unsigned_decimal(va_list args);
void	ft_print_hex_lowercase(va_list args);
void	ft_print_hex_uppercase(va_list args);
void	ft_putnbr_hex(unsigned long nb, char format_type);
void	ft_print_percent(va_list args);
typedef struct s_flags
{
	char	value;
	void	(*action)(va_list);
}	t_flags;

extern t_flags	g_flags[NUM_FLAGS];

#endif