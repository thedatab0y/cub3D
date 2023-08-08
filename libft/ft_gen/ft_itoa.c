/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snocita <samuelnocita@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 20:24:31 by snocita           #+#    #+#             */
/*   Updated: 2023/06/30 19:09:47 by snocita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
	Takes an int, returns it as a string.

		-482039
		"-482039"

	(ft_nb_len)->
	It first counts the int digit length by:

		- adding one if the number is negative
		- add one until the number is NULL and 
		each round divides it by 10 thus shifting.

	(ft_itoa)->
		- array init. with length digits + '\0'
		- return NULL if string is empty
		- first letter is '-' if nb is negative
		- first letter is '0' if nb is '-0'
		- numbers are allocated backwards using
			a % 10 to get the last num and then
			/ 10 to shift backwards -> 329 9 2 3
	
*/

size_t	ft_nb_len(int nb)
{
	int	len;

	len = 0;
	if (nb <= 0)
		len++;
	while (nb)
	{
		len++;
		nb = nb / 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*str;
	long	nb;

	len = ft_nb_len(n);
	nb = n;
	str = malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	if (nb < 0)
	{
		str[0] = '-';
		nb = -nb;
	}
	if (nb == 0)
		str[0] = '0';
	str[len--] = '\0';
	while (nb)
	{
		str[len] = nb % 10 + '0';
		len--;
		nb = nb / 10;
	}
	return (str);
}
