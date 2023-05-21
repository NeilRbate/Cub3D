/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inttofloat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efirmino <efirmino@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 12:57:56 by jbarbate          #+#    #+#             */
/*   Updated: 2023/05/19 16:55:05 by efirmino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

double	ft_div(double a, double b)
{
	return (a / b);
}

double	ft_dist(t_all *all, double rx, double ry)
{
	double	px;
	double	py;
	double	dist;

	px = all->player->pos_x;
	py = all->player->pos_y;
	dist = sqrt((rx - px) * (rx - px) + (ry - py) * (ry - py));
	return (dist);
}

void	ft_check_h_angle(double angle, t_all *all, double *rxy, double *rdxy)
{
	if (angle > PI)
	{
		rxy[1] = ft_get_closest_y(all, 1);
		rxy[0] = ((all->player->pos_y - rxy[1]) * \
		(-1 / tan(angle)) + all->player->pos_x);
		rdxy[1] = - (all->map->delta_y);
		rdxy[0] = -rdxy[1] * (-1 / tan(angle));
	}
	if (angle < PI)
	{
		rxy[1] = ft_get_closest_y(all, 0);
		rxy[0] = ((all->player->pos_y - rxy[1]) * \
		(-1 / tan(angle)) + all->player->pos_x);
		rdxy[1] = all->map->delta_y;
		rdxy[0] = -rdxy[1] * (-1 / tan(angle));
	}
	if (angle != 0 && angle != PI)
	{
		while (!hit_a_wall_h(all, rxy[0], rxy[1], angle))
		{
			rxy[0] += rdxy[0];
			rxy[1] += rdxy[1];
		}
	}
}

void	ft_check_v_an(double angle, t_all *all, double *rxy, double *rdxy)
{
	if (angle > PI2 && angle < PI3)
	{
		rxy[0] = ft_get_closest_x(all, 1);
		rxy[1] = ((all->player->pos_x - rxy[0]) * \
		(-tan(angle)) + all->player->pos_y);
		if (rxy[1] < 0)
			rxy[1] = 0;
		rdxy[0] = - (all->map->delta_x);
		rdxy[1] = -rdxy[0] * (-tan(angle));
	}
	else if (angle < PI2 || angle > PI3)
	{
		rxy[0] = ft_get_closest_x(all, 0);
		rxy[1] = ((all->player->pos_x - rxy[0]) * \
		(-tan(angle)) + all->player->pos_y);
		if (rxy[1] < 0)
			rxy[1] = 0;
		rdxy[0] = (all->map->delta_x);
		rdxy[1] = -rdxy[0] * (-tan(angle));
	}
}

void	ft_check_v(t_all *all, double angle, t_ray **ray)
{
	double	rxy[2];
	double	rdxy[2];

	ft_check_v_an(angle, all, rxy, rdxy);
	if (angle != PI2 && angle != PI3)
	{
		while (!hit_a_wall_v(all, rxy[0], rxy[1], angle))
		{
			rxy[0] += rdxy[0];
			rxy[1] += rdxy[1];
		}
	}
	(*ray)->ray_x = rxy[0];
	(*ray)->ray_y = rxy[1];
	(*ray)->angle = angle;
	(*ray)->dist = ft_dist(all, rxy[0], rxy[1]);
	if (angle > PI2 && angle < PI3)
		(*ray)->or = 'W';
	if (angle < PI2 || angle > PI3)
		(*ray)->or = 'E';
}
