/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbate <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 13:33:21 by jbarbate          #+#    #+#             */
/*   Updated: 2023/04/17 13:54:36 by jbarbate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

int	ft_open(char *filename)
{
	int	fd;

	fd = open(filename, O_DIRECTORY);
	if (fd != -1)
	{
		close(fd);
		ft_putendl_fd("Error", 2);
		ft_putstr_fd(filename, 2);
		return (ft_putendl_fd(": Is a directory", 2), -1);
	}
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		ft_putendl_fd("Error", 2);
		perror(filename);
		return (-1);
	}
	return (fd);
}

t_file	*ft_read(int fd)
{
	t_file	*list;
	char	*stock;

	stock = get_next_line(fd);
	if (stock)
		list = ft_create_file(stock);
	else
	{
		close (fd);
		return (ft_putendl_fd("Error\nGNL Error", 2), NULL);
	}
	while (stock != NULL)
	{
		stock = get_next_line(fd);
		if (stock)
			ft_add_listelem(stock, list);
	}
	close (fd);
	return (list);
}
