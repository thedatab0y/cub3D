/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busmanov <busmanov@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 14:04:32 by busmanov          #+#    #+#             */
/*   Updated: 2021/12/01 13:46:50 by busmanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *to, const char *from, size_t n)
{
	size_t	x;
	size_t	y;

	x = 0;
	y = ft_strlen(from);
	if (to == NULL)
		return (y);
	if (n == 0)
		return (y);
	while (from[x] && x < n - 1)
	{
		to[x] = from[x];
		x++;
	}
	to[x] = '\0';
	while (from[x])
		x++;
	return (x);
}
