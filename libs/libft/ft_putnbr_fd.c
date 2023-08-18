/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busmanov <busmanov@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 14:06:43 by busmanov          #+#    #+#             */
/*   Updated: 2021/12/15 14:33:11 by busmanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int nb, int fd)
{	
	unsigned int	x;

	if (fd < 0)
		return ;
	if (nb < 0)
	{
		x = nb * -1;
		ft_putchar_fd('-', fd);
	}
	else
		x = nb;
	if (x >= 10)
	{
		ft_putnbr_fd(x / 10, fd);
	}
	ft_putchar_fd(x % 10 + 48, fd);
}
