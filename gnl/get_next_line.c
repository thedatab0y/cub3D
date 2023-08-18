/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busmanov <busmanov@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 17:52:14 by busmanov          #+#    #+#             */
/*   Updated: 2023/08/17 17:52:16 by busmanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>

char	*ft_read_line(char *buffer, int fd)
{
	char	*temp;
	int		byte_count;

	byte_count = 1;
	temp = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (temp == NULL)
		return (NULL);
	while (!(ft_strchr(buffer, '\n')) && byte_count != 0)
	{
		byte_count = read(fd, temp, BUFFER_SIZE);
		if (byte_count == -1)
		{
			free(temp);
			free(buffer);
			return (NULL);
		}
		temp[byte_count] = '\0';
		buffer = ft_strjoin(buffer, temp);
	}
	free(temp);
	return (buffer);
}

//return the line being read
char	*ft_ret_read_line(char *buffer)
{
	char	*line;
	int		x;

	x = 0;
	if (!buffer[x])
		return (NULL);
	while (buffer[x] != '\n' && buffer[x])
		x++;
	line = malloc(sizeof(char) * (x + 2));
	if (!line)
		return (NULL);
	x = 0;
	while (buffer[x] != '\n' && buffer[x])
	{
		line[x] = buffer[x];
		x++;
	}
	if (buffer[x] == '\n')
	{
		line[x] = '\n';
		x++;
	}
	line[x] = '\0';
	return (line);
}

char	*ft_update_line(char *buffer)
{
	int		x;
	int		y;
	char	*new_str;

	x = 0;
	y = -1;
	while (buffer[x] != '\n' && buffer[x])
		x++;
	if (!buffer[x])
	{
		free(buffer);
		return (NULL);
	}
	new_str = malloc(sizeof(char) * (ft_strlen(buffer) - x + 1));
	if (!new_str)
		return (NULL);
	x++;
	while (buffer[x])
	{
		new_str[++y] = buffer[x];
		x++;
	}
	new_str[++y] = '\0';
	free(buffer);
	return (new_str);
}

//reads from fd and returns one line or NULL
char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = ft_read_line(buffer, fd);
	if (buffer == NULL)
		return (NULL);
	line = ft_ret_read_line(buffer);
	buffer = ft_update_line(buffer);
	return (line);
}
