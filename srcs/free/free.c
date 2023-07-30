/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snocita <snocita@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 11:03:43 by snocita           #+#    #+#             */
/*   Updated: 2023/07/30 11:04:57 by snocita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	free_struct(t_gen *gen)
{
	free(gen->elements[0].path);
	free(gen->elements[1].path);
	free(gen->elements[2].path);
	free(gen->elements[3].path);
	free(gen->elements[4].path);
	free(gen->elements[5].path);
}
