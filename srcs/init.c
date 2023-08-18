/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busmanov <busmanov@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 07:50:57 by busmanov          #+#    #+#             */
/*   Updated: 2023/08/18 09:38:35 by busmanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdlib.h>

//FUNCTION prepares t_cub3d structure for use  by initializing its
// members to appropriate starting values. It is often used at 
//the beginning of the program or before populating the 
// structure with actual data from a configuration file.
// 1. exture Path Pointers (no, so, ea, we)
// 2. Map Data Pointer (map)
// 3. Color Members (fl, ce)
// 4. Map Dimensions (h, w)
void	init_cub3d(t_cub3d *c)
{
	c->no = NULL;
	c->so = NULL;
	c->ea = NULL;
	c->we = NULL;
	c->map = NULL;
	c->fl = UNDEF;
	c->ce = UNDEF;
	c->h = 0;
	c->w = 0;
}

//FUNCTION sets up vector components based on character 
//representing a direction (North, South, East, West) 
//& initial position coordinates (x, y).It's used set
//up player's initial pos & orientation in game world.
// 1.Position Coordinates (pos_x, pos_y):
//- represent the position in the 2D space.
//(+ 0.5) used for accurate positioning in grid-based systems.
//2. Direction & Plane Components (dir_x, dir_y, pln_x, pln_y):
// represents direction and orientation in the 2D space.
// initialized with default values of 1 or 0.66.
// 3.Adjustments Based on Character 'c':
// If c is 'N' or 'S', the corresponding direction and plane
// components are set to zero, and flipping is applied.
// If c is 'E' or 'W', the corresponding direction and plane
// components are set to zero, and flipping is applied.
// flipping is to ensure that the player's initial orientation
// is aligned with the intended game world's direction.
void	init_vec(t_vec *v, char c, int x, int y)
{
	v->pos_x = (double)x + 0.5;
	v->pos_y = (double)y + 0.5;
	v->dir_x = 1;
	v->dir_y = 1;
	v->pln_x = 0.66;
	v->pln_y = 0.66;
	if (c == 'N' || c == 'S')
	{
		v->dir_x = 0;
		v->pln_y = 0;
		if (c == 'N')
			v->dir_y *= -1;
		else
			v->pln_x *= -1;
	}
	if (c == 'E' || c == 'W')
	{
		v->dir_y = 0;
		v->pln_x = 0;
		if (c == 'W')
		{
			v->dir_x *= -1;
			v->pln_y *= -1;
		}
	}
}

// FUNCTION sets up texture images for rendering using mlx.
//allocates memory for texture arrays, initializes them with zeros,
//& populates these arrays by converting XPM images into texture data
//finally new image is created in memory 4 rendering using MLX library
static void	init_texture(t_mlx *m, t_cub3d *c)
{
	int	i;

	i = -1;
	while (++i < 4)
	{
		m->texture[i] = malloc(sizeof(int) * PIX * PIX);
		if (m->texture[i] == NULL)
			err_exit(0);
		ft_bzero(m->texture[i], sizeof(int) * PIX * PIX);
	}
	my_xpm_to_img(m, 0, c->we);
	my_xpm_to_img(m, 1, c->ea);
	my_xpm_to_img(m, 2, c->no);
	my_xpm_to_img(m, 3, c->so);
	m->img.img_ptr = mlx_new_image(m->mlx_ptr, \
		WIN_X, WIN_Y);
	m->img.data = (unsigned int *)mlx_get_data_addr(m->img.img_ptr, \
		&m->img.bpp, &m->img.size_l, &m->img.endian);
}

//FUNCTION sets up temporary 2D array that can be used for rendering
//purposes. The array is used to store pixel information during 
//rendering operations, and it provides a buffer to hold temporary 
//graphical data before it's finalized and displayed on the screen.
// 1. Memory Allocation for Rows
// 2. Loop Through Rows
// 3. Memory Allocation for Columns
// 4. Initialize with Zeros:
// After memory allocation, the allocated memory for each row is
// initialized with zeros using ft_bzero.
static void	init_tmp(t_mlx *m)
{
	int		i;

	m->tmp = malloc(sizeof(int *) * WIN_Y);
	if (m->tmp == NULL)
		err_exit(0);
	i = -1;
	while (++i < WIN_Y)
	{
		m->tmp[i] = malloc(sizeof(int) * WIN_X);
		if (m->tmp[i] == NULL)
			err_exit(0);
		ft_bzero(m->tmp[i], sizeof(int) * WIN_X);
	}
}

// responsible for initializing various graphics-related 
// components within the game using the (MLX).
void	init_mlx(t_game *g)
{
	init_tmp(g->mlx);
	init_texture(g->mlx, g->cub);
}
