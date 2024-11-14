/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florianb <florianb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 02:37:39 by florianb          #+#    #+#             */
/*   Updated: 2024/11/14 22:55:36 by florianb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

# define NUM_FLAGS 9

int		ft_printf(const char *format, ...);
int		ft_putchar_print(va_list args);
int		ft_putstr_print(va_list args);
int		ft_decimal_print(va_list args);
int		ft_print_pointer(va_list args);
int		ft_print_unsigned_decimal(va_list args);
int		ft_print_hex_lowercase(va_list args);
int		ft_print_hex_uppercase(va_list args);
void	ft_putnbr_hex(unsigned long nb, char format_type);
int		ft_print_percent(va_list args);
int		ft_nbrlen(int nbr);

typedef struct s_flags
{
	char	value;
	int		(*action)(va_list);
}	t_flags;

extern t_flags	g_flags[NUM_FLAGS];

#endif