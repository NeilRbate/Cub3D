/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efirmino <efirmino@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 13:31:21 by efirmino          #+#    #+#             */
/*   Updated: 2023/05/19 18:40:39 by efirmino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

/*	Convert RGB color to hexa readable for mlx, RGB are double between 0 and.
	Return Value: hexINT that correpond to the RGB color */
int	rgb_to_int(double r, double g, double b)
{
	int	color;

	color = 0;
	color |= (int)(b * 255);
	color |= (int)(g * 255) << 8;
	color |= (int)(r * 255) << 16;
	return (color);
}

void	ft_draw_some_lines(t_all *all)
{
	t_ray	*ray;
	int		i;
	int		value[2];

	i = 0;
	ray = all->rays;
	value[0] = all->player->pos_x;
	value[1] = all->player->pos_y;
	while (ray->next)
	{
		if (i % 160 == 0)
			plot_line(all, value, ray->ray_x, ray->ray_y);
		ray = ray->next;
		i++;
	}
}

void	ft_init_all_render_img(t_all **all)
{
	t_mlx_img	*render;

	render = malloc(sizeof(t_mlx_img));
	render->img_height = HEIGHT;
	render->img_width = WIDTH;
	render->img = mlx_new_image((*all)->id, WIDTH, HEIGHT);
	render->addr = mlx_get_data_addr(render->img, &(render->b_pp), \
	&(render->len), &(render->endian));
	(*all)->render = render;
	ft_init_texture_img(*all);
	ft_draw_floor_celling((*all));
}

void	ft_get_f_dist(double *f_dist, t_all *all, t_ray *ray)
{
	int			px;
	int			py;
	int			rx;
	int			ry;
	t_mlx_img	*img;

	img = all->map->minimap;
	rx = all->map->width - (((ray->ray_x - all->map->end_x) \
	/ img->img_width * all->map->width) * -1);
	ry = all->map->height - (((ray->ray_y - all->map->end_y) \
	/ img->img_height * all->map->height) * -1);
	px = all->map->width - (((all->player->pos_x - all->map->end_x) \
	/ img->img_width * all->map->width) * -1);
	py = all->map->height - (((all->player->pos_y - all->map->end_y) \
	/ img->img_height * all->map->height) * -1);
	*f_dist = sqrt((rx - px) * (rx - px) + (ry - py) * (ry - py));
}
