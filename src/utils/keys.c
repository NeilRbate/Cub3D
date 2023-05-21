/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efirmino <efirmino@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 13:19:48 by efirmino          #+#    #+#             */
/*   Updated: 2023/05/20 08:02:34 by jbarbate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

static int	ft_is_move_key(int keycode)
{
	if (keycode == W_KEY)
		return (TRUE);
	else if (keycode == A_KEY)
		return (TRUE);
	else if (keycode == S_KEY)
		return (TRUE);
	else if (keycode == D_KEY)
		return (TRUE);
	else
		return (FALSE);
}

int	ft_exit_button(t_all **all)
{
	mlx_destroy_window((*all)->id, (*all)->window);
	exit(0);
}

int	ft_key_handler(int keycode, t_all **all)
{
	if (keycode == ESC_KEY)
	{
		ft_exit_button(all);
	}
	else if (ft_is_move_key(keycode))
		ft_move_player(keycode, all);
	else if (keycode == CAM_L_KEY || keycode == CAM_R_KEY)
		ft_move_cam(keycode, all);
	return (0);
}

static void	ft_is_free_space_util(double *rx, double *ry, t_all *all, int pos)
{
	t_mlx_img	*img;

	img = all->map->minimap;
	if (pos)
	{
		*rx = all->map->width - ((((all->player->pos_x + all->player->dor_x) \
		- all->map->end_x) / img->img_width * all->map->width) * -1);
		*ry = all->map->height - ((((all->player->pos_y + all->player->dor_y) \
		- all->map->end_y) / img->img_height * all->map->height) * -1);
	}
	else
	{
		*rx = all->map->width - ((((all->player->pos_x - all->player->dor_x) \
		- all->map->end_x) / img->img_width * all->map->width) * -1);
		*ry = all->map->height - ((((all->player->pos_y - all->player->dor_y) \
		- all->map->end_y) / img->img_height * all->map->height) * -1);
	}
}

int	ft_is_free_space(t_all *all, char dir)
{
	double		rx;
	double		ry;

	if (dir == 'w')
	{
		ft_is_free_space_util(&rx, &ry, all, 1);
		if (rx < all->map->width && ry < all->map->height \
		&& all->map->map[(int)ry][(int)rx] == 0)
			return (TRUE);
		return (FALSE);
	}
	else if (dir == 's')
	{
		ft_is_free_space_util(&rx, &ry, all, 0);
		if (rx < all->map->width && ry < all->map->height \
		&& all->map->map[(int)ry][(int)rx] == 0)
			return (TRUE);
		return (FALSE);
	}
	return (FALSE);
}
