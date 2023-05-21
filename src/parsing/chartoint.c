/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chartoint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbate <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 12:38:04 by jbarbate          #+#    #+#             */
/*   Updated: 2023/04/20 14:29:28 by jbarbate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

int	ft_put_mapinmap(char **cmap, int **imap, int i, int j)
{
	while (cmap[i])
	{
		while (cmap[i][j])
		{
			if (cmap[i][j] == '0')
				imap[i][j] = 0;
			if (cmap[i][j] == '1')
				imap[i][j] = 1;
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

int	ft_init_intmap(int **map, t_all *all)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < all->map->height)
	{
		map[i] = malloc(sizeof(int) * all->map->width);
		if (!map[i])
			return (ft_putendl_fd("Error\nMalloc fail", 2), 1);
		while (j < all->map->width)
		{
			map[i][j] = 2;
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

void	ft_map_size(char **map, int *x, int *y)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			j++;
			if (*x < j)
				*x = j;
		}
		j = 0;
		i++;
	}
	if (*y < i)
		*y = i;
}

int	ft_convert_tab(t_all *all)
{
	ft_map_size(all->map->mapy, &all->map->width, &all->map->height);
	all->map->map = malloc(sizeof(*all->map->map) * all->map->height);
	if (!all->map->map)
		return (ft_putendl_fd("Error\nMalloc fail", 2), 1);
	if (ft_init_intmap(all->map->map, all) != 0)
		return (1);
	if (ft_put_mapinmap(all->map->mapy, all->map->map, 0, 0) != 0)
		return (1);
	free(all->map->mapy);
	all->map->mapy = NULL;
	return (0);
}
