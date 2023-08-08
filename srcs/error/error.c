/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snocita <snocita@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 11:08:09 by snocita           #+#    #+#             */
/*   Updated: 2023/08/08 13:20:09 by snocita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	error_message(int num)
{
	if (num == 1)
		printf("ERROR!\nWrong Amount of Arguments!\n");
	if (num == 2)
		printf("ERROR!\nInput file format is not compliant\n");
	if (num == 3)
		printf("ERROR!\nError found while validating map\n");
	if (num == 4)
		printf("ERROR\nPath to map is incorrect!\n");
	if (num == 5)
		printf("ERROR!\nMap is not completely surrounded by walls\n");
	if (num == 6)
		printf("ERROR!\nMap is not completely surrounded by walls\n");
	return ((num * 0) + 1);
}
