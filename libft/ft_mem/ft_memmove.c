/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snocita <samuelnocita@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 14:29:44 by snocita           #+#    #+#             */
/*   Updated: 2023/06/30 19:11:03 by snocita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*

	Copies from src into dst up to len chars.
	The process differs slightly depending on
	the dimentions of the two strings as 
	dst can be either greater or smaller
	than src.

*/

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned int	i;

	if (!dst && !src)
		return (NULL);
	if (dst > src)
	{
		while (len > 0)
		{
			((char *)dst)[len - 1] = ((char *)src)[len - 1];
			len--;
		}
	}
	else
	{
		i = 0;
		while (i < len)
		{
			((char *)dst)[i] = ((char *)src)[i];
			i++;
		}
	}
	return (dst);
}

// int	main(void)
// {
// 	char sp[] = "Para";
// 	char dp[] = "Elephant";
// 	char sp1[] = "Para";
// 	char dp1[] = "Elephant";
// 	ft_memmove(dp, sp, 5);
// 	memmove(dp1, sp1, 5);
// 	printf("%s\n", dp);
// 	printf("%s\n", dp+1);
// 	printf("%s\n", dp+2);
// 	printf("%s\n", dp+3);
// 	printf("%s\n", dp+4);
// 	printf("%s\n", dp+5);
// 	printf("%s", dp1);
// }