/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snocita <samuelnocita@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 19:09:57 by snocita           #+#    #+#             */
/*   Updated: 2023/06/30 19:10:10 by snocita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
// #include <ctype.h>
#include "../libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}

// int	main()
// {
// 	int result;
// 	int result1;

// 	result = ft_isascii('F');
// 	result1 = isascii('F');

// 	printf("%d", result);
// 	printf("%d", result1);
// 	return (0);
// }