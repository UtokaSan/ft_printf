/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florianb <florianb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 11:31:11 by florianb          #+#    #+#             */
/*   Updated: 2024/11/13 11:52:16 by florianb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	ft_print_pointer(va_list args)
{
	void	*ptr;

	ptr = va_arg(args, void *);
	write(1, "0x", 2);
	ft_putnbr_hex((unsigned long)ptr, 'a');
}
