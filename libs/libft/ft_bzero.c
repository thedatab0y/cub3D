/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busmanov <busmanov@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 10:50:50 by busmanov          #+#    #+#             */
/*   Updated: 2021/11/29 13:48:09 by busmanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	ft_bzero(void *str, size_t n)
{
	unsigned char	*ptr;
	size_t			index;

	index = 0;
	ptr = str;
	while (index < n)
	{
		ptr[index] = '\0';
		index++;
	}
}
