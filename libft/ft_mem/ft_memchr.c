/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snocita <samuelnocita@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 14:55:56 by snocita           #+#    #+#             */
/*   Updated: 2023/06/30 19:10:48 by snocita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
// #include <stdio.h>

/*
	Locates the first occurence of a character inside a string
*/

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*byte;
	unsigned char	character;

	byte = (unsigned char *)s;
	character = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (*byte == character)
		{
			return (byte);
		}
		byte++;
		i++;
	}
	return (NULL);
}

// int	main(void)
// {
// 	char	str[] = "HELLOOOO";

// 	printf("%d", ft_memchr(str, 'H', 2));
// }
