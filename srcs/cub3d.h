/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busmanov <busmanov@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 07:50:21 by busmanov          #+#    #+#             */
/*   Updated: 2023/08/18 14:19:09 by busmanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libs/minilibx_mac/mlx.h"
# include "../libs/libft/libft.h"

typedef enum e_return {
	SUCCESS	= 0,
	FAIL	= 1,
	UNDEF	= -1,
}	t_return;

typedef enum e_keycode {
	KEY_W	= 13,
	KEY_A	= 0,
	KEY_S	= 1,
	KEY_D	= 2,
	KEY_R	= 124,
	KEY_L	= 123,
	KEY_ESC = 53,
}	t_keycode;

typedef enum e_x_event {
	ON_KEYDOWN = 2,
	ON_DESTROY = 17,
}	t_x_event;

typedef enum e_size {
	PIX = 16,
	WIN_X = 680,
	WIN_Y = 480
}	t_size;

typedef enum e_speed {
	MOVE_SPEED = 1,
	ROT_SPEED = 1
}	t_speed;

typedef struct s_raycast {
	double	cam_x;
	double	raydir_x;
	double	raydir_y;
	int		map_x;
	int		map_y;
	double	deltadist_x;
	double	deltadist_y;
	double	sidedist_x;
	double	sidedist_y;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	double	wall_dist;
}	t_raycast;

typedef struct s_wall {
	int	side;
	int	tex_x;
	int	line_h;
	int	draw_start;
	int	draw_end;
}	t_wall;

typedef struct s_image
{
	void			*img_ptr;
	int				bpp;
	int				size_l;
	int				endian;
	unsigned int	*data;
}			t_image;

typedef struct s_mlx {
	void	*mlx_ptr;
	void	*mlx_win;
	int		**tmp;
	int		*texture[4];
	t_image	img;
}			t_mlx;

typedef struct s_cub3d {
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	int		fl;
	int		ce;
	char	**map;
	int		h;
	int		w;
}	t_cub3d;

typedef struct s_vec {
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	pln_x;
	double	pln_y;
}	t_vec;

typedef struct s_parse {
	int		is_p;
	int		is_e;
	char	*line;
	char	*full_line;
}	t_parse;

typedef struct s_game {
	struct s_cub3d	*cub;
	struct s_mlx	*mlx;
	struct s_vec	*vec;
}	t_game;

//main
void	err_exit(const char *str);
int		close_win(t_mlx *mlx);

//init
void	init_cub3d(t_cub3d *c);
void	init_vec(t_vec *v, char c, int x, int y);
void	init_mlx(t_game *g);

//free
void	free_double_char(char **ptr);
void	free_double_int(int **ptr);
void	free_cub(t_cub3d *cub);

//move
int		key_press(int keycode, t_game *g);

//draw
int		draw_game(t_game *g);

//parse
void	parse(char *av, t_game *g);
void	parse_cub(int fd, t_cub3d *c);
void	parse_map(int fd, t_game *g);
void	set_color(int *texture, char *value);
int		is_empty_line(char *line);
void	skip_empty_line(int fd, char **line);

//raycast
void	calc_ray(t_vec *v, t_raycast *r, int x);
void	dda(t_raycast *r, t_cub3d *c);

//run_util
void	my_xpm_to_img(t_mlx *m, int dir, char *wall);
void	draw_floor_ceil(t_game *g);

#endif
