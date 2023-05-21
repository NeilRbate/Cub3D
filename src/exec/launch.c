/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efirmino <efirmino@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 12:41:14 by efirmino          #+#    #+#             */
/*   Updated: 2023/05/12 07:05:43 by jbarbate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

static void	ft_update(t_all **all)
{
	mlx_clear_window((*all)->id, (*all)->window);
	ft_draw_minimap(*all);
}

static void	ft_move_side(t_all **all, float angle, t_mlx_img *img)
{
	double		new_x;
	double		new_y;
	char		*pixel;
	int			rx;
	int			ry;

	new_x = cos((*all)->player->angle + (angle)) * SPEED;
	new_y = sin((*all)->player->angle + (angle)) * SPEED;
	rx = (*all)->player->pos_x + new_x - (*all)->map->start_x;
	ry = (*all)->player->pos_y + new_y - (*all)->map->start_y;
	pixel = img->addr + (ry * img->len + rx * (img->b_pp / 8));
	if (*(unsigned int *)pixel == SPACE_COLOR)
	{
		(*all)->player->pos_x += new_x;
		(*all)->player->pos_y += new_y;
	}
}

void	ft_launch(t_all *all)
{
	all->window = mlx_new_window(all->id, WIDTH, HEIGHT, "cub3D");
	mlx_hook(all->window, 17, 0, ft_exit_button, &all);
	mlx_hook(all->window, 2, (1L << 0), ft_key_handler, &all);
	ft_draw_minimap(all);
	mlx_loop(all->id);
}

void	ft_move_player(int keycode, t_all **all)
{
	(void)all;
	if (keycode == W_KEY && ft_is_free_space(*all, 'w'))
	{
		(*all)->player->pos_x += (*all)->player->dor_x;
		(*all)->player->pos_y += (*all)->player->dor_y;
		ft_update(all);
	}
	else if (keycode == A_KEY)
	{
		ft_move_side(all, (DEG * -90), (*all)->map->minimap);
		ft_update(all);
	}
	else if (keycode == S_KEY && ft_is_free_space(*all, 's'))
	{
		(*all)->player->pos_x -= (*all)->player->dor_x;
		(*all)->player->pos_y -= (*all)->player->dor_y;
		ft_update(all);
	}
	else if (keycode == D_KEY)
	{
		ft_move_side(all, (DEG * 90), (*all)->map->minimap);
		ft_update(all);
	}
}

void	ft_move_cam(int keycode, t_all **all)
{
	(void)all;
	if (keycode == CAM_L_KEY)
	{
		(*all)->player->angle -= 0.1;
		if ((*all)->player->angle < 0)
		{
			(*all)->player->angle += 2 * PI;
		}
		(*all)->player->dor_x = cos((*all)->player->angle) * SPEED;
		(*all)->player->dor_y = sin((*all)->player->angle) * SPEED;
		ft_update(all);
	}
	else if (keycode == CAM_R_KEY)
	{
		(*all)->player->angle += 0.1;
		if ((*all)->player->angle > 2 * PI)
		{
			(*all)->player->angle -= 2 * PI;
		}
		(*all)->player->dor_x = cos((*all)->player->angle) * SPEED;
		(*all)->player->dor_y = sin((*all)->player->angle) * SPEED;
		ft_update(all);
	}
}
