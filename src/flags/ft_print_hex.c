/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florianb <florianb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 11:37:49 by florianb          #+#    #+#             */
/*   Updated: 2024/11/14 22:47:48 by florianb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	ft_putnbr_hex(unsigned long nb, char format_type)
{
	if (nb >= 16)
	{
		ft_putnbr_hex(nb / 16, format_type);
		ft_putnbr_hex(nb % 16, format_type);
	}
	else
	{
		if (nb < 10)
			ft_putchar_fd(nb + '0', 1);
		else
			ft_putchar_fd(nb - 10 + format_type, 1);
	}
}

int	ft_print_hex_lowercase(va_list args)
{
	unsigned int	nbr;

	nbr = va_arg(args, unsigned int);
	ft_putnbr_hex(nbr, 'a');
	return (ft_nbrlen(nbr));
}

int	ft_print_hex_uppercase(va_list args)
{
	unsigned int	nbr;

	nbr = va_arg(args, unsigned int);
	ft_putnbr_hex(nbr, 'A');
	return (ft_nbrlen(nbr));
}
