/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_algo_two.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busmanov <busmanov@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 11:05:44 by snocita           #+#    #+#             */
/*   Updated: 2023/08/18 13:58:37 by busmanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../gnl/get_next_line.h" 
#include "../../cub3d.h"

static void	wall_test(int y, char **map, t_cub3d *c)
{
	int	x;

	x = -1;
	while (++x < c->w)
	{
		if (map[y][x] == '0' && (\
			y == 0 || y == c->h - 1 || x == 0 || x == c->w - 1 \
			|| map[y - 1][x] == ' ' || map[y + 1][x] == ' ' \
			|| map[y][x - 1] == ' ' || map[y][x + 1] == ' '))
			err_exit("The player might run away!");
	}
}

//Check around
// Extends a given line to match a desired width by 
//adding spaces at the end of the line.
// Concatenates the extended line with the spaces
static void	make_map_rectangle(char **line, int w)
{
	int		size;
	char	*fill;

	size = w - (int)ft_strlen(*line);
	if (size > 0)
	{
		fill = ft_calloc(sizeof(char), size + 1);
		if (!fill)
			err_exit(0);
		ft_memset(fill, ' ', size);
		*line = ft_strjoin(*line, fill);
		if (!*line)
			err_exit(0);
		free(fill);
	}
}

//Processes and validates the input map, ensuring
// its dimensions and wall placement, and then 
//stores the processed map in the c->map variable
// within the t_cub3d structure.
// 1. Splitting
// 2. Array Check
// 3. Map Rectangularization
// 4. Map Validation
// 5. Map Assignment
static void	set_map(char *full_line, t_cub3d *c)
{
	int		y;
	char	**map;

	y = -1;
	map = ft_split(full_line, '\n');
	free(full_line);
	if (!map)
		err_exit(0);
	while (++y < c->h)
		make_map_rectangle(&map[y], c->w);
	y = -1;
	while (++y < c->h)
		wall_test(y, map, c);
	c->map = map;
}

// Processes and validates a line of the map, detecting
// player characters, initializing player position data,
// and updating the dimensions of the map.
// 1. Player Character Detection:
// with init_vec, initialize some vector data related 
//to the player's position
// 2. Validation Check
static int	check_element(char *line, int *is_p, t_game *g)
{
	int	x;

	x = -1;
	while (line[++x])
	{
		if (!(*is_p) && ft_strchr("NSEW", line[x]))
		{
			init_vec(g->vec, line[x], x, g->cub->h);
			*is_p = 1;
			line[x] = '0';
			continue ;
		}
		if (!ft_strchr("10 \n", line[x]))
			return (FAIL);
	}
	if (--x > g->cub->w)
		g->cub->w = x;
	g->cub->h++;
	return (SUCCESS);
}

//Function reads and processes the map data from the input
// file, handling empty lines, map element validation,
//player detection, map concatenation, and setting up the
//processed map in the game structure.
// 1. Structure Initialization
// 2. Empty Line Skipping
// 3. Main Parsing Loop
// 4. Non-Empty Line Check
// 5. Element Parsing
// 6. Full Line Concatenation:
// This step effectively builds  entire map into single string.
// 7. Full Line Concatenation Check
// 8. Empty Line Flag Update
// 9. Map Setting
// It calls the set_map function with the concatenated 
//p.full_line and the g->cub pointer to set up the processed 
//map data in the game structure.
void	parse_map(int fd, t_game *g)
{
	t_parse	p;

	ft_bzero(&p, sizeof(t_parse));
	skip_empty_line(fd, &p.line);
	while (p.line)
	{
		if (!is_empty_line(p.line))
		{
			if (p.is_e || check_element(p.line, &p.is_p, g))
				err_exit("Invalid map!");
			p.full_line = ft_strjoin(p.full_line, p.line);
			if (!p.full_line)
				err_exit(0);
		}
		else
			p.is_e = 1;
		free(p.line);
		p.line = get_next_line(fd);
	}
	if (!p.is_p)
		err_exit("No player, no game!");
	set_map(p.full_line, g->cub);
}
