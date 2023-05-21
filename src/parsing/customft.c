/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   customft.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbate <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 15:13:41 by jbarbate          #+#    #+#             */
/*   Updated: 2023/04/22 08:43:07 by jbarbate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

t_file	*ft_del_ws(t_file *list)
{
	int	i;

	i = 0;
	while (list->next)
	{
		while (list->line[i])
		{
			if (list->line[i] != 32 && list->line[i] != 10
				&& list->line[i] != '1')
				return (ft_putendl_fd(
						"Error\nInvalid char between args and map", 2), NULL);
			if (list->line[i] == '1')
				return (list);
			i++;
		}
		i = 0;
		list = list->next;
	}
	return (list);
}

char	*ft_strndup(char *str, int size)
{
	char	*ret;

	if (ft_strlen(str) < (size_t)size)
		return (NULL);
	ret = malloc(sizeof(char) * (size + 1));
	ft_memmove(ret, str, size);
	ret[size] = '\0';
	return (ret);
}

int	ft_init_player(t_all *all)
{
	all->player = malloc(sizeof(*all->player));
	if (!all->player)
		return (ft_putendl_fd("Error\nMalloc fail", 2), 1);
	all->player->pos_x = -1;
	all->player->pos_y = -1;
	all->player->dor_x = -1;
	all->player->dor_y = -1;
	return (0);
}

int	ft_init_map(t_all *all)
{
	all->map = malloc(sizeof(*all->map));
	if (!all->map)
		return (ft_putendl_fd("Error\nMalloc fail", 2), 1);
	all->map->mapy = NULL;
	all->map->map = NULL;
	all->map->width = -1;
	all->map->height = -1;
	all->map->start_x = -1;
	all->map->start_y = -1;
	all->map->delta_x = -1;
	all->map->delta_y = -1;
	return (0);
}

int	ft_init(t_all *all)
{
	if (ft_init_map(all) != 0)
		return (1);
	if (ft_init_player(all) != 0)
	{
		free(all->map);
		return (1);
	}
	return (0);
}
