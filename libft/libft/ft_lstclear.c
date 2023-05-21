/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efirmino <efirmino@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 12:58:45 by efirmino          #+#    #+#             */
/*   Updated: 2022/11/15 17:55:56 by efirmino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*curent;
	t_list	*next;

	if (!(del) || !(lst))
		return ;
	next = *lst;
	while (next)
	{
		curent = next;
		next = curent->next;
		(del)(curent->content);
		free(curent);
	}
	*lst = 0;
	return ;
}
