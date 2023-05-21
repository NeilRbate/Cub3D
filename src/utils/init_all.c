/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efirmino <efirmino@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 06:34:23 by efirmino          #+#    #+#             */
/*   Updated: 2023/05/20 08:02:12 by jbarbate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

static void	ft_init_all_player(t_all **all)
{
	int	real_x;
	int	real_y;

	real_x = ((*all)->map->start_x + (*all)->map->delta_x / 2) \
	+ ((*all)->player->pos_x * (*all)->map->delta_x);
	real_y = ((*all)->map->start_y + (*all)->map->delta_y / 2) \
	+ ((*all)->player->pos_y * (*all)->map->delta_y);
	(*all)->player->pos_x = real_x;
	(*all)->player->pos_y = real_y;
	(*all)->player->dor_x = cos((*all)->player->angle) * SPEED;
	(*all)->player->dor_y = sin((*all)->player->angle) * SPEED;
}

static void	ft_init_all_map(t_map **map)
{
	t_map	*current;
	size_t	height;
	size_t	width;

	current = *map;
	height = current->height;
	width = current->width;
	(*map)->height = height;
	(*map)->width = width;
	(*map)->delta_x = (WIDTH / MINIMAP_RATE) / width;
	(*map)->delta_y = (HEIGHT / MINIMAP_RATE) / height;
	(*map)->start_x = WIDTH - (current->delta_x * current->width);
	(*map)->start_y = HEIGHT - (current->delta_y * current->height);
	(*map)->end_x = current->start_x + (current->delta_x * current->width);
	(*map)->end_y = current->start_y + (current->delta_y * current->height);
}

static void	ft_init_all_minimap_img(t_all **all)
{
	t_mlx_img	*img;

	img = malloc(sizeof(t_mlx_img));
	img->img_width = (*all)->map->delta_x * (*all)->map->width;
	img->img_height = (*all)->map->delta_y * (*all)->map->height;
	img->img = mlx_new_image((*all)->id, img->img_width, img->img_height);
	img->addr = mlx_get_data_addr(img->img, &(img->b_pp), &(img->len), \
	&(img->endian));
	(*all)->map->minimap = img;
	ft_draw_minimap_wall((*all));
}

int	ft_init_texture_img(t_all *all)
{
	t_img	*img;

	img = all->imgs;
	img->img_no = malloc(sizeof(t_mlx_img));
	img->img_so = malloc(sizeof(t_mlx_img));
	img->img_we = malloc(sizeof(t_mlx_img));
	img->img_ea = malloc(sizeof(t_mlx_img));
	img->img_no->img = all->imgs->no;
	img->img_no->addr = mlx_get_data_addr(img->no, &img->img_no->b_pp, \
						&img->img_no->len, &img->img_no->endian);
	img->img_so->img = all->imgs->so;
	img->img_so->addr = mlx_get_data_addr(img->so, &img->img_so->b_pp, \
						&img->img_so->len, &img->img_so->endian);
	img->img_we->img = all->imgs->we;
	img->img_we->addr = mlx_get_data_addr(img->we, &img->img_we->b_pp, \
						&img->img_we->len, &img->img_we->endian);
	img->img_ea->img = all->imgs->ea;
	img->img_ea->addr = mlx_get_data_addr(img->ea, &img->img_ea->b_pp, \
						&img->img_ea->len, &img->img_ea->endian);
	return (0);
}

void	ft_init_all(t_all **all)
{
	ft_init_all_map(&((*all)->map));
	ft_init_all_player(all);
	ft_init_all_render_img(all);
	ft_init_all_minimap_img(all);
	(*all)->rays = NULL;
}
