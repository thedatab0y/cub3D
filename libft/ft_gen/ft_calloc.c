/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snocita <samuelnocita@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 16:58:52 by snocita           #+#    #+#             */
/*   Updated: 2023/06/30 19:09:41 by snocita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
	Uses malloc to automatically create a pointer of a certain size and count.
	(bzero)-> fills the memory spaces with '0's as per manual
	void	*ptr;

	if (size == 0 || count == 0)
		return (0);
	if (size * count == 0)
		return (NULL);
	ptr = malloc(size * count);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, size * count);
	return (ptr);
*/

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;
	size_t	total;

	total = count * size;
	p = malloc (total);
	if (!p)
		return (NULL);
	ft_bzero(p, total);
	return (p);
}

// int	main(void)
// {
// 	ft_calloc(3, 4);
// }
