/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florianb <florianb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 11:31:11 by florianb          #+#    #+#             */
/*   Updated: 2024/11/14 22:49:39 by florianb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ft_print_pointer(va_list args)
{
	void	*ptr;

	ptr = va_arg(args, void *);
	write(1, "0x", 2);
	ft_putnbr_hex((unsigned long)ptr, 'a');
	return (ft_nbrlen((unsigned long)ptr) + 2);
}
