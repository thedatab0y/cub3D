/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snocita <samuelnocita@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 19:10:04 by snocita           #+#    #+#             */
/*   Updated: 2023/06/30 19:10:17 by snocita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
// #include <stdio.h>
// #include <ctype.h>

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}

// int	main()
// {
// 	int result;
// 	int result1;
// 	int result3;
// 	int result4;

// 	result = ft_isprint('F');
// 	result1 = ft_isprint(25);
// 	result3 = isprint(25);
// 	result4 = isprint('F');

// 	printf("%d", result);
// 	printf("%d", result1);
// 	printf("%d", result3);
// 	printf("%d", result4);
// 	return (0);
// }