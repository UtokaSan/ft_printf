/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fboulbes <fboulbes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 02:55:35 by fboulbes          #+#    #+#             */
/*   Updated: 2024/11/20 17:45:49 by fboulbes         ###   ########.fr       */
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

int	ft_nbrlen(int nbr)
{
	int	len;

	len = 0;
	if (nbr == 0)
		return (1);
	if (nbr == -2147483648)
		return (11);
	if (nbr < 0)
	{
		len++;
		nbr *= -1;
	}
	while (nbr > 0)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}

static void	init_flags(void)
{
	static char	specifiers[] = "sdcpiuxX%";
	static int	(*actions[])(va_list) = {
		ft_putstr_print,
		ft_decimal_print,
		ft_putchar_print,
		ft_print_pointer,
		ft_decimal_print,
		ft_print_unsigned_decimal,
		ft_print_hex_lowercase,
		ft_print_hex_uppercase,
		ft_print_percent
	};
	size_t		i;

	i = 0;
	while (i < NUM_FLAGS)
	{
		g_flags[i].value = specifiers[i];
		g_flags[i].action = actions[i];
		i++;
	}
}

static int	search_flags(const char *format, va_list args)
{
	size_t	j;
	char	*flag_pos;
	size_t	count;

	j = 0;
	count = 0;
	while (*format)
	{
		if (*format == '%' && *(++format))
		{
			flag_pos = ft_strchr("sdcpiuxX%", *format);
			if (flag_pos)
			{
				j = flag_pos - "sdcpiuxX%";
				count += g_flags[j].action(args);
			}
			else
				count += write(1, "%", 1) + write(1, format, 1);
		}
		else
			count += write(1, format, 1);
		format++;
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	va_start(args, format);
	init_flags();
	count = search_flags(format, args);
	va_end(args);
	return (count);
}
