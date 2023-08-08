/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_double_arr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snocita <snocita@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 15:00:07 by snocita           #+#    #+#             */
/*   Updated: 2023/07/22 15:00:37 by snocita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	free_double_arr(char **str)
{
	char	**temp;
	int		i;

	i = 0;
	if (!str)
		return ;
	temp = str;
	while (str[i])
	{
		if (str[i] && (str[i] != NULL))
			free(str[i]);
		i++;
	}
	if (temp != NULL)
		free(temp);
	return ;
}
