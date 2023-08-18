/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busmanov <busmanov@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 15:59:21 by busmanov          #+#    #+#             */
/*   Updated: 2021/12/31 16:51:53 by busmanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*firstl;
	t_list	*new_list;

	firstl = NULL;
	while (lst)
	{
		new_list = ft_lstnew(f(lst -> content));
		if (!new_list)
		{
			ft_lstclear(&firstl, del);
			return (firstl);
		}
		ft_lstadd_back(&firstl, new_list);
		lst = lst -> next;
	}
	return (firstl);
}
