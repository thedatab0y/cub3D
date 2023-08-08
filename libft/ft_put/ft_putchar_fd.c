/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snocita <samuelnocita@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 20:32:36 by snocita           #+#    #+#             */
/*   Updated: 2023/06/30 19:11:12 by snocita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <unistd.h>
#include "../libft.h"
/*

	fd = file descriptor (int)
	putchar_fd writes 1 byte with value c
	depending on the fd.
	1 = standard input, 
	2 = standard output, 
	3 = standard error,

*/

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
