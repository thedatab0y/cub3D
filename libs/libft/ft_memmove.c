/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmore.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busmanov <busmanov@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 14:40:39 by busmanov          #+#    #+#             */
/*   Updated: 2021/11/29 14:54:02 by busmanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *to, const void *from, size_t x)
{
	unsigned char	*pto;
	unsigned char	*pfrom;
	size_t			y;

	if (!to && !from)
		return (NULL);
	pto = (unsigned char *)to;
	pfrom = (unsigned char *)from;
	y = 0;
	if (x == 0)
		return (to);
	if (pto > pfrom)
	{
		while (x-- > 0)
			pto[x] = pfrom[x];
	}
	else
	{
		while (y < x)
		{
			pto[y] = pfrom[y];
			y++;
		}
	}
	return (to);
}
