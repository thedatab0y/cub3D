/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snocita <samuelnocita@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 17:58:06 by snocita           #+#    #+#             */
/*   Updated: 2023/06/30 19:09:56 by snocita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
// #include <stdio.h>

int	ft_isuppercase(int c);
int	ft_tolower(int c);

int	ft_isuppercase(int c)
{
	if (c >= 65 && c <= 90)
		return (1);
	return (0);
}

int	ft_tolower(int c)
{
	if (ft_isuppercase(c))
	{
		c += 32;
		return (c);
	}
	return (c);
}

// int	main(void)
// {
// 	printf("%c", ft_tolower('E'));
// }
