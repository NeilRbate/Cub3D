/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efirmino <efirmino@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 13:37:05 by jbarbate          #+#    #+#             */
/*   Updated: 2023/05/19 15:44:51 by efirmino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

static void	ft_draw_minimap_wall_unit(int x, int y, t_all *all, int color)
{
	int	start_x;
	int	start_y;
	int	tmp_x;
	int	tmp_y;

	start_x = x * all->map->delta_x;
	start_y = y * all->map->delta_y;
	tmp_y = start_y;
	while (tmp_y < start_y + all->map->delta_y \
			&& tmp_y < all->map->delta_y * all->map->height)
	{
		tmp_x = start_x;
		while (tmp_x < start_x + all->map->delta_x && tmp_x < \
		all->map->delta_x * all->map->width)
		{
			img_pxl_put(all->map->minimap, tmp_x, tmp_y, color);
			tmp_x++;
		}
		tmp_y++;
	}
}

void	ft_draw_minimap_wall(t_all *all)
{
	int		**map;
	int		y;
	int		x;

	map = all->map->map;
	y = 0;
	while (y < all->map->height)
	{
		x = 0;
		while (x < all->map->width)
		{
			if (map[y][x] == 1)
				ft_draw_minimap_wall_unit(x, y, all, WALL_COLOR);
			else
				ft_draw_minimap_wall_unit(x, y, all, SPACE_COLOR);
			x++;
		}
		y++;
	}
}

void	ft_draw_floor_celling(t_all *all)
{
	int	y;
	int	x;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			if (y < HEIGHT / 2)
				img_pxl_put(all->render, x, y, all->imgs->c_color);
			else
				img_pxl_put(all->render, x, y, all->imgs->f_color);
			x++;
		}
		y++;
	}
}

void	ft_draw_player(t_all *all)
{
	int	y;
	int	x;
	int	color;

	ft_draw_some_lines(all);
	color = rgb_to_int(0, 1, 1);
	y = all->player->pos_y - 2;
	while (y < all->player->pos_y + 2)
	{
		x = all->player->pos_x - 2;
		while (x < all->player->pos_x + 2)
		{
			mlx_pixel_put(all->id, all->window, x, y, color);
			x++;
		}
		y++;
	}
}

void	img_pxl_put(t_mlx_img *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->addr + (y * img->len + x * (img->b_pp / 8));
	*(int *)pixel = color;
}
