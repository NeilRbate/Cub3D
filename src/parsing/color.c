/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efirmino <efirmino@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 15:42:59 by jbarbate          #+#    #+#             */
/*   Updated: 2023/05/20 09:23:03 by jbarbate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

int	ft_check_elem(t_img *img)
{
	if (img->no != NULL && img->so != NULL && img->we != NULL
		&& img->ea != NULL && img->f_color != -1 && img->c_color != -1)
		return (1);
	return (0);
}

int	ft_split_color(int *color, char *line, int j)
{
	double	c[3];

	c[0] = (double)ft_atoi(line + j);
	while (line[j] != ',')
		j++;
	j++;
	c[1] = (double)ft_atoi(line + j);
	while (line[j] != ',')
		j++;
	j++;
	c[2] = (double)ft_atoi(line + j);
	if (c[0] > 255 || c[1] > 255 || c[2] > 255
		|| c[0] < 0 || c[1] < 0 || c[2] < 0)
		return (ft_putendl_fd("Error\nInvalid color value", 2), 1);
	c[0] = c[0] / 255;
	c[1] = c[1] / 255;
	c[2] = c[2] / 255;
	*color = rgb_to_int(c[0], c[1], c[2]);
	return (0);
}

int	ft_open_color(int *color, char *line, int *i, int count)
{
	int	j;

	*i += 1;
	while (line[*i] && line[*i] == 32)
		*i += 1;
	j = *i;
	if (line[*i] && (ft_isdigit(line[*i]) == 1))
	{
		while (line[*i] && (ft_isdigit(line[*i]) == 1
				|| line[*i] == ','))
		{
			if (line[*i] == ',')
				count++;
			*i += 1;
		}
		if (*i - j < 5 || count != 2)
			return (ft_putendl_fd("Error\nInvalid color value", 2), 1);
		if (ft_split_color(color, line, j) != 0)
			return (1);
		return (0);
	}
	else
		return (ft_putendl_fd("Error\nInvalid color value", 2), 1);
}
