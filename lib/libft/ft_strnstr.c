/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florianb <florianb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 20:50:27 by fboulbes          #+#    #+#             */
/*   Updated: 2024/11/12 01:09:28 by florianb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h> 
// #include <string.h>

#include "libft.h"

char	*ft_strnstr(const char *b, const char *l, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (l[j] == '\0')
		return ((char *)b);
	if (len == 0)
		return (NULL);
	while ((b[i] != '\0' && l[j] != '\0') && i < len)
	{
		if (b[i] == l[j])
			j++;
		i++;
	}
	if (l[j] == '\0')
		return ((char *)&b[i - j]);
	return (NULL);
}
/*
int	main(void)
{
	printf("%s", ft_strnstr("aaabcabcd", "abcd", 9));
	return (0);
}
*/