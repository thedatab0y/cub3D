/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snocita <snocita@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 13:40:08 by snocita           #+#    #+#             */
/*   Updated: 2023/08/08 13:44:38 by snocita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	view_registered(t_gen	*gen)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		printf("\nElement found: %c\n", gen->elements[i].id);
		printf("\tPATH: ->%s\n", gen->elements[i].path);
		i++;
	}
}

void	print_matrixed_map(t_gen	*gen)
{
	int	i;

	i = 0;
	printf("\nFINAL MATRIXED MAP:\n\n");
	while (gen->buffered_map[i])
		printf("%s\n", gen->buffered_map[i++]);
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
	char	*ret;
	int		length;

	ret = NULL;
	element++;
	while (*element == ' ' || *element == '\t')
		element++;
	if (*element != '.' && mode != 1)
		return (NULL);
	if ((*element < '0' && *element > '9') && mode != 0)
		return (NULL);
	length = get_length(element);
	ret = ft_substr(element, 0, length);
	return (ret);
}
