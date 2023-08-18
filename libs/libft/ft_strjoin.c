/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busmanov <busmanov@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 14:04:26 by busmanov          #+#    #+#             */
/*   Updated: 2023/08/17 17:28:23 by busmanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *temp, char *buffer)
{
	char	*str;
	int		x;
	int		y;

	if (!temp)
	{
		temp = malloc(1);
		temp[0] = '\0';
	}
	str = malloc(sizeof(char) * ((ft_strlen(temp) + ft_strlen(buffer) + 1)));
	if (!str)
		return (NULL);
	x = -1;
	y = 0;
	if (temp)
	{
		while (temp[++x] != '\0')
			str[x] = temp[x];
	}
	while (buffer[y] != '\0')
		str[x++] = buffer[y++];
	str[ft_strlen(temp) + ft_strlen(buffer)] = '\0';
	free(temp);
	return (str);
}
