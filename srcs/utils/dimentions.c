/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dimentions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snocita <snocita@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 13:41:32 by snocita           #+#    #+#             */
/*   Updated: 2023/08/08 13:42:08 by snocita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	get_height(char	**map)
{
	int	i;
	int	j;
	int	height;

	i = 0;
	j = 0;
	height = 0;
	while ((map[i]))
	{
		if (map[i][j] == '0')
		{
			height = -1;
			break ;
		}
		else if ((map[i][j] == ' ') || (map[i][j] == '1'))
			height++;
		i++;
	}
	return (height);
}

int	get_width(char	**map)
{
	int	i;
	int	j;
	int	width;

	i = 0;
	j = 0;
	width = 0;
	while ((map[i][j]))
	{
		if (map[i][j] == '0')
		{
			width = -1;
			break ;
		}
		else if ((map[i][j] == ' ') || (map[i][j] == '1'))
			width++;
		j++;
	}
	return (width);
}

/**
 * get width and height, if a 0 is found
 * the return value is -1;
*/
int	get_dimensions(t_gen	*gen)
{
	gen->height = get_height(gen->buffered_map);
	gen->width = get_width(gen->buffered_map);
	if ((gen->height == -1) || (gen->width == -1))
		return (FAILURE);
	if (ft_strchr(gen->buffered_map[gen->height - 1], '0') != NULL)
		return (FAILURE);
	printf("Width is -> %d\n", gen->width);
	printf("Height is -> %d\n", gen->height);
	return (SUCCESS);
}
