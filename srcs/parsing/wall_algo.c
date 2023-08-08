/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snocita <snocita@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 13:42:27 by snocita           #+#    #+#             */
/*   Updated: 2023/08/08 13:45:48 by snocita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	check_around(char	**map, int x, int y)
{
	printf("around\n");
	printf("AT: %c\n", map[y][x]);
	if (map[y][x] == '1' || map[y][x] == ' ' || map[y][x] == 'N')
	{
		printf(" 1, SPACE or N\n");
		return (SUCCESS);
	}
	if (ft_up_down(map, y, x) != SUCCESS)
		return (FAILURE);
	printf(" UPDOWN PASSED\n");
	if (ft_left_right(map, y, x) != SUCCESS)
		return (FAILURE);
	printf(" LEFTRIGHT PASSED\n");
	if (ft_corners(map, y, x) != SUCCESS)
		return (FAILURE);
	printf("CORNER PASSED\n");
	return (SUCCESS);
}

int	wall_test(t_gen	*gen)
{
	int	ret;
	int	i;
	int	j;

	ret = SUCCESS;
	i = 0;
	j = 0;
	if (get_dimensions(gen) != SUCCESS)
		return (error_message(5));
	while (i < gen->height)
	{
		j = 0;
		while (gen->buffered_map[i][j])
		{
			printf("checking\n");
			if (check_around(gen->buffered_map, j, i) != SUCCESS)
			{
				printf("FAIL\n");
				printf("COO: x:%d y:%d\n", j, i);
				return (FAILURE);
			}
			if (gen->buffered_map[i][j])
			{
				printf("\n\nTO NEXT ->>\n");
				j++;
			}
			else
				break ;
		}
		printf("NEW_LINE\n");
		i++;
	}
	return (ret);
}
