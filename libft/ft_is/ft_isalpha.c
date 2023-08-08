/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snocita <samuelnocita@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 19:09:53 by snocita           #+#    #+#             */
/*   Updated: 2023/06/30 19:10:07 by snocita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <ctype.h>
// #include <stdio.h>
#include "../libft.h"

int	ft_isalpha(int c)
{
	if (!(((c >= 65) && (c <= 90)) || ((c >= 97) && (c <= 122))))
		return (0);
	else
		return (1);
}

// int	main()
// {
// 	char	c;
// 	char	result1;
// 	char	result2;

// 	c = '9';

// 	result1 = ft_isalpha(c);
// 	result2 = isalpha(c);

// 	printf("%d\n", result1);
// 	printf("%d\n", result2);
// 	return (0);
// }
