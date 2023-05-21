/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbate <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 09:15:12 by jbarbate          #+#    #+#             */
/*   Updated: 2023/05/16 09:17:33 by jbarbate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	print_no(t_all *all, double *start, double y, int r)
{
	t_mlx_img	*render;
	char		*pixel;

	render = all->render;
	pixel = all->imgs->img_no->addr + ((int)start[0] * all->imgs->img_no->len \
				+ (r % 256) * (all->imgs->img_we->b_pp / 8));
	img_pxl_put(render, (int)start[1], y, *(unsigned int *)pixel);
}

void	print_so(t_all *all, double *start, double y, int r)
{
	t_mlx_img	*render;
	char		*pixel;

	pixel = all->imgs->img_so->addr + ((int)start[0] * all->imgs->img_so->len \
				+ (r % 256) * (all->imgs->img_we->b_pp / 8));
	render = all->render;
	img_pxl_put(render, (int)start[1], y, *(unsigned int *)pixel);
}

void	print_ea(t_all *all, double *start, double y, int r)
{
	t_mlx_img	*render;
	char		*pixel;

	pixel = all->imgs->img_ea->addr + ((int)start[0] * all->imgs->img_ea->len \
				+ (r % 256) * (all->imgs->img_we->b_pp / 8));
	render = all->render;
	img_pxl_put(render, (int)start[1], y, *(unsigned int *)pixel);
}

void	print_we(t_all *all, double *start, double y, int r)
{
	t_mlx_img	*render;
	char		*pixel;

	pixel = all->imgs->img_we->addr + ((int)start[0] * all->imgs->img_we->len \
			+ (r % 256) * (all->imgs->img_we->b_pp / 8));
	render = all->render;
	img_pxl_put(render, (int)start[1], y, *(unsigned int *)pixel);
}
