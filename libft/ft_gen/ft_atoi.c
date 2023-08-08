/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snocita <samuelnocita@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 14:34:22 by snocita           #+#    #+#             */
/*   Updated: 2023/06/30 19:09:21 by snocita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
	Takes a string, returns an int without special 
	chars or spaces, negative or positive 
	depending of the '-' (if odds int is negative).

		 -++--+48203947d147
		-48203947
*/

int	ft_atoi(const char *str)
{
	int	i;
	int	result;
	int	sign;

	i = 0;
	result = 0;
	sign = 1;
	while (str[i] && (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'
			|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r'))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = sign * (-1);
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10;
		result = result + str[i] - '0';
		i++;
	}
	return (result * sign);
}
