/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efirmino <efirmino@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 09:02:11 by efirmino          #+#    #+#             */
/*   Updated: 2023/05/19 18:28:19 by efirmino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	ft_free_rays(t_ray **rays)
{
	t_ray	*current;
	t_ray	*tmp;

	if (*rays == NULL)
		return ;
	current = *rays;
	while (current)
	{
		tmp = current;
		current = current->next;
		free(tmp);
		tmp = NULL;
	}
	*rays = NULL;
}

static void	ft_clear_map(t_all *all)
{
	t_map	*tmp;
	int		i;

	tmp = all->map;
	i = 0;
	while (i < tmp->height)
	{
		free(tmp->map[i++]);
	}
}

void	ft_safe_stop(t_all *all)
{
	mlx_clear_window(all->id, all->window);
	ft_clear_map(all);
	free(all->map);
	free(all->player);
	free(all->imgs);
}
