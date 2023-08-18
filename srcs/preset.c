/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busmanov <busmanov@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 07:51:21 by busmanov          #+#    #+#             */
/*   Updated: 2023/08/18 14:15:37 by busmanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../gnl/get_next_line.h" 
#include "cub3d.h"

// used to set texture paths within game configuration
// The texture parameter is a pointer to a pointer 
//(char **) that points to a texture path string. By 
//passing the address of the texture pointer, the 
//function can modify the actual texture variable and 
//set it to the desired texture path
static void	set_texture(char **texture, char *value)
{
	*texture = ft_substr(value, 0, ft_strlen(value) - 1);
	if (!(*texture))
		err_exit(0);
}

// helps populate the game configuration structure with 
//the appropriate texture paths and colors based on the 
//provided key-value pairs
// The function first checks the key to determine which
// parameter is being set.
static void	set_cub3d(char *key, char *value, t_cub3d *c)
{
	if (ft_strcmp(key, "NO") == 0 && c->no == NULL)
		set_texture(&c->no, value);
	else if (ft_strcmp(key, "SO") == 0 && c->so == NULL)
		set_texture(&c->so, value);
	else if (ft_strcmp(key, "WE") == 0 && c->we == NULL)
		set_texture(&c->we, value);
	else if (ft_strcmp(key, "EA") == 0 && c->ea == NULL)
		set_texture(&c->ea, value);
	else if (ft_strcmp(key, "F") == 0 && c->fl == UNDEF)
		set_color(&c->fl, value);
	else if (ft_strcmp(key, "C") == 0 && c->ce == UNDEF)
		set_color(&c->ce, value);
	else
		err_exit("Invalid texture.");
}

// help parse and process configuration data from file
// populating the game's configuration structure with 
//the relevant information
//used iteratively to process each line of file
// 1. It reads a line from the file using the
// get_next_line function.
// 2. It then uses the set_cub3d function to populate
// the game configuration (t_cub3d structure) based 
//on the key-value pair obtained from the split array.
// 
static int	check_cub(int fd, t_cub3d *c)
{
	char	*line;
	char	**split;
	int		err;

	err = SUCCESS;
	split = NULL;
	line = get_next_line(fd);
	if (!line)
		err_exit(0);
	if (!is_empty_line(line))
	{
		split = ft_split(line, ' ');
		if (!split)
			err_exit(0);
		set_cub3d(split[0], split[1], c);
	}
	free(line);
	free_double_char(split);
	return (err);
}

//function is to sequentially process lines of 
//configuration data and populate the game's
// configuration structure until all required 
//settings are obtained. 
void	parse_cub(int fd, t_cub3d *c)
{
	init_cub3d(c);
	while (c->no == NULL || c->so == NULL || c->we == NULL \
		|| c->ea == NULL || c->fl == UNDEF || c->ce == UNDEF)
		check_cub(fd, c);
}
