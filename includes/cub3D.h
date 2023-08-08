/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snocita <snocita@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 09:00:57 by snocita           #+#    #+#             */
/*   Updated: 2023/08/08 13:59:49 by snocita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define SUCCESS 0
# define FAILURE 1

# include "../libft/libft.h"
# include <stdio.h>
# include <limits.h>
# include <fcntl.h>
# include <limits.h>
# include <stdlib.h>
# include "../minilibx_mac/mlx.h"
# include "../libft/libft.h"

typedef struct s_el		t_el;
typedef struct s_gen	t_gen;

typedef struct s_el
{
	char	id;
	char	*path;
}			t_el;

typedef struct s_gen
{
	t_el	elements[7];
	int		el_num;
	char	*map_file;
	char	*only_map_flat;
	char	**buffered_map;
	void	*mlx_ptr;
	void	*mlx_win_ptr;
	int		height;
	int		width;
	
	// void	*img_exit;
	// int		map_w;
	// int		map_h;
	// int		img_w;
	// int		img_h;
	// int		n_colect;
	// int		n_player;
	// int		n_exit;
	// int		endgame;
}	t_gen;

//CUB3D
int		main(int ac, char **av);
void	init_gen_struct(t_gen	*gen);
//PARSING
int		compliancy_check(int ac, char **av);
int		check_format(char *map_file_name);
int		check_file_content(char *map, t_gen *gen);
void	parse_map(t_gen	*gen);
int		get_length(char *path);
char	*get_path(char *element, int mode);
void	register_in_struct(t_gen *gen, char *buf, char letter, int mode);
int		locate_nsewfc(char	*buf, t_gen	*gen);
void	view_registered(t_gen	*gen);
void	print_matrixed_map(t_gen	*gen);
//WALL
int		wall_test(t_gen	*gen);
int		get_dimensions(t_gen	*gen);
int		ft_up_down(char	**map, int y, int x);
int		ft_left_right(char	**map, int y, int x);
int		ft_corners(char	**map, int y, int x);
int		ft_top_leftright(char **map, int *top_left, int *top_right);
//int		ft_bot_leftright(char **map, int *top_left, int *top_right)
//ERROR
int		error_message(int num);
//UTILS
void	view_registered(t_gen	*gen);
void	print_matrixed_map(t_gen	*gen);
int		get_length(char *path);
char	*get_path(char *element, int mode);
//FREE
int		free_struct(t_gen *gen, int ret);


#endif