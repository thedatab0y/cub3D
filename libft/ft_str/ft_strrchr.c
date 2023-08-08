/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snocita <samuelnocita@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 16:42:44 by snocita           #+#    #+#             */
/*   Updated: 2023/06/30 19:12:05 by snocita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*

	Finds the last instance of a character

*/

char	*ft_strrchr(const char *s, int c)
{
	char		*last;
	char		find;
	size_t		i;

	last = (char *)s;
	find = (char)c;
	i = ft_strlen(s);
	while (i > 0)
	{
		if (last[i] == find)
			return (last + i);
		i--;
	}
	if (last[i] == find)
		return (last);
	return (NULL);
}

// int	main(void)
// {
// 	char s[] = "tripouille";
// 	char s2[] = "ltripouiel";
// 	char s3[] = "";

// 	char *d1 = strrchr(src, '\xe2\x80\x93');
// 	char *d2 = ft_strrchr(src, '\xe2\x80\x93');

// 	printf("%s\n", d1);
// 	printf("%s\n", d2);
// }
