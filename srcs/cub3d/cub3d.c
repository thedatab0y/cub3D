/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snocita <snocita@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 11:33:39 by snocita           #+#    #+#             */
/*   Updated: 2023/08/08 13:44:18 by snocita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	init_gen_struct(t_gen	*gen)
{
	int	i;

	i = 0;
	while (i < 6)
		gen->elements[i++].path = NULL;
	gen->el_num = 0;
	gen->height = 0;
	gen->width = 0;
	gen->map_file = NULL;
	gen->only_map_flat = NULL;
	gen->buffered_map = NULL;
	gen->mlx_ptr = NULL;
	gen->mlx_win_ptr = NULL;
}

void	parse_map(t_gen	*gen)
{
	int	i;
	int	indicator;

	i = 0;
	indicator = 0;
	while (gen->map_file[i])
	{
		if (gen->map_file[i] == '.' || gen->map_file[i] == 'F'
			|| gen->map_file[i] == 'C')
			indicator++;
		if (indicator == 6)
			break ;
		i++;
	}
	while (gen->map_file[i] != '\n')
		i++;
	i++;
	gen->only_map_flat = ft_substr(gen->map_file, i, ft_strlen(gen->map_file));
	gen->buffered_map = ft_split(gen->only_map_flat, '\n');
}

int	main(int ac, char **av)
{
	t_gen	*gen;
	int		i;
	int		j;

	i = 0;
	j = 0;
	gen = malloc(sizeof(t_gen));
	init_gen_struct(gen);
	if (compliancy_check(ac, av) != SUCCESS)
		return (FAILURE);
	else
		printf("\tPassed argument_check\n\tPassed format check\n");
	if (check_file_content(av[1], gen) != SUCCESS)
		return (FAILURE);
	else
		printf("\tPassed map_registration\n\tPassed NSWEFC check\n");
	parse_map(gen);
	print_matrixed_map(gen);
	if (wall_test(gen) != SUCCESS)
		return (free_struct(gen, FAILURE));
	else
		printf("\tPassed wall_test\n");
	return (free_struct(gen, SUCCESS));
}
