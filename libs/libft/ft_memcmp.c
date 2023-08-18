/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busmanov <busmanov@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 13:02:10 by busmanov          #+#    #+#             */
/*   Updated: 2021/12/07 13:26:19 by busmanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*st1;
	unsigned char	*st2;
	size_t			x;

	st1 = (unsigned char *)s1;
	st2 = (unsigned char *)s2;
	x = 0;
	while (n--)
	{
		if (st1[x] != st2[x])
			return (st1[x] - st2[x]);
		x++;
	}
	return (0);
}
