/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snocita <samuelnocita@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 11:35:13 by snocita           #+#    #+#             */
/*   Updated: 2023/06/30 19:11:45 by snocita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
// #include "stdio.h"

/*

	takes two strings and returns
	the a string containing both
	of them.

*/

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	char	s1len;
	int		s2len;

	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	str = malloc(sizeof(char) * (s1len + s2len + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (*s1 != '\0')
	{
		str[i] = *s1;
		i++;
		s1++;
	}
	while (*s2 != '\0')
	{
		str[i] = *s2;
		i++;
		s2++;
	}
	str[i] = '\0';
	return (str);
}

// int	main(void)
// {
// 	printf("%s\n", ft_strjoin("", ""));
// }
