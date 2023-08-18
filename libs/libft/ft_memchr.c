/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busmanov <busmanov@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 14:11:33 by busmanov          #+#    #+#             */
/*   Updated: 2022/01/05 16:23:40 by busmanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			x;
	unsigned char	*s1;

	s1 = (unsigned char *)s;
	x = 0;
	while (x < n)
	{
		if (s1[x] == (unsigned char)c)
		{
			return (s1 + x);
		}
		x++;
	}
	return (NULL);
}
