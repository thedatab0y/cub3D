/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busmanov <busmanov@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 14:04:41 by busmanov          #+#    #+#             */
/*   Updated: 2022/01/05 12:47:34 by busmanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	long int	result;
	int			x;
	int			sign;
	long int	old_num;

	result = 0;
	sign = 1;
	x = 0;
	while (str[x] == 32 || (str[x] >= 9 && str[x] <= 13))
		x++;
	if (str[x] == '-')
		sign *= -1;
	if (str[x] == '+' || str[x] == '-')
		x++;
	while (str[x] >= '0' && str[x] <= '9')
	{
		old_num = result;
		result = result * 10 + str[x] - '0';
		if ((old_num < 0 && result > 0) || (old_num > 0 && result < 0))
			return ((sign == 1) * -1);
		x++;
	}
	return (result * sign);
}
