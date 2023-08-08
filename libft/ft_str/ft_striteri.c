/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snocita <samuelnocita@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 11:15:33 by snocita           #+#    #+#             */
/*   Updated: 2023/06/30 19:11:42 by snocita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*

	takes a string, and a function.
	applies the function in each
	character in the string.

*/

// void	print(unsigned int i, char *s)
// {
// 	printf("%c", s[i]);
// }

// void	iter(unsigned int i, char *s)
// {
// 	*s += i;
// }

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	index;

	if (!s || !f)
		return ;
	index = 0;
	while (s[index])
	{
		f(index, s + index);
		index++;
	}
}

// int	main(void)
// {
// 	char	str[] = "0000000000";

// 	ft_striteri(str, iter);
// }
