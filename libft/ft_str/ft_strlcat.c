/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snocita <samuelnocita@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 10:33:01 by snocita           #+#    #+#             */
/*   Updated: 2023/06/30 19:11:48 by snocita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
	returns total length that would have been created
	if there was unlimited space.
*/

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (dst[i] && i < dstsize)
		i++;
	while (src[j] && (i + j + 1) < dstsize)
	{
		dst[i + j] = src[j];
		j++;
	}
	if (i < dstsize)
		dst[i + j] = '\0';
	return (i + ft_strlen(src));
}
