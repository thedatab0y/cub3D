/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busmanov <busmanov@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 13:29:13 by busmanov          #+#    #+#             */
/*   Updated: 2023/07/26 12:55:43 by busmanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_strncmp(const char *st1, const char *st2, size_t x)
{
	size_t	n;

	n = 0;
	if (x == 0)
		return (0);
	while (n < x - 1 && st1[n] != '\0' && st2[n] != '\0' && st1[n] == st2[n])
	{
		n++;
	}
	return ((unsigned char)st1[n] - (unsigned char)st2[n]);
}
