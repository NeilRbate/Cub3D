/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbate <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 12:43:02 by jbarbate          #+#    #+#             */
/*   Updated: 2023/04/18 13:23:18 by jbarbate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

int	ft_check_file_extension(char *filename)
{
	int	i;

	i = ft_strlen(filename);
	if (i <= 4)
		return (1);
	i -= 4;
	if (ft_strncmp(filename + i, ".cub", 5) != 0)
	{
		ft_putendl_fd("Error\nInvalid extension", 2);
		return (1);
	}
	return (0);
}

t_img	*ft_init_img(void)
{
	t_img	*img;

	img = malloc(sizeof(*img));
	if (!img)
		return (ft_putendl_fd("Error\nMalloc fail", 2), NULL);
	img->no = NULL;
	img->so = NULL;
	img->we = NULL;
	img->ea = NULL;
	img->f_color = -1;
	img->c_color = -1;
	return (img);
}

int	ft_parsing(char *filename, t_all *all)
{
	int		fd;
	t_file	*list;

	if (!filename)
		return (ft_putendl_fd("Error\nNULL filename", 2), 1);
	if (ft_strlen(filename) <= 4)
		return (ft_putendl_fd("Error\nExtension without filename", 2), 1);
	if (ft_check_file_extension(filename) != 0)
		return (1);
	fd = ft_open(filename);
	if (fd < 0)
		return (1);
	list = ft_read(fd);
	if (!list)
		return (1);
	all->imgs = ft_init_img();
	if (!all->imgs)
		return (ft_free_file(list), 1);
	if (ft_check_file(list, all) != 0)
		return (ft_free_file(list), 1);
	ft_free_file(list);
	all->map->mapy = NULL;
	return (0);
}
