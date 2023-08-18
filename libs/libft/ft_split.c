/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busmanov <busmanov@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 13:27:08 by busmanov          #+#    #+#             */
/*   Updated: 2022/01/04 21:05:55 by busmanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(const char *str, char c)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (str[x])
	{
		if (str[x] == c)
			x++;
		else
		{
			y++;
			while (str[x] != '\0' && str[x] != c)
				x++;
		}
	}
	return (y);
}

static char	*ft_write_words(const char *str, char c)
{
	int		counterr;
	char	*ptr;

	counterr = 0;
	while (*str && *str == c)
		str++;
	while (str[counterr] && str[counterr] != c)
		counterr++;
	ptr = (char *)malloc(sizeof(char) * (counterr + 1));
	if (ptr == NULL)
		return (NULL);
	counterr = 0;
	while (str[counterr] && str[counterr] != c)
	{
		ptr[counterr] = str[counterr];
		counterr++;
	}
	ptr[counterr] = '\0';
	return (ptr);
}

static void	ft_free_words(int i, char **pptr)
{
	while (i > 0)
	{
		free(pptr[i - 1]);
		i--;
	}
	free(pptr);
}

static int	ft_free(int counter, char **pptr)
{
	if (pptr[counter] == NULL)
	{
		ft_free_words(counter, pptr);
		return (0);
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**pptr;
	int		counter;
	int		num_word;

	if (!s)
		return (NULL);
	num_word = ft_count_words(s, c);
	pptr = (char **)malloc(sizeof(char *) * (num_word + 1));
	if (pptr == NULL)
		return (NULL);
	counter = 0;
	while (counter < num_word)
	{
		while (*s && *s == c)
			s++;
		pptr[counter] = ft_write_words(s, c);
		if (!(ft_free(counter, pptr)))
			return (NULL);
		while (*s && *s != c)
			s++;
		counter++;
	}
	pptr[counter] = NULL;
	return (pptr);
}
