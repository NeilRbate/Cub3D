/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efirmino <efirmino@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 09:39:31 by efirmino          #+#    #+#             */
/*   Updated: 2023/05/19 16:12:24 by jbarbate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

double	ft_get_closest_y(t_all *all, int top)
{
	double	start_y;
	int		i;

	i = 0;
	start_y = all->map->start_y;
	while (all->player->pos_y > start_y && i < all->map->height)
	{
		start_y += all->map->delta_y;
		i++;
	}
	if (top == 1)
		return (start_y - all->map->delta_y);
	return (start_y);
}

double	ft_get_closest_x(t_all *all, int top)
{
	double	start_x;
	int		i;

	i = 0;
	start_x = all->map->start_x;
	while (all->player->pos_x > start_x && i < all->map->width)
	{
		start_x += all->map->delta_x;
		i++;
	}
	if (top == 1)
		return (start_x - all->map->delta_x);
	return (start_x);
}

void	ft_check_h(t_all *all, double angle, t_ray **ray)
{
	double	rxy[2];
	double	rdxy[2];

	ft_check_h_angle(angle, all, rxy, rdxy);
	if (angle != PI)
	{
		while (!hit_a_wall_h(all, rxy[0], rxy[1], angle))
		{
			rxy[0] += rdxy[0];
			rxy[1] += rdxy[1];
		}
	}
	(*ray)->ray_x = rxy[0];
	(*ray)->ray_y = rxy[1];
	(*ray)->angle = angle;
	(*ray)->dist = ft_dist(all, rxy[0], rxy[1]);
	if (angle < PI)
		(*ray)->or = 'S';
	if (angle > PI)
		(*ray)->or = 'N';
}

int	hit_a_wall_v(t_all *all, double x, double y, double angle)
{
	t_mlx_img	*img;
	double		rx;
	double		ry;

	img = all->map->minimap;
	rx = all->map->width - (((x - all->map->end_x) / img->img_width \
	* all->map->width) * -1);
	ry = all->map->height - (((y - all->map->end_y) / img->img_height \
	* all->map->height) * -1);
	if (ry > all->map->height || ry < 0.1)
		return (TRUE);
	if (rx > all->map->width || rx < 0.1)
		return (TRUE);
	if (angle > PI2 && angle < PI3)
	{
		rx -= 0.00000001;
		ry -= 0.00000001;
	}
	if (rx >= all->map->width || ry >= all->map->height)
		return (TRUE);
	if (all->map->map[(int)ry][(int)rx] == 1)
		return (TRUE);
	return (FALSE);
}

int	hit_a_wall_h(t_all *all, double x, double y, double angle)
{
	t_mlx_img	*img;
	double		rx;
	double		ry;

	img = all->map->minimap;
	rx = all->map->width - (((x - all->map->end_x) / img->img_width \
	* all->map->width) * -1.0);
	ry = all->map->height - (((y - all->map->end_y) / img->img_height \
	* all->map->height) * -1.0);
	if (ry > all->map->height || ry < 0.1)
		return (TRUE);
	if (rx > all->map->width || rx < 0.1)
		return (TRUE);
	if (angle > PI && rx > 0 && ry > 0)
	{
		rx -= 0.00000001;
		ry -= 0.00000001;
	}
	else if (rx >= all->map->width || ry >= all->map->height)
		return (TRUE);
	if (all->map->map[(int)ry][(int)rx] && all->map->map[(int)ry][(int)rx] == 1)
		return (TRUE);
	return (FALSE);
}
