/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busmanov <busmanov@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 14:26:28 by busmanov          #+#    #+#             */
/*   Updated: 2021/11/29 14:38:53 by busmanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *to, const void *from, size_t n)
{
	unsigned char	*pto;
	unsigned char	*pfrom;
	size_t			x;

	if (to == NULL && from == NULL)
		return (NULL);
	pto = (unsigned char *)to;
	pfrom = (unsigned char *)from;
	x = 0;
	while (x < n)
	{
		pto[x] = pfrom[x];
		x++;
	}
	return (pto);
}
