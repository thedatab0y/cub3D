/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busmanov <busmanov@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 17:40:53 by busmanov          #+#    #+#             */
/*   Updated: 2023/08/17 17:40:55 by busmanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	int	x;

	x = 0;
	if (!s)
		return (NULL);
	while (s[x] != 0)
	{
		if (s[x] == (char)c)
			return ((char *)&s[x]);
		x++;
	}
	if (s[x] == (char)c)
		return ((char *)&s[x]);
	return (0);
}

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
