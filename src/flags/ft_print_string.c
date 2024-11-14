/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florianb <florianb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 11:30:12 by florianb          #+#    #+#             */
/*   Updated: 2024/11/14 22:49:54 by florianb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ft_putstr_print(va_list args)
{
	const char	*str;

	str = va_arg(args, const char *);
	write(1, str, ft_strlen(str));
	return (ft_strlen(str));
}
