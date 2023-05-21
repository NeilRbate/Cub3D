/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efirmino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 11:23:21 by efirmino          #+#    #+#             */
/*   Updated: 2022/11/15 22:18:19 by efirmino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*curent;
	t_list	*next;
	int		i;

	i = 0;
	curent = lst;
	next = lst;
	while (next)
	{
		curent = next;
		next = curent->next;
		i++;
	}
	return (i);
}
