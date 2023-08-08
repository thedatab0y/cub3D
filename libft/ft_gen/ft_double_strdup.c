/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double_strdup.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snocita <snocita@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 17:08:48 by snocita           #+#    #+#             */
/*   Updated: 2023/07/28 17:35:15 by snocita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	**ft_double_strdup(char **envp)
{
	char	**myenvp;
	int		i;

	i = 0;
	while (envp[i])
		i++;
	i += 1000;
	myenvp = (char **)malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (envp[i])
	{
		if (envp[i] == NULL)
			continue ;
		myenvp[i] = malloc(sizeof(char) * (ft_strlen(envp[i]) + 1000));
		strcpy(myenvp[i], envp[i]);
		i++;
	}
	myenvp[i] = NULL;
	return (myenvp);
}
