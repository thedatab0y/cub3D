/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busmanov <busmanov@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 11:05:44 by snocita           #+#    #+#             */
/*   Updated: 2023/08/18 10:48:57 by busmanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

// Strings are used to store text data like file path
//deallocate memory that was previously allocated 
//for a two-dimensional array of strings
void	free_double_char(char **ptr)
{
	int	i;

	if (!ptr)
		return ;
	i = -1;
	while (ptr[++i])
		free(ptr[i]);
	free(ptr);
}

// Used to store various numerical data, such as map data
//deallocate memory that was previously allocated
//for a two-dimensional array of integers 
void	free_double_int(int **ptr)
{
	int	i;

	if (!ptr)
		return ;
	i = -1;
	while (ptr[++i])
		free(ptr[i]);
	free(ptr);
}

//responsible for freeing memory associated with the various
// fields of the t_cub3d structure.
// 1. Free Texture Paths
// 2. Free Map.
void	free_cub(t_cub3d *cub)
{
	if (cub->no)
		free(cub->no);
	if (cub->so)
		free(cub->so);
	if (cub->we)
		free(cub->we);
	if (cub->ea)
		free(cub->ea);
	if (cub->map)
		free_double_char(cub->map);
}
