/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snocita <samuelnocita@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 14:35:35 by snocita           #+#    #+#             */
/*   Updated: 2023/06/30 19:10:55 by snocita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
// #include <stdio.h>
// #include <string.h>

/*

	Copies from src into dst up to n chars.

*/

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	char		*dp;
	const char	*sp;

	dp = dst;
	sp = src;
	if (!dp && !sp)
		return (NULL);
	while (n > 0)
	{
		*dp = *sp;
		dp++;
		sp++;
		n--;
	}
	return (dst);
}
