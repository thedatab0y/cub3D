/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busmanov <busmanov@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 07:51:35 by busmanov          #+#    #+#             */
/*   Updated: 2023/08/18 10:05:22 by busmanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>

//initializing variables and calculations related to raycasting
// determine what objects are visible on the screen
// 1. Calculate Camera Plane Coordinate (cam_x)
// 2. Calculate Ray Direction (raydir_x and raydir_y)
// 3. Calculate Initial Map Cell Coordinates (map_x and map_y)
// 4. Calculate Delta Distances (deltadist_x and deltadist_y)
// 5.Initialize Hit Flag:
// Flag is used to indicate whether the ray has hit an obstacle.
static void	init_raycast(t_vec *v, t_raycast *r, int x)
{
	r->cam_x = 2 * x / (double)WIN_X - 1;
	r->raydir_x = v->dir_x + v->pln_x * r->cam_x;
	r->raydir_y = v->dir_y + v->pln_y * r->cam_x;
	r->map_x = (int)v->pos_x;
	r->map_y = (int)v->pos_y;
	r->deltadist_x = fabs(1 / r->raydir_x);
	r->deltadist_y = fabs(1 / r->raydir_y);
	r->hit = 0;
}

//responsible for setting up step sizes and side distances for 
//each axis of the ray
// 1. Calculate Step Size and Side Distances for X-Axis:
// Depending on the direction of the ray (raydir_x), the step size
// (step_x) is set to either -1 (if the ray direction is negative)
// or 1 (if the ray direction is positive).
// The side distance (sidedist_x) for the x-axis is calculated based
// on the player's position relative to the map cell (map_x), 
//multiplied by the calculated delta distance (deltadist_x). This
// side distance represents the distance from the player's position 
//to the nearest vertical grid line that the ray hits.
void	calc_ray(t_vec *v, t_raycast *r, int x)
{
	init_raycast(v, r, x);
	if (r->raydir_x < 0)
	{
		r->step_x = -1;
		r->sidedist_x = (v->pos_x - r->map_x) * r->deltadist_x;
	}
	else
	{
		r->step_x = 1;
		r->sidedist_x = (r->map_x + 1.0 - v->pos_x) * r->deltadist_x;
	}
	if (r->raydir_y < 0)
	{
		r->step_y = -1;
		r->sidedist_y = (v->pos_y - r->map_y) * r->deltadist_y;
	}
	else
	{
		r->step_y = 1;
		r->sidedist_y = (r->map_y + 1.0 - v->pos_y) * r->deltadist_y;
	}
}

//allows the ray to traverse through the map and identify the point
// of collision with walls or obstacles.
// r->side value is also crucial for further calculations, such as
// calculating wall textures and depth.
//The DDA algorithm involves comparing side distances 
//(r->sidedist_x and r->sidedist_y) to determine whether the
// next step should be taken along the x-axis or the y-axis.
// he function checks whether the current map cell contains
// a wall ('1' indicates a wall).
// If a wall is detected, the r->hit flag is set 
void	dda(t_raycast *r, t_cub3d *c)
{
	while (r->hit == 0)
	{
		if (r->sidedist_x < r->sidedist_y)
		{
			r->sidedist_x += r->deltadist_x;
			r->map_x += r->step_x;
			if (r->step_x == 1)
				r->side = 0;
			else
				r->side = 1;
		}
		else
		{
			r->sidedist_y += r->deltadist_y;
			r->map_y += r->step_y;
			if (r->step_y == 1)
				r->side = 2;
			else
				r->side = 3;
		}
		if (c->map[r->map_y][r->map_x] == '1')
			r->hit = 1;
	}
}
