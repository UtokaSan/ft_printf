/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florianb <florianb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 22:46:13 by florianb          #+#    #+#             */
/*   Updated: 2024/11/13 00:07:03 by florianb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

void	ft_putchar_print(va_list args)
{
	char	c;

	c = va_arg(args, int);
	write(1, &c, 1);
}

void	ft_putnbr_hex(unsigned long nb)
{
	if (nb >= 16)
	{
		ft_putnbr_hex(nb / 16);
		ft_putnbr_hex(nb % 16);
	}
	else
	{
		if (nb < 10)
			ft_putchar_fd(nb + '0', 1);
		else
			ft_putchar_fd(nb - 10 + 'a', 1);
	}
}

void	ft_print_pointer(va_list args)
{
	void	*ptr;

	ptr = va_arg(args, void *);
	write(1, "0x", 2);
	ft_putnbr_hex((unsigned long)ptr);
}

void	ft_putstr_print(va_list args)
{
	const char	*str;

	str = va_arg(args, const char *);
	write(1, str, ft_strlen(str));
}
