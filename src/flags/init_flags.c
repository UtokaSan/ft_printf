/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_flags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fboulbes <fboulbes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 18:31:01 by fboulbes          #+#    #+#             */
/*   Updated: 2025/01/27 20:45:47 by fboulbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags	*init_flags(void)
{
	size_t			i;
	static t_flags	flags[NUM_FLAGS];
	static char		specifiers[] = "sdcpiuxX%";
	static int		(*actions[])(va_list) = {
		putstr_print,
		decimal_print,
		putchar_print,
		print_pointer,
		decimal_print,
		print_unsigned_decimal,
		print_hex_lowercase,
		print_hex_uppercase,
		print_percent
	};

	i = 0;
	while (i < NUM_FLAGS)
	{
		flags[i].value = specifiers[i];
		flags[i].action = actions[i];
		i++;
	}
	return (flags);
}
