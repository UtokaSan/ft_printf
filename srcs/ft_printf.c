/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florianb <florianb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 02:55:35 by florianb          #+#    #+#             */
/*   Updated: 2024/11/12 21:55:58 by florianb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include "libft.h"

void ft_putstr_print(va_list args) {
    const char *str = va_arg(args, const char *);
    write(1, str, ft_strlen(str)); // Utilisez write ou une fonction similaire
}

void ft_putnbr_print(va_list args) {
    int nbr = va_arg(args, int);
    // Implémentez la logique pour afficher un nombre ici
	printf("%d", nbr);
}

void ft_putchar_print(va_list args) {
    char c = (char)va_arg(args, int); // Les caractères sont passés comme int
    write(1, &c, 1);
}

static void	init_flags(void)
{
	g_flags[0].value = 's';
	g_flags[0].action = &ft_putstr_print;
	g_flags[1].value = 'd';
	g_flags[1].action = &ft_putnbr_print;
	g_flags[2].value = 'c';
	g_flags[2].action = &ft_putchar_print;
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
			flag_pos = ft_strchr("sdc", *format);
			if (flag_pos)
			{
				j = flag_pos - "sdc";
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