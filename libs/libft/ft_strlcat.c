/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busmanov <busmanov@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 13:48:13 by busmanov          #+#    #+#             */
/*   Updated: 2021/12/01 14:12:46 by busmanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *to, const char *from, size_t tosize)
{
	size_t	x;
	size_t	pto;
	size_t	pfrom;
	size_t	y;

	pto = ft_strlen(to);
	pfrom = ft_strlen(from);
	x = pto;
	if (to == from)
		return (0);
	if (tosize != 0 && x < (tosize - 1))
	{
		y = 0;
		while (x < (tosize - 1) && from[y] != '\0')
		{
			to[x] = from[y];
			x++;
			y++;
		}
		to[x] = '\0';
	}
	if (pto > tosize)
		return (tosize + pfrom);
	return (pto + pfrom);
}
