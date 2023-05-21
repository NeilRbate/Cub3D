/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efirmino <efirmino@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 03:15:29 by efirmino          #+#    #+#             */
/*   Updated: 2022/11/11 05:34:42 by efirmino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*str;

	if (!(s) || !(f))
		return (0);
	i = 0;
	str = malloc(sizeof(*str) * ft_strlen(s) + 1);
	if (!(str))
		return (0);
	ft_strlcpy(str, s, ft_strlen(s) + 1);
	while (str[i])
	{
		str[i] = (*f)((unsigned int)i, str[i]);
		i++;
	}
	return (str);
}
