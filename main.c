/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florianb <florianb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 22:15:37 by florianb          #+#    #+#             */
/*   Updated: 2024/11/13 14:01:52 by florianb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	main(void)
{
	int	a;
	int	*ptr;

	ptr = &a;
	a = 42;
	ft_printf("Hello ss%s World%p\nje test les unsigned int%r je veux 120%%", "42", ptr, 255);
	return (0);
}
