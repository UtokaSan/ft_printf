/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florianb <florianb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 22:15:37 by florianb          #+#    #+#             */
/*   Updated: 2024/11/14 22:20:27 by florianb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	main(void)
{
	int count = ft_printf("Hello ss%s World%t", "42");
	printf("\nCount: %d\n", count);
	return (0);
}
