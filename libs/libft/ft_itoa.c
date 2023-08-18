/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busmanov <busmanov@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 15:15:28 by busmanov          #+#    #+#             */
/*   Updated: 2021/12/30 19:43:07 by busmanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_sign(long int n)
{
	int	sign;

	sign = 1;
	if (n < 0)
		sign = -1;
	return (sign);
}

static char	*ft_null(int n, char *res)
{
	if (n == 0)
	{
		res[0] = '0';
		res[1] = '\0';
		return (res);
	}
	return (res);
}

static int	ft_getlen(long int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		len;
	int		sign;
	char	*res;

	sign = ft_sign(n);
	len = ft_getlen(n);
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	ft_null(n, res);
	res[len] = '\0';
	while (n != 0)
	{
		res[--len] = (char)((n % 10) * sign + 48);
		n = n / 10;
	}
	len--;
	if (sign < 0)
		res[0] = '-';
	return (res);
}
