/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efirmino <efirmino@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 12:33:33 by jbarbate          #+#    #+#             */
/*   Updated: 2023/05/19 18:19:16 by efirmino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

double	ratio(t_all *all)
{
	double	stock;

	stock = 1;
	if ((double)all->map->width * (double)all->map->height > 600)
		stock = 0.3;
	else if ((double)all->map->width * (double)all->map->height > 500)
		stock = 0.4;
	else if ((double)all->map->width * (double)all->map->height > 350)
		stock = 0.5;
	else if ((double)all->map->width * (double)all->map->height > 200)
		stock = 0.6;
	else if ((double)all->map->width * (double)all->map->height > 100)
		stock = 0.8;
	else if ((double)all->map->width * (double)all->map->height > 50)
		stock = 1;
	else
		stock = 1.5;
	return (stock);
}

double	raydist(t_mlx_img *img, t_ray *rays, t_all *all)
{
	double	r;

	if (rays->type == 1)
	{
		r = all->map->width - (((rays->ray_x - all->map->end_x) \
			/ img->img_width * all->map->width) * -1);
		return (r);
	}
		r = all->map->height - (((rays->ray_y - all->map->end_y) \
			/ img->img_height * all->map->height) * -1);
	return (r);
}

void	ft_print_texture(double f_dist, int start, t_ray *rays, t_all *all)
{
	double	value[3];
	double	j[2];

	value[2] = raydist(all->render, rays, all);
	j[0] = 0;
	value[1] = (HEIGHT / 2) - (f_dist / 2);
	if (f_dist >= 256)
		value[0] = (double)256 / (double)f_dist;
	else
		value[0] = (double)256 / (double)f_dist;
	value[2] = ((double)1024 * (value[2] - (int)value[2]));
	j[1] = start;
	while (value[1] > 0 && value[1] < (HEIGHT / 2) + (f_dist / 2))
	{
		if (rays->or == 'N')
			print_no(all, j, value[1], value[2]);
		else if (rays->or == 'S')
			print_so(all, j, value[1], value[2]);
		else if (rays->or == 'E')
			print_ea(all, j, value[1], value[2]);
		else if (rays->or == 'W')
			print_we(all, j, value[1], value[2]);
		j[0] += value[0];
		value[1]++;
	}
}
