/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snocita <samuelnocita@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 19:09:46 by snocita           #+#    #+#             */
/*   Updated: 2023/06/30 19:10:03 by snocita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <ctype.h>
#include <stdio.h>

// int	isalnum(int c);
// int	ft_isalpha(int c);
// int	ft_isdigit(int c);

int	ft_isalnum(int c)
{
	if (ft_isalpha(c) || ft_isdigit(c))
		return (1);
	else
		return (0);
}

// int	main(void)
// {
// 	char	c;
// 	char	result1;
// 	char	result2;

// 	c = 8;

// 	result1 = ft_isalnum(c);
// 	result2 = isalnum(c);

// 	printf("%d\n", result1);
// 	printf("%d\n", result2);
// 	return (0);
// }
