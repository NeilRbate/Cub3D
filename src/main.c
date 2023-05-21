/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efirmino <efirmino@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 09:20:45 by efirmino          #+#    #+#             */
/*   Updated: 2023/05/19 18:21:08 by efirmino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

double	ft_repair_angle(double angle)
{
	double	tmp;

	tmp = angle;
	if (tmp < 0)
	{
		tmp += (double)2 * PI;
	}
	if (tmp > (double)2 * PI)
	{
		tmp -= (double)2 * PI;
	}
	return (tmp);
}

void	boucle(t_all *all, int *value, int *errs, int *data)
{
	while (1)
	{
		mlx_pixel_put(all->id, all->window, value[0], value[1], \
						rgb_to_int(1, 0, 0));
		if (value[0] == value[2] && value[1] == value[3])
			return ;
		errs[1] = 2 * errs[0];
		if (errs[1] >= data[0])
		{
			errs[0] += data[0];
			value[0] += data[3];
		}
		if (errs[1] <= data[2])
		{
			errs[0] += data[2];
			value[1] += data[1];
		}
	}
}

void	plot_line(t_all *all, int *x, int x1, int y1)
{
	int	data[4];
	int	errs[2];
	int	value[4];

	data[2] = abs (x1 - x[0]);
	if (x[0] < x1)
		data[3] = 1;
	else
		data[3] = -1;
	data[0] = -abs (y1 - x[1]);
	if (x[1] < y1)
		data[1] = 1;
	else
		data[1] = -1;
	errs[0] = data[2] + data[0];
	value[0] = x[0];
	value[1] = x[1];
	value[2] = x1;
	value[3] = y1;
	boucle(all, value, errs, data);
}

static void	ft_mlx_init(t_all **all)
{
	*all = malloc(sizeof(t_all));
	(*all)->id = mlx_init();
	(*all)->window = NULL;
	(*all)->imgs = NULL;
	(*all)->map = NULL;
	(*all)->render = NULL;
}

int	main(int argc, char **argv)
{
	t_all	*all;

	if (argc != 2)
	{
		ft_putendl_fd("cub3D: wrong number of arguments", 2);
		exit(1);
	}
	ft_mlx_init(&all);
	if (ft_parsing(argv[1], all) == 1)
		return (0);
	ft_init_all(&all);
	ft_launch(all);
	return (0);
}
