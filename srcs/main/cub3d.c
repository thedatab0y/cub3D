/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snocita <snocita@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 08:45:35 by snocita           #+#    #+#             */
/*   Updated: 2023/07/30 14:16:43 by snocita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	check_format(char *map_file_name)
{
	size_t	filename_len;
	int		ret;

	ret = SUCCESS;
	filename_len = ft_strlen(map_file_name);
	if (filename_len < 5 || (ft_strchr(map_file_name, '.') == NULL))
		ret = error_message(2);
	while (*map_file_name != '.')
		map_file_name++;
	if ((*(map_file_name + 1) != 'c') || (*(map_file_name + 2) != 'u')
		|| (*(map_file_name + 3) != 'b'))
		ret = error_message(2);
	printf("Passed this test\n");
	return (ret);
}

int	get_length(char *path)
{
	int	i;

	i = 0;
	while (*path)
	{
		if (*path == 32 || *path == 9 || *path == '\n')
			break ;
		path++;
		i++;
	}
	return (i);
}

char	*get_path(char *element, int mode)
{
	element++;
	while (*element == 32 || *element == 9)
		element++;
	if (*element != '.' && mode != 1)
		return (NULL);
	if ((*element < '0' && *element > '9') && mode != 0)
		return (NULL);
	return (ft_substr(element, 0, get_length(element)));
}

int	check_file_content(char *map, t_gen *gen)
{
	int		fd;
	char	buf[999];

	fd = open(map, O_RDONLY);
	read(fd, buf, 999);
	parse(gen, buf);
	gen->buffered_map = ft_strdup(buf);
	// printf("!!LETTER: %c\n", gen->buffered_map[1]);
	printf("Parsing completed!\n");
	close(fd);
	return (SUCCESS);
}

int	compliancy_check(int ac, char **av, t_gen *gen)
{
	int	i;
	int	ret;

	ret = SUCCESS;
	if (ac != 2)
		ret = error_message(1);
	else if (check_format(av[1]) != SUCCESS)
	{
		printf("hello\n");
		ret = FAILURE;
	}
	check_file_content(av[1], gen);
	return (ret);
}

int	perimeter_check(t_gen   *gen)
{
	int	ret;
	int	i;

	ret = SUCCESS;
	i = 0;
	while (gen->buffered_map[i])
	{
		if (!gen->buffered_map || ft_strchr(gen->buffered_map, 'N') == NULL
			|| ft_strchr(gen->buffered_map, 'S') == NULL
			|| ft_strchr(gen->buffered_map, 'E') == NULL
			|| ft_strchr(gen->buffered_map, 'W') == NULL)
			ret = error_message(3);
	}
	return (ret);
}

int	wall_test(char	*squished_map)
{
	int	ret;

	ret = SUCCESS;
	printf("Entered wall test\n");
	while (*squished_map)
	{
		while (*squished_map == ' ' || *squished_map == '\t')
		{
			if (*squished_map == ' ' || *squished_map == '\t')
				printf("Space or Tab\n");
			squished_map++;
		}
		if (*squished_map != '1')
		{
			ret = error_message(4);
			break ;
		}
		else
			printf("First is wall\n");
		while ((*squished_map == '1') || (*squished_map == '0'))
		{
			if (*squished_map == '\n')
				break ;
			squished_map++;
		}
		squished_map++;
	}
	return (ret);
}

// TODO:
//  MAP VALIDATION
//       - file must be *.cub
//       - CHAR-type must be: 3
//             -> 0 for walking space, 1 for wall
//             -> AND (N or S or E or W)
//             -> Map must be fullly brodered by 1s
//  CLEAN EXIT
//  ERROR HANDLING
//       - should return "Error\n" + CHOSEN message if anything is not compliant
//       - input -> NO SO WE  EA F C and ultimately MAP
//  TEXTURE SETUP
int	main(int ac, char **av)
{
	t_gen	gen;
	void	*mlx_ptr;
	int		i;

	i = 0;
	gen.el_num = 0;
	gen.buffered_map = NULL;
	while (i < 6)
		gen.elements[i++].path = NULL;
	if (compliancy_check(ac, av, &gen) != SUCCESS)
		return (1);
	// if (perimeter_check(&gen) != SUCCESS)
	// 	return (FAILURE);
	// else
	if (wall_test(gen.buffered_map) == SUCCESS)
		printf("Good to go!\n");
	else
		printf("Not correct!\n");
	mlx_ptr = mlx_init();
	mlx_destroy_display(mlx_ptr);
	free(mlx_ptr);
	free_struct(&gen);
	return (SUCCESS);
}
