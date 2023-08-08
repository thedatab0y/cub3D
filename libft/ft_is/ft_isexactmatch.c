/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isexactmatch.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snocita <snocita@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 14:01:35 by snocita           #+#    #+#             */
/*   Updated: 2023/07/28 17:37:15 by snocita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	is_exact_match(char *x_str, char *y_str)
{
	int		is_x_equal_to_y;
	int		is_y_equal_to_x;
	size_t	len_x;
	size_t	len_y;

	len_x = ft_strlen(x_str);
	len_y = ft_strlen(y_str);
	if (len_x == 0 || len_y == 0)
		return (0);
	is_x_equal_to_y = ft_strncmp(x_str, y_str, len_x);
	is_y_equal_to_x = ft_strncmp(x_str, y_str, len_y);
	if (is_x_equal_to_y == 0 && is_y_equal_to_x == 0)
		return (1);
	return (0);
}
