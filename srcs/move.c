/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busmanov <busmanov@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 07:51:10 by busmanov          #+#    #+#             */
/*   Updated: 2023/08/18 09:45:21 by busmanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>

// simulates rotation of the player's view in the game world by
// applying trigonometric calculations to the direction and plane
// vectors within the t_vec structure
// 1. Store Original Components
// 2. Calculate Rotation Angle
// 3. Update Direction Vector
// This updates the direction of the player's view.
// 4. Update Plane Vector:
// This updates the player's field of view.
static void	rotate(t_vec *v, int opt)
{
	double	dir_x;
	double	pln_x;
	double	rot;

	dir_x = v->dir_x;
	pln_x = v->pln_x;
	rot = (double)ROT_SPEED / 10 * opt;
	v->dir_x = dir_x * cos(rot) - v->dir_y * sin(rot);
	v->dir_y = dir_x * sin(rot) + v->dir_y * cos(rot);
	v->pln_x = pln_x * cos(rot) - v->pln_y * sin(rot);
	v->pln_y = pln_x * sin(rot) + v->pln_y * cos(rot);
}

// performs collision detection with game's map data to ensure
// that player's movement is constrained by obstacles in game
// 1. Calculate Desired Position
// 2. Check Horizontal Movement
// 3. Check Vertical Movement
static void	move_ws(t_vec *v, t_cub3d *c, double opt)
{
	double	des_x;
	double	des_y;

	des_x = v->pos_x + v->dir_x * (double)MOVE_SPEED / 10 * opt;
	des_y = v->pos_y + v->dir_y * (double)MOVE_SPEED / 10 * opt;
	if (c->map[(int)v->pos_y][(int)des_x] == '0')
		v->pos_x = des_x;
	if (c->map[(int)des_y][(int)v->pos_x] == '0')
		v->pos_y = des_y;
}

// The desired x and y positions (des_x and des_y) after the
// movement are calculated based on the current position, plane
// orientation (pln_x and pln_y), and speed (MOVE_SPEED). The 
//opt value determines the direction and magnitude of movement
// The function checks if the horizontal movement is valid by 
//inspecting map at desired y-coordinate and calculated x.
static void	move_ad(t_vec *v, t_cub3d *c, double opt)
{
	double	des_x;
	double	des_y;

	des_x = v->pos_x + v->pln_x * (double)MOVE_SPEED / 10 * opt;
	des_y = v->pos_y + v->pln_y * (double)MOVE_SPEED / 10 * opt;
	if (c->map[(int)v->pos_y][(int)des_x] == '0')
		v->pos_x = des_x;
	if (c->map[(int)des_y][(int)v->pos_x] == '0')
		v->pos_y = des_y;
}

// updating the player's position and orientation in response
// to keyboard input, allowing the player to navigate and 
//interact with the game world.
int	key_press(int keycode, t_game *g)
{
	if (keycode == KEY_W)
		move_ws(g->vec, g->cub, 1);
	if (keycode == KEY_S)
		move_ws(g->vec, g->cub, -1);
	if (keycode == KEY_A)
		move_ad(g->vec, g->cub, -1);
	if (keycode == KEY_D)
		move_ad(g->vec, g->cub, 1);
	if (keycode == KEY_R)
		rotate(g->vec, 1);
	if (keycode == KEY_L)
		rotate(g->vec, -1);
	if (keycode == KEY_ESC)
		close_win(g->mlx);
	return (0);
}
