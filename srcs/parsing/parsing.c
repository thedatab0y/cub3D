/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snocita <snocita@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 11:05:44 by snocita           #+#    #+#             */
/*   Updated: 2023/07/30 11:14:20 by snocita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	parse(t_gen *gen, char *buf)
{
	int	ret;

	ret = SUCCESS;
	while (*buf)
	{
		if (check_element(gen, buf) == FAILURE)
			ret = FAILURE;
		buf++;
	}
	return (ret);
}

int	check_element(t_gen *gen, char *buf)
{
	int	ret;
	int	i;

	i = 0;
	ret = SUCCESS;
	if (*buf == 'N')
	{
		buf++;
	}
	if (*buf == 'N')
	{
		buf++;
		if (*buf == 'O' && *(buf + 1) == ' ')
		{
			register_in_struct(gen, buf, 'N', 0);
			ret++;
		}
	}
	else if (*buf == 'S')
	{
		buf++;
		if (*buf == 'O' && *(buf + 1) == ' ')
		{
			register_in_struct(gen, buf, 'S', 0);
			ret++;
		}
	}
	else if (*buf == 'E')
	{
		buf++;
		if (*buf == 'A' && *(buf + 1) == ' ')
		{
			register_in_struct(gen, buf, 'E', 0);
			ret++;
		}
	}
	else if (*buf == 'W')
	{
		buf++;
		if (*buf == 'E' && *(buf + 1) == ' ')
		{
			register_in_struct(gen, buf, 'W', 0);
			ret++;
		}
	}
	else if (*buf == 'F')
	{
		buf++;
		if (*buf == ' ')
		{
			register_in_struct(gen, buf, 'F', 1);
			ret++;
		}
	}
	else if (*buf == 'C')
	{
		buf++;
		if (*buf == ' ')
		{
			register_in_struct(gen, buf, 'C', 1);
			ret++;
		}
	}
	gen->buffered_map = buf;
	if (gen->el_num == 6)
		return (ret * 0);
	else
		return (FAILURE);
}

void	register_in_struct(t_gen *gen, char *buf, char letter, int mode)
{
	printf("LETTER IS: %c\n", letter);
	gen->elements[gen->el_num].id = letter;
	gen->elements[gen->el_num].path = get_path(buf, mode);
	printf("New Element found! %c\n", gen->elements[gen->el_num].id);
	printf("PATH: %s\n", gen->elements[gen->el_num].path);
	gen->el_num++;
	printf("NUMBER: %d\n", gen->el_num);
}
