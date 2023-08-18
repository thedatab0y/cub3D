/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busmanov <busmanov@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 07:50:26 by busmanov          #+#    #+#             */
/*   Updated: 2023/08/18 14:32:34 by busmanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>

// calculate the distance from the player's current
// position to the nearest wall along the ray's path.
// 1. For Sides 0 and 1 (X-Axis Walls):
// If the side of the wall is 0 or 1, indicating that
// the ray hit a vertical wall (left or right side), 
//the function calculates the distance from the player's
// current position to the wall along the x-axis.
// 2. For Other Sides (Y-Axis Walls):
// If the side of the wall is not 0 or 1 (i.e., it's
// 2 or 3), indicating that the ray hit a horizontal 
//wall (top or bottom side), the function calculates 
//the distance from the player's current position to 
//the wall along the y-axis.
// if the calculated wall distance is very small, 
//it's adjusted to a small positive value to avoid 
//division by zero.
// 3. Return Wall Intersection Coordinate:
//function returns coordinates where the ray hit 
//the wall and is used for further calculations, 
//such as rendering textured walls.
static double	calc_dis(t_vec *v, t_raycast *r)
{
	if (r->side == 0 || r->side == 1)
	{
		r->wall_dist = (r->map_x - v->pos_x + \
			(1 - r->step_x) / 2) / r->raydir_x;
		if (r->wall_dist <= 0.000001)
			r->wall_dist = 0.00001;
		return (v->pos_y + r->wall_dist * r->raydir_y);
	}
	r->wall_dist = (r->map_y - v->pos_y + \
		(1 - r->step_y) / 2) / r->raydir_y;
	if (r->wall_dist <= 0.000001)
		r->wall_dist = 0.00001;
	return (v->pos_x + r->wall_dist * r->raydir_x);
}

// Prepare information needed to render the wall, including
// its height on the screen, the texture coordinate for 
//correct mapping, and the vertical range of pixels to draw.
// 1. Calculate Normalized Wall Coordinate:
// 2. Calculate Wall Height:
// The height of the wall (w->line_h) is calculated based
// on reciprocal of calculated wall distance (r->wall_dist).
// 3. Set Wall Side:
// The side of the wall that was hit (w->side) is set based
// on the value stored in r->side. Needed for text mapping.
// 4.Calculate Texture Coordinate:
// The texture coordinate (w->tex_x) is calculated by mapping
// normalized wall coordinate to range of texture pixels (PIX)
// 5. Adjust Texture Coordinate for Flipping
// 6. Calculate Drawing Range.
static void	calc_wall(t_vec *v, t_raycast *r, t_wall *w)
{
	double	wall_x;

	wall_x = calc_dis(v, r);
	wall_x -= floor(wall_x);
	w->line_h = (WIN_Y / r->wall_dist);
	w->side = r->side;
	w->tex_x = (int)(wall_x * (double)PIX);
	if (((r->side == 0) || (r->side == 1)) && r->raydir_x < 0)
		w->tex_x = PIX - w->tex_x - 1;
	if (((r->side == 2) || (r->side == 3)) && r->raydir_y > 0)
		w->tex_x = PIX - w->tex_x - 1;
	w->draw_start = -w->line_h / 2 + WIN_Y / 2;
	if (w->draw_start < 0)
		w->draw_start = 0;
	w->draw_end = w->line_h / 2 + WIN_Y / 2;
	if (w->draw_end >= WIN_Y)
		w->draw_end = WIN_Y - 1;
}

//Responsible for rendering a vertical line of pixels on the 
//screen using the information from the t_wall structure
// 1.Calculate Step and Initial Texture Position:
// Calculates the step size (step) needed to traverse the 
//texture vertically based on height of wall (w.line_h).
// Calculates the initial texture position (tex_pos)
// 2.Loop Through Vertical Pixels:
//loop that iterates through each vertical pixel position
// from the w.draw_start to w.draw_end
// 3. Calculate Vertical Texture Coordinate:
// For each pixel position, the vertical texture coordinate
// (tex_y) is calculated using the current tex_pos value.
// "& (PIX - 1)" operation effectively wraps the texture 
//coordinate if it goes beyond the texture's height (PIX).
// 4. Update Texture Position:
// The tex_pos is updated by adding the previously calculated
// step to it. This moves txt position vertically 4 next pixel
// 5. Get Texture Color:
// The color value (color) is retrieved from the game's 
//texture array (g->mlx->texture) using the calculated w.side
// and texture coordinates (w.tex_x and tex_y).
// 6. Store Color in Temporary Buffer:
// The retrieved color val is stored in tmp buffer (g->mlx->tmp)
// at the corresponding pixel position (i, x)
// 7. Increment Vertical Pixel Position:
// Loop increments vert pixel pos (i) to move to next row.
void	map_line(t_game *g, t_wall w, int x)
{
	double	step;
	double	tex_pos;
	int		i;
	int		tex_y;
	int		color;

	step = 1.0 * PIX / w.line_h;
	tex_pos = (w.draw_start - WIN_Y / 2 + w.line_h / 2) * step;
	i = w.draw_start;
	while (i <= w.draw_end)
	{
		tex_y = (int)tex_pos & (PIX - 1);
		tex_pos += step;
		color = g->mlx->texture[w.side][PIX * tex_y + w.tex_x];
		g->mlx->tmp[i][x] = color;
		i++;
	}
}

// Transferring the pixel data from the temporary buffer to 
//the image buffer used by the graphics library.
// 1. Transfer Color Data:
// iterates over each pixel position in temporary buffer.
// For each pixel position, it transfers the color value 
//from the temporary buffer (g->mlx->tmp) to the corresponding
//position in the image buffer (g->mlx->img.data).
// 2. Display Image on Window:
// Once the color data has been set, mlx_put_image_window()
// The (0, 0) coordinates indicate the position within the 
//window where the top-left corner of image should be placed.
void	draw(t_game *g)
{
	int	x;
	int	y;

	y = -1;
	while (++y < WIN_Y)
	{
		x = -1;
		while (++x < WIN_X)
			g->mlx->img.data[y * WIN_X + x] = g->mlx->tmp[y][x];
	}
	mlx_put_image_to_window(g->mlx->mlx_ptr, \
		g->mlx->mlx_win, g->mlx->img.img_ptr, 0, 0);
}

// This is the core of the program, using raycasting process,
// to render the 3D environment.
// 1.Loop Through Columns (x-axis)
// 2. Calculate Ray Properties:
// For each column, the function calculates the properties of
// the ray (t_raycast) that will be cast from the player's 
//position towards that column
// 3. Perform DDA
// 4. Calculate Wall Properties
// 5. Map Wall Segment to Screen.
// fills the temporary buffer with pixel data for the wall.
// 6. Draw Image on Window.
int	draw_game(t_game *g)
{
	int			x;
	t_raycast	r;
	t_wall		w;

	x = -1;
	draw_floor_ceil(g);
	while (++x < WIN_X)
	{
		calc_ray(g->vec, &r, x);
		dda(&r, g->cub);
		calc_wall(g->vec, &r, &w);
		map_line(g, w, x);
	}
	draw(g);
	return (0);
}
