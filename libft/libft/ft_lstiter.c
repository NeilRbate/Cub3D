/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efirmino <efirmino@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 14:50:05 by efirmino          #+#    #+#             */
/*   Updated: 2022/11/15 17:57:42 by efirmino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*curent;
	t_list	*next;

	if (!(f) || !(lst))
		return ;
	curent = lst;
	next = 0;
	while (curent)
	{
		next = curent->next;
		(f)(curent->content);
		curent = next;
	}
	return ;
}
