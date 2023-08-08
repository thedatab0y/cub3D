/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snocita <samuelnocita@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 19:10:01 by snocita           #+#    #+#             */
/*   Updated: 2023/06/30 19:10:13 by snocita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <ctype.h>
// #include <stdio.h>
#include "../libft.h"

int	ft_isdigit(int c)
{
	if (!((c >= '0') && (c <= '9')))
		return (0);
	else
		return (1);
}

// int	main()
// {
// 	char	c;
// 	char	result1;
// 	char	result2;

// 	c = ' ';

// 	result1 = ft_isdigit(c);
// 	result2 = isdigit(c);

// 	printf("%d\n", result1);
// 	printf("%d\n", result2);
// 	return (0);
// }