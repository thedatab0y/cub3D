/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snocita <samuelnocita@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 17:46:39 by snocita           #+#    #+#             */
/*   Updated: 2023/06/30 19:11:06 by snocita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
// #include <stdio.h>

/*

	Returns one int long as much as len
	if c = 1 && b = str* && len = 3
	-> 111

*/

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*p;

	p = b;
	while (len > 0)
	{
		*p = c;
		p++;
		len--;
	}
	return (b);
}

// int main(void)
// {
// 	int str[50] = {3,5,6,78,44};
// 	printf("%s", ft_memset(str, 'a', 3));

// 	return (0);
// }