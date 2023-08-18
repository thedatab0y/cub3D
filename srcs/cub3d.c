/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busmanov <busmanov@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 07:51:02 by busmanov          #+#    #+#             */
/*   Updated: 2023/08/18 09:07:06 by busmanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

//prints error message
void	err_exit(const char *str)
{
	if (str)
		printf("Error\n%s\n", str);
	else
		perror("Error\n");
	exit(1);
}

//closes the window with a message
int	close_win(t_mlx *mlx)
{
	mlx_clear_window(mlx->mlx_ptr, mlx->mlx_win);
	mlx_destroy_window(mlx->mlx_ptr, mlx->mlx_win);
	printf("See you later!\n");
	exit(0);
}

// Initialize MLX Library & Check MLX Initialization
// Create Window & Check Window Creation
// Initialize Graphics Components & Register Loop Hook
// Register Key Press Hook & Register Window Close Hook
// FUNCTION initializes graphics system usingMLX, createswindow,
// sets up event hooks for drawing, key presses, and window closing,
// initializes graphics components, and enters the main event loop.
// This loop is where the game's visuals are updated and rendered, 
// keyboard input is handled,& cleanup operations occur when game is closed.
static void	start_cub3d3d(t_game *g)
{
	g->mlx->mlx_ptr = mlx_init();
	if (!g->mlx->mlx_ptr)
		err_exit("mlx failed.");
	g->mlx->mlx_win = mlx_new_window(g->mlx->mlx_ptr, WIN_X, WIN_Y, "cub3D");
	if (!g->mlx->mlx_win)
		err_exit("mlx failed.");
	init_mlx(g);
	mlx_loop_hook(g->mlx->mlx_ptr, &draw_game, g);
	mlx_hook(g->mlx->mlx_win, ON_KEYDOWN, 0, &key_press, g);
	mlx_hook(g->mlx->mlx_win, ON_DESTROY, 0, &close_win, g->mlx);
	mlx_loop(g->mlx->mlx_ptr);
}

// Sets up basic data structures, parses input file, and starts
// the Cub3D game using the provided data and functions.
// 1. Command-Line Argument Check
// 2. Structure Assignments
// 3. Parsing
// 4. Starting the Game
int	main(int argc, char **argv)
{
	t_game	game;
	t_cub3d	cub;
	t_mlx	mlx;
	t_vec	vec;

	if (argc != 2)
		err_exit("TWO ARGUMENTS ONLY!!");
	game.cub = &cub;
	game.vec = &vec;
	game.mlx = &mlx;
	parse(argv[1], &game);
	start_cub3d3d(&game);
	return (0);
}
