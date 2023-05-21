/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbate <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 09:13:20 by jbarbate          #+#    #+#             */
/*   Updated: 2023/05/11 13:39:16 by jbarbate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	ft_set_pos(int x, int y, t_all *all, char **map)
{
	all->player->pos_x = x;
	all->player->pos_y = y;
	map[y][x] = '0';
}

int	ft_player_orientation(int *spawn, t_all *all, char c)
{
	*spawn += 1;
	if (c == 'N')
	{
		all->player->angle = PI + (90 * DEG);
	}
	else if (c == 'E')
	{
		all->player->angle = 0;
	}
	else if (c == 'S')
	{
		all->player->angle = PI - (90 * DEG);
	}
	else if (c == 'W')
	{
		all->player->angle = PI;
	}
	return (0);
}

int	ft_check_spawn(char **map, t_all *all, int i, int j)
{
	int	spawn;

	spawn = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] != '1' && map[i][j] != '0'
					&& map[i][j] != 32 && map[i][j] != 10)
			{
				if ((map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'E'
							|| map[i][j] == 'W') && spawn == 0)
					ft_player_orientation(&spawn, all, map[i][j]);
				else
					return (ft_putendl_fd("Error\nInvalid map char", 2), 1);
				ft_set_pos(j, i, all, map);
			}
			j++;
		}
		j = 0;
		i++;
	}
	if (spawn == 0)
		return (ft_putendl_fd("Error\nNo spawn in map", 2), 1);
	return (0);
}

char	**ft_char_map(t_file *list)
{
	char	**map;
	int		i;
	int		size;

	i = 0;
	size = ft_file_size(list);
	map = malloc(sizeof(char **) * size + 1);
	if (!map)
		return (ft_putendl_fd("Error\nMalloc fail", 2), NULL);
	map[size] = NULL;
	while (list)
	{
		map[i] = list->line;
		i++;
		list = list->next;
	}
	return (map);
}

int	ft_check_map(t_all *all)
{
	if (ft_check_spawn(all->map->mapy, all, 0, 0) != 0)
		return (free(all->map->mapy), 1);
	if (ft_check_wall(all->map->mapy) != 0)
		return (free(all->map->mapy), 1);
	if (all->player->pos_x == 0 || all->player->pos_y == 0)
	{
		ft_putendl_fd("Error\nPlayer in the border of map", 2);
		return (free(all->map->mapy), 1);
	}
	if (ft_convert_tab(all) != 0)
		return (free(all->map->mapy), 1);
	return (0);
}
