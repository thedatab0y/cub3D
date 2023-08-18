/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busmanov <busmanov@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 11:05:44 by snocita           #+#    #+#             */
/*   Updated: 2023/08/18 13:28:27 by busmanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../gnl/get_next_line.h" 
#include "../../cub3d.h"
#include <fcntl.h>
#include <unistd.h>

// Checks the file extension of a given file 
//name (av) and ensures that it is ".cub"
static void	check_format(char *av, int *fd)
{
	int	len;

	len = ft_strlen(av);
	if (len < 4 || av[len - 4] != '.' || av[len - 3] != 'c'\
		|| av[len - 2] != 'u' || av[len - 1] != 'b')
		err_exit("Invalid map extension.");
	*fd = open(av, O_RDONLY);
	if (*fd < 0)
		err_exit("Open map failed.");
}

void	parse(char *av, t_game *g)
{
	int		fd;

	check_format(av, &fd);
	parse_cub(fd, g->cub);
	parse_map(fd, g);
	close(fd);
}
