/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florianb <florianb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 02:37:39 by florianb          #+#    #+#             */
/*   Updated: 2024/11/12 21:29:48 by florianb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

int		ft_printf(const char *format, ...);

typedef struct s_flags
{
	char	value;
	void	(*action)(va_list);
}	t_flags;

static t_flags	g_flags[3];
#endif