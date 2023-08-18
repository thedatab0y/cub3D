/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busmanov <busmanov@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 13:23:53 by busmanov          #+#    #+#             */
/*   Updated: 2021/11/19 14:19:59 by busmanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char string [])
{
	int		count;
	int		i;

	count = 0;
	i = 0;
	while (string [i])
	{
		count++;
		i++;
	}
	return (count);
}
