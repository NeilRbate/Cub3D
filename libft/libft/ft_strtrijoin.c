/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrijoin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efirmino <efirmino@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 11:11:10 by efirmino          #+#    #+#             */
/*   Updated: 2023/03/18 11:11:34 by efirmino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrijoin(char const *s1, char const *s2, char const *s3)
{
	int		i;
	int		j;
	char	*str;
	int		len;

	i = 0;
	j = 0;
	if (!(s1) || !(s2))
		return (0);
	len = ft_strlen(s1) + ft_strlen(s2) + ft_strlen(s3);
	str = malloc(sizeof(char) * len + 1);
	if (!(str))
		return (0);
	while (s1[i])
			str[j++] = s1[i++];
	i = 0;
	while (s2[i])
			str[j++] = s2[i++];
	i = 0;
	while (s3[i])
			str[j++] = s3[i++];
	str[j] = '\0';
	return (str);
}
