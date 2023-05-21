/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efirmino <efirmino@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 14:28:59 by efirmino          #+#    #+#             */
/*   Updated: 2023/05/19 18:42:26 by efirmino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	ft_add_ray(t_all **all, t_ray *good, int type)
{
	t_ray	*current;

	good->type = type;
	if ((*all)->rays == NULL)
		(*all)->rays = good;
	else
	{
		current = (*all)->rays;
		while (current && current->next)
			current = current->next;
		current->next = good;
	}
}

static void	ft_draw_minimap_line(t_all *all, double angle)
{	
	t_ray	*rx;
	t_ray	*ry;

	rx = malloc(sizeof(t_ray));
	ry = malloc(sizeof(t_ray));
	if (!rx || !ry)
		exit(1);
	rx->dist = DEFDIST;
	ry->dist = DEFDIST;
	rx->next = NULL;
	ry->next = NULL;
	angle = ft_repair_angle(angle);
	ft_check_h(all, angle, &ry);
	ft_check_v(all, angle, &rx);
	if (rx->dist < ry->dist)
	{
		ft_add_ray(&all, rx, 0);
		free(ry);
	}
	else
	{
		ft_add_ray(&all, ry, 1);
		free(rx);
	}
}

void	ft_raycaster(t_all *all)
{
	double	min_ray_angle;
	int		i;

	i = 0;
	min_ray_angle = all->player->angle - ((double)(FOV / 2)*DEG);
	while (i < WIDTH)
	{
		min_ray_angle = ft_repair_angle(min_ray_angle);
		ft_draw_minimap_line(all, min_ray_angle + (i * DEG / \
		(double)(WIDTH / FOV)));
		i++;
	}
}

void	ft_interpret(t_all *all, t_ray *rays)
{
	int		start;
	int		f_dist;
	double	tmp;
	double	stock;

	start = 0;
	stock = ratio(all);
	while (rays && start < WIDTH)
	{
		tmp = all->player->angle - rays->angle;
		tmp = ft_repair_angle(tmp);
		f_dist = all->map->height / rays->dist * HEIGHT;
		f_dist *= stock;
		f_dist = f_dist / cos(tmp);
		if (f_dist >= HEIGHT)
			f_dist = HEIGHT - 2;
		ft_print_texture(f_dist, start, rays, all);
		rays = rays->next;
		start++;
	}
}

void	ft_draw_minimap(t_all *all)
{
	ft_raycaster(all);
	ft_interpret(all, all->rays);
	mlx_put_image_to_window(all->id, all->window, all->render->img, 0, 0);
	mlx_put_image_to_window(all->id, all->window, all->map->minimap->img, \
	all->map->start_x, all->map->start_y);
	ft_draw_player(all);
	mlx_destroy_image(all->id, all->render);
	free(all->imgs->img_ea);
	free(all->imgs->img_so);
	free(all->imgs->img_we);
	free(all->imgs->img_no);
	ft_init_all_render_img(&all);
	ft_free_rays(&all->rays);
}
