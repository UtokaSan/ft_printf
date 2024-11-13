/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florianb <florianb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 11:36:30 by florianb          #+#    #+#             */
/*   Updated: 2024/11/13 11:36:42 by florianb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	ft_print_unsigned_decimal(va_list args)
{
	unsigned int	nbr;

	nbr = va_arg(args, unsigned int);
	ft_putnbr_fd(nbr, 1);
}
