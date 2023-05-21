/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efirmino <efirmino@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 12:14:08 by efirmino          #+#    #+#             */
/*   Updated: 2022/11/15 17:54:58 by efirmino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*curent;
	t_list	*next;

	if (*lst == 0)
	{
		*lst = new;
		return ;
	}
	curent = *lst;
	next = *lst;
	while (next)
	{
		curent = next;
		next = next->next;
	}
	curent->next = new;
	return ;
}
