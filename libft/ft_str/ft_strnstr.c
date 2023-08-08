/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snocita <samuelnocita@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 16:50:04 by snocita           #+#    #+#             */
/*   Updated: 2023/06/30 19:12:02 by snocita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*

	returns a pointer to the beginning of the 
	first occurrence of string2 in string1. 
	If string2 does not appear in string1, 
	the strstr() function returns NULL. 
	If string2 points to a string with zero length, 
	the strstr() function returns string1.

*/

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		i;
	size_t		j;

	i = 0;
	if (*needle == '\0' || needle == NULL)
		return ((char *)haystack);
	while (haystack[i] != '\0' && i < len)
	{
		j = 0;
		while (needle[j] == haystack[i + j] && i + j < len)
		{
			if (needle[j + 1] == '\0')
			{
				return ((char *)haystack + i);
			}
			j++;
		}
		i++;
	}
	return (NULL);
}
