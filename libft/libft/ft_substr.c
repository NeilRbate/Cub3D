/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efirmino <efirmino@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 13:53:39 by efirmino          #+#    #+#             */
/*   Updated: 2022/11/15 18:00:05 by efirmino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	j;
	size_t	s_len;

	if (!(s))
		return (0);
	s_len = ft_strlen(s);
	if (start > s_len)
		len = 0;
	if (len > s_len)
		len = s_len - start;
	str = malloc(sizeof(char) * (len + 1));
	if (!(str))
		return (0);
		i = 0;
		j = start;
	if (start < s_len)
	{	
		while (s[j] && (j < len + start))
			str[i++] = s[j++];
	}
	str[i] = '\0';
	return (str);
}
