/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efirmino <efirmino@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 11:39:27 by efirmino          #+#    #+#             */
/*   Updated: 2022/11/14 17:53:38 by efirmino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*st;
	const char	*rc;
	size_t		i;

	if (len == 0)
		return (dst);
	if (!(src) && !(dst))
		return (0);
	i = 0;
	st = (char *)dst;
	rc = (char *)src;
	if (dst < src)
	{
		while (len > i)
		{
			st[i] = rc[i];
			i++;
		}
	}
	else
	{
		while (len--)
			st[len] = rc[len];
	}
	return (dst);
}
