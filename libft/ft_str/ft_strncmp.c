/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snocita <samuelnocita@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 14:58:27 by snocita           #+#    #+#             */
/*   Updated: 2023/06/30 19:11:58 by snocita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*

	compares the two string par
	returning the difference 
	between them that is either
	0 or negative or positive.
	A non-zero return means the
	strings differs.

*/

int	ft_strncmp(const char *str1, const char *str2, size_t num)
{
	size_t				i;
	const unsigned char	*st1;
	const unsigned char	*st2;

	i = 0;
	st1 = (const unsigned char *) str1;
	st2 = (const unsigned char *) str2;
	while ((i < num) && ((*st1 != '\0') || (*st2 != '\0')))
	{
		if (*st1 == *st2)
		{
			st1++;
			st2++;
			i++;
		}
		else
		{
			return (*st1 - *st2);
		}
	}
	return (0);
}

// int	main(void)
// {
// 	const char	s1[] = "1234";
// 	const char	s2[] = "1234";
// 	size_t		n;

// 	n = 2;
// 	printf("Result: %d", ft_strncmp(s1, s2, n));
// 	return (0);
// }
