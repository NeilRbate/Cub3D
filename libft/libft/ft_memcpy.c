/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efirmino <efirmino@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 10:51:45 by efirmino          #+#    #+#             */
/*   Updated: 2022/11/11 06:11:04 by efirmino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*st;

	if (!(src) && !(dst))
		return (0);
	st = (char *)dst;
	while (n)
	{
		*(char *)st = *(char *)src;
		n--;
		st++;
		src++;
	}
	return (dst);
}
