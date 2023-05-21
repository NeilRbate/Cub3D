/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efirmino <efirmino@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 11:20:28 by efirmino          #+#    #+#             */
/*   Updated: 2022/11/15 19:15:28 by efirmino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	size_dst;
	size_t	size_src;

	i = 0;
	size_src = ft_strlen(src);
	if (dstsize == 0)
		return (size_src);
	size_dst = ft_strlen(dst);
	if (dstsize - 1 < size_dst || dstsize == 0)
		return (dstsize + size_src);
	while (dstsize - 1 > size_dst + i && src[i])
	{
		dst[size_dst + i] = src [i];
		i++;
	}
	dst[size_dst + i] = '\0';
	return (size_dst + size_src);
}
