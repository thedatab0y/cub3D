/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busmanov <busmanov@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 07:50:45 by busmanov          #+#    #+#             */
/*   Updated: 2023/08/18 14:36:26 by busmanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// load textures from XPM image files & store them in game's
// texture array for later use in rendering the game's env
// 1.Load Image and Retrieve Information
// 2.Get Image Data Pointer:
// mlx_get_data_addr to obtain a pointer (img.data) to the 
//image's pixel data,
// 3. Copy Image Data to Texture Array:
// The function iterates over each pixel of the image and
// copies the pixel data from img.data to the corresponding
// location in the game's texture array (m->texture[dir])
// 4. Destroy Loaded Image
void	my_xpm_to_img(t_mlx *m, int dir, char *wall)
{
	t_image	img;
	int		x;
	int		y;
	int		w;
	int		h;

	img.img_ptr = mlx_xpm_file_to_image(m->mlx_ptr, \
	wall, &w, &h);
	if (!img.img_ptr)
		err_exit("Invalid texture!");
	img.data = (unsigned int *)mlx_get_data_addr(img.img_ptr, \
		&img.bpp, &img.size_l, &img.endian);
	y = -1;
	while (++y < h)
	{
		x = -1;
		while (++x < w)
			m->texture[dir][w * y + x] = img.data[w * y + x];
	}
	mlx_destroy_image(m->mlx_ptr, img.img_ptr);
}

// FOR FLOOR AND CEIL
// function fills a temporary image buffer with ceiling 
//color in the top half and floor color in the bottom half
// to simulate a 3D spac
void	draw_floor_ceil(t_game *g)
{
	int	x;
	int	y;

	x = -1;
	while (++x < WIN_X)
	{
		y = -1;
		while (++y < WIN_Y / 2)
		{
			g->mlx->tmp[y][x] = g->cub->ce;
			g->mlx->tmp[WIN_Y - y - 1][x] = g->cub->fl;
		}
	}
}
