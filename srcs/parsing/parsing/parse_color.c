/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busmanov <busmanov@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 08:59:19 by busmanov          #+#    #+#             */
/*   Updated: 2023/08/18 12:03:22 by busmanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

//calculate a new color value by replacing
// one of the color channels (red, green, 
//or blue) of an existing color with a new value
// 1. Check Valid RGB Value:
// checks if the value is in range
// 2. Shift Existing Color Value:
// shifting by 8  makes room for the new color
// channel (red, green, or blue) to be placed in
//the least significant byte.
// 3. Combine Existing and New Color Value
// 4. Return Resulting Color Value:
static int	calc_color(int color, int rgb)
{
	if (rgb < 0 || rgb > 255)
		return (-1);
	color <<= 8;
	return (color |= rgb);
}

static int	check_isdigit(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (!ft_isdigit(str[i]))
			return (FAIL);
	}
	return (SUCCESS);
}

//Parsing a string representing an RGB color value
// and converting it into an integer color value.
// 1. Processing RGB Values:
// converts each component with ft_atoi & combines
// them using the calc_color function.
// 2. Removing Newline Character:
// if last char is \n, replace it with null termin.
// 3. Combining RGB Components:
// Iterates through split str components, converting
// & combining into int color val using calc_color func
// 4. Assigning color:
// Assigns calculated color value to specified txt ptr
void	set_color(int *texture, char *value)
{
	char	**split;
	int		color;
	int		i;

	i = -1;
	color = 0;
	if (value[ft_strlen(value) - 1] == '\n')
		value[ft_strlen(value) - 1] = '\0';
	split = ft_split(value, ',');
	if (!split)
		err_exit(0);
	while (split[++i])
	{
		if (i < 3 && check_isdigit(split[i]))
			break ;
		color = calc_color(color, ft_atoi(split[i]));
		if (color < 0)
			break ;
	}
	free_double_char(split);
	if (color < 0 || i != 3)
		err_exit("Invalid color.");
	*texture = color;
}
