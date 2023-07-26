/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busmanov <busmanov@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 13:23:53 by busmanov          #+#    #+#             */
/*   Updated: 2023/07/26 12:55:54 by busmanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_strlen(char string [])
{
	int		count;
	int		i;

	count = 0;
	i = 0;
	while (string [i])
	{
		count++;
		i++;
	}
	return (count);
}
