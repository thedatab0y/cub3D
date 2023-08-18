/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busmanov <busmanov@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 07:51:28 by busmanov          #+#    #+#             */
/*   Updated: 2023/08/18 10:43:16 by busmanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../gnl/get_next_line.h" 
#include "cub3d.h"

static int	is_only_wspace(char *str)
{
	while (*str)
	{
		if (!(*str == ' ' || (*str >= 9 && *str <= 13)))
			return (0);
		str++;
	}
	return (1);
}

int	is_empty_line(char *line)
{
	if (!ft_strncmp(line, "\n", 1) || is_only_wspace(line))
		return (1);
	else
		return (0);
}

//  used for reading lines from a file descriptor and 
//skipping over empty lines until non-empty line.
void	skip_empty_line(int fd, char **line)
{
	*line = get_next_line(fd);
	if (!(*line))
		err_exit(0);
	while ((*line) && is_empty_line(*line))
	{
		free(*line);
		*line = get_next_line(fd);
	}
}
