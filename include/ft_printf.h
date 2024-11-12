/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florianb <florianb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 02:37:39 by florianb          #+#    #+#             */
/*   Updated: 2024/11/12 23:43:15 by florianb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
void	ft_putchar_print(va_list args);
void	ft_putstr_print(va_list args);
void	ft_putnbr_print(va_list args);
void	ft_print_pointer(va_list args);

typedef struct s_flags
{
	char	value;
	void	(*action)(va_list);
}	t_flags;

extern t_flags	g_flags[4];

#endif