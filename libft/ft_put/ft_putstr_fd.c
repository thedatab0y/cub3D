/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snocita <samuelnocita@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 15:48:15 by snocita           #+#    #+#             */
/*   Updated: 2023/06/30 19:11:24 by snocita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*

	Loops through the string writing
	every char based on fd.

*/

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	while (*s != '\0')
	{
		ft_putchar_fd(*s, fd);
		s++;
	}
}
