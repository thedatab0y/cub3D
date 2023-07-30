/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snocita <snocita@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 09:00:57 by snocita           #+#    #+#             */
/*   Updated: 2023/07/30 14:14:53 by snocita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define SUCCESS 0
# define FAILURE 1

# include "../libft/libft.h"
# include <stdio.h>
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
	char	*buffered_map;
}			t_gen;

// #include "../srcs/minilibx-linux/mlx_int.h"
// #include "../srcs/minilibx-linux/mlx.h"

int		error_message(int num);
int		check_format(char *map_file_name);
int		check_compliancy(int ac, char **av);
int		check_element(t_gen *gen, char *buf);
int		check_file_content(char *map, t_gen *gen);
int		main(int ac, char **av);
int		parse(t_gen *gen, char *buf);
void	free_struct(t_gen *gen);
int		get_length(char *path);
char	*get_path(char *element, int mode);
void	register_in_struct(t_gen *gen, char *buf, char letter, int mode);

#endif