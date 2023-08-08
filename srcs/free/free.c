/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snocita <snocita@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 11:03:43 by snocita           #+#    #+#             */
/*   Updated: 2023/08/08 13:17:30 by snocita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	free_struct(t_gen *gen, int ret)
{
	t_gen	*ref;

	ref = gen;
	free(ref->elements[0].path);
	free(ref->elements[1].path);
	free(ref->elements[2].path);
	free(ref->elements[3].path);
	free(ref->elements[4].path);
	free(ref->elements[5].path);
	free(ref->map_file);
	free(ref->only_map_flat);
	free_double_arr(ref->buffered_map);
	free(ref);
	return (ret);
}
