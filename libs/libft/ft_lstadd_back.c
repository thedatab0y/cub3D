/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busmanov <busmanov@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 15:08:03 by busmanov          #+#    #+#             */
/*   Updated: 2021/12/31 15:24:18 by busmanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last_elm;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last_elm = *lst;
	last_elm = ft_lstlast(last_elm);
	last_elm -> next = new;
}
