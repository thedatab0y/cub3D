/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snocita <samuelnocita@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 09:00:57 by snocita           #+#    #+#             */
/*   Updated: 2023/07/29 14:20:34 by snocita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

#define SUCCESS 0
#define FAILURE 1

typedef struct s_el t_el;
typedef struct s_gen t_gen;

typedef struct s_el
{
    char id;
    char *path;
} t_el;

typedef struct s_gen
{
    t_el elements[7];
    int el_num;
} t_gen;

#include "../libft/libft.h"
#include <stdio.h>
#include <fcntl.h>
#include <limits.h>
#include <stdlib.h>
#include "../minilibx-linux/mlx_int.h"
#include "../minilibx-linux/mlx.h"

int error_message(int num);
int check_format(char *map_file_name);
int check_compliancy(int ac, char **av);
int check_file_content(char *map, t_gen *gen);
int main(int ac, char **av);

#endif