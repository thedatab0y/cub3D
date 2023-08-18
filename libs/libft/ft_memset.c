/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busmanov <busmanov@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 12:16:58 by busmanov          #+#    #+#             */
/*   Updated: 2021/11/22 14:31:53 by busmanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memset(void *str, int setchar, size_t n)
{
	size_t			i;
	unsigned char	*x;

	i = 0;
	x = str;
	while (i != n)
	{
		x[i] = setchar;
		i++;
	}
	return (x);
}
