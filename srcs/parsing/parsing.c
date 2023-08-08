/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snocita <snocita@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 11:05:44 by snocita           #+#    #+#             */
/*   Updated: 2023/08/08 13:55:28 by snocita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	register_in_struct(t_gen *gen, char *buf, char letter, int mode)
{
	gen->elements[gen->el_num].id = letter;
	gen->elements[gen->el_num].path = get_path(buf, mode);
	gen->el_num++;
}

int	locate_nsewfc(char	*buf, t_gen	*gen)
{
	int	mode;

	mode = 0;
	while (*buf)
	{
		if (*buf == 'N' && (((*(buf + 1) == 'O') && (*(buf + 2) == ' '))))
			register_in_struct(gen, ++buf, 'N', mode);
		else if (*buf == 'S' && (((*(buf + 1) == 'O') && (*(buf + 2) == ' '))))
			register_in_struct(gen, ++buf, 'S', mode);
		else if (*buf == 'E' && (((*(buf + 1) == 'A') && (*(buf + 2) == ' '))))
			register_in_struct(gen, ++buf, 'E', mode);
		else if (*buf == 'W' && (((*(buf + 1) == 'E') && (*(buf + 2) == ' '))))
			register_in_struct(gen, ++buf, 'W', mode);
		else if (*buf == 'F' && (*(buf + 1) == ' '))
			register_in_struct(gen, buf, 'F', 1);
		else if (*buf == 'C' && (*(buf + 1) == ' '))
			register_in_struct(gen, buf, 'C', 1);
		buf++;
	}
	if (gen->el_num != 6)
		return (FAILURE);
	view_registered(gen);
	return (FAILURE);
}

/**
 * @brief opens map file, reads it into buf[999]
 * and strduplicates it into gen->map_file AND
 * locates N-S-E-W-F-C
*/
int	check_file_content(char *map, t_gen *gen)
{
	int		ret;
	int		fd;
	char	buf[999];
	ssize_t	bytes_read;

	ret = SUCCESS;
	fd = open(map, O_RDONLY);
	if (fd < 0)
		ret = error_message(4);
	else
	{
		bytes_read = read(fd, buf, 998);
		if (bytes_read > 0)
		{
			buf[bytes_read] = '\0';
			gen->map_file = ft_strdup(buf);
			locate_nsewfc(gen->map_file, gen);
		}
		else
			ret = error_message(5);
		close(fd);
	}
	return (ret);
}

/**
 * @brief checks that the file format is ".cub"
*/
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
	return (ret);
}

/**
 * Tests:
 * 		- that the argcount is 2
 * 		- that the file is the correct ".ber" format
 * 		NOPE-> that each element requested is present and registered in struct
*/
int	compliancy_check(int ac, char **av)
{
	int	ret;

	ret = SUCCESS;
	if (ac != 2)
		ret = error_message(1);
	else if (check_format(av[1]) != SUCCESS)
		ret = FAILURE;
	return (ret);
}