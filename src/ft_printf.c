/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florianb <florianb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 02:55:35 by florianb          #+#    #+#             */
/*   Updated: 2024/11/13 14:00:17 by florianb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

t_flags	g_flags[NUM_FLAGS];

void	ft_putnbr_print(va_list args)
{
	int	nbr;

	nbr = va_arg(args, int);
	ft_putnbr_fd(nbr, 1);
}

static void	init_flags(void)
{
	g_flags[0] = (t_flags){'s', &ft_putstr_print};
	g_flags[1] = (t_flags){'d', &ft_decimal_print};
	g_flags[2] = (t_flags){'c', &ft_putchar_print};
	g_flags[3] = (t_flags){'p', &ft_print_pointer};
	g_flags[4] = (t_flags){'i', &ft_decimal_print};
	g_flags[5] = (t_flags){'u', &ft_print_unsigned_decimal};
	g_flags[6] = (t_flags){'x', &ft_print_hex_lowercase};
	g_flags[7] = (t_flags){'X', &ft_print_hex_uppercase};
	g_flags[8] = (t_flags){'%', &ft_print_percent};
}

static void	search_flags(const char *format, va_list args)
{
	size_t	j;
	char	*flag_pos;

	j = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			flag_pos = ft_strchr("sdcpiuxX%", *format);
			if (flag_pos)
			{
				j = flag_pos - "sdcpiuxX%";
				g_flags[j].action(args);
			}
			else
			{
				ft_putchar_fd('%', 1);
				ft_putchar_fd(*format, 1);
			}
		}
		else
			ft_putchar_fd(*format, 1);
		format++;
	}
}

int	ft_printf(const char *format, ...)
{
	int		count;
	va_list	args;

	count = 0;
	va_start(args, format);
	init_flags();
	search_flags(format, args);
	va_end(args);
	return (count);
}
