/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florianb <florianb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 02:55:35 by florianb          #+#    #+#             */
/*   Updated: 2024/11/13 00:00:10 by florianb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

t_flags	g_flags[4];

void	ft_putnbr_print(va_list args)
{
	int	nbr;

	nbr = va_arg(args, int);
	ft_putnbr_fd(nbr, 1);
}

static void	init_flags(void)
{
	g_flags[0].value = 's';
	g_flags[0].action = &ft_putstr_print;
	g_flags[1].value = 'd';
	g_flags[1].action = &ft_putnbr_print;
	g_flags[2].value = 'c';
	g_flags[2].action = &ft_putchar_print;
	g_flags[3].value = 'p';
	g_flags[3].action = &ft_print_pointer;
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
			flag_pos = ft_strchr("sdcp", *format);
			if (flag_pos)
			{
				j = flag_pos - "sdcp";
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
