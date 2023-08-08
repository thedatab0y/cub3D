/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_algo_two.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snocita <snocita@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 13:45:16 by snocita           #+#    #+#             */
/*   Updated: 2023/08/08 13:46:04 by snocita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	ft_up_down(char	**map, int y, int x)
{
	int	ret;
	int	up;
	int	down;

	ret = FAILURE;
	up = y;
	down = y;
	up++;
	down--;
	printf("\tUP and DOWN\n");
	if ((map[(up)][x] == '1') || (map[(up)][x] == '0'))
	{
		printf("\tAT UP: %c\n", map[(up)][x]);
		if (map[(down)][x] != '1' || map[(down)][x] != '0')
		{
			printf("\tAT DOWN: %c\n", map[(down)][x]);
			return (SUCCESS);
		}
		else
			return (ret);
	}
	else
		return (ret);
}

int	ft_left_right(char	**map, int y, int x)
{
	int	ret;
	int	left;
	int	right;

	ret = FAILURE;
	left = x;
	right = x;
	left--;
	right++;
	printf("\t\tRIGHT and LEFT\n");
	if (map[y][(right)] != '1' || map[y][(right)] != '0')
	{
		printf("\t\tAT RIGHT: %c\n", map[y][(right)]);
		if (map[y][(left)] != '1' || map[y][left] != '0')
		{
			printf("\t\tAT LEFT: %c\n", map[y][(left)]);
			return (SUCCESS);
		}
		else
			return (ret);
	}
	else
		return (ret);
}

int	ft_top_leftright(char **map, int *top_left, int *top_right)
{
	int	ret;

	ret = FAILURE;
	printf("TOP_LEFTRIGHT\n");
	if (map[top_left[0]][top_right[1]] != '1'
		|| map[top_left[0]][top_right[1]] != '0')
	{
		printf("AT TOP_LEFT: %d\n", map[top_left[0]][top_left[1]]);
		return (0);
	}
	else
		return (ret);
}

// int	ft_bot_leftright(char **map, int *top_left, int *top_right)
// {
	
// }

int	ft_corners(char	**map, int y, int x)
{
	int	ret;
	int	top_left[2];
	int	top_right[2];
	int	bot_left[2];
	int	bot_right[2];

	ret = FAILURE;
	top_left[0] = y;
	top_left[1] = x;
	top_right[0] = y;
	top_right[1] = x;
	bot_left[0] = y;
	bot_left[1] = x;
	bot_right[0] = y;
	bot_right[1] = x;
	top_left[0]++;
	top_left[1]--;
	top_right[0]++;
	top_left[1]++;
	printf("\t\tCORNERS\n");
	if (ft_top_leftright(map, top_left, top_right) != FAILURE)
	{
		// if (ft_bot_leftright(map, bot_left, bot_right) != FAILURE)
		// 	return (SUCCESS);
		// else
		// 	return (FAILURE);
		return (SUCCESS);
	}
	else
		return (FAILURE);
}
