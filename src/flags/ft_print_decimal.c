/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_decimal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florianb <florianb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 11:32:14 by florianb          #+#    #+#             */
/*   Updated: 2024/11/13 11:35:20 by florianb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	ft_decimal_print(va_list args)
{
	int	nbr;

	nbr = va_arg(args, int);
	ft_putnbr_fd(nbr, 1);
}
