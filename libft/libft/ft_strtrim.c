/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efirmino <efirmino@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 00:11:54 by efirmino          #+#    #+#             */
/*   Updated: 2022/11/15 19:06:08 by efirmino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	my_isset(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	my_trimlen(char const *str, char const *set)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (my_isset(str[i], set))
		i++;
	while (str[j])
		j++;
	j--;
	while (my_isset(str[j], set))
		j--;
	if (j - i < 0)
		return (0);
	return (j - i + 1);
}

static int	my_trimbeg(char const *str, char const *set)
{
	int	i;

	i = 0;
	while (my_isset(str[i], set))
		i++;
	return (i);
}

static int	my_trimend(char const *str, char const *set)
{
	int	j;

	j = 0;
	while (str[j])
		j++;
	j--;
	while (my_isset(str[j], set))
		j--;
	return (j);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		beg;
	int		end;
	int		i;

	if (!(s1))
		return (0);
	if (set[0] == '\0')
		return (ft_strdup(s1));
	str = malloc(sizeof(char) * my_trimlen(s1, set) + 1);
	if (!(str))
		return (0);
	beg = my_trimbeg(s1, set);
	end = my_trimend(s1, set);
	i = 0;
	while (beg <= end)
	{
		str[i] = s1[beg];
		i++;
		beg++;
	}
	str[i] = '\0';
	return (str);
}
