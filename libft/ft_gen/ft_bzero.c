/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snocita <samuelnocita@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 18:36:22 by snocita           #+#    #+#             */
/*   Updated: 2023/06/30 19:09:36 by snocita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
// #include <string.h>
// #include <stdio.h>
// #include <unistd.h>

/*

	Returns 0 long as much as len

	if b = str* && len = 3
	
	-> 000

*/

void	*ft_memset(void *b, int c, size_t len);

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, '\0', n);
}

// void	printthefuckingstring(char *str)
// {
// 	int	i;

// 	i=0;
// 	while(i != 20)
// 	{
// 		char c = str[i];
// 		write(1, &c, 1);
// 		i++;
// 	}
// }

// int	main()
// {
// 	char str[20] = "ALOHAasddsad";
// 	char str1[20] = "ALOHAasddsad";
// 	ft_bzero(str, 6);
// 	printf("%s\n", str);
// 	printthefuckingstring(str);
// 	bzero(str1, 6);
// 	printf("%s\n", str1);

// 	printthefuckingstring(str1);

// 	return (0);
// }