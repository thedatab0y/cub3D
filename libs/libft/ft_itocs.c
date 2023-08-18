/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itocs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busmanov <busmanov@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 06:56:04 by busmanov          #+#    #+#             */
/*   Updated: 2023/08/16 06:56:46 by busmanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_itocs(unsigned char *s, int i)
{
	s[0] = (unsigned char)i;
	s[1] = (unsigned char)(i >> 8);
	s[2] = (unsigned char)(i >> 16);
	s[3] = (unsigned char)(i >> 24);
}