/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkwall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbate <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 10:58:06 by jbarbate          #+#    #+#             */
/*   Updated: 2023/04/22 08:54:14 by jbarbate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

int	ft_check_emptyline(char **map, int i, int j)
{
	int	check;
	int	is_empty;

	check = FALSE;
	is_empty = TRUE;
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] == '\n' && map[i][j + 1] == '\0')
				map[i][j] = '\0';
			if (map[i][j] == '1' || map[i][j] == '0')
			{
				is_empty = FALSE;
				check = TRUE;
			}
			j++;
		}
		if (check == TRUE && is_empty == TRUE)
			return (ft_putendl_fd("Error\nMaps separate with newline", 2), 1);
		is_empty = TRUE;
		j = 0;
		i++;
	}
	return (0);
}

int	ft_left_right(char **map, int i, int j)
{
	int	stock;

	stock = j;
	while (j > 0)
	{
		if (map[i][j] == '0' && j > 0)
			j--;
		if (map[i][j] == '1')
		{
			j++;
			break ;
		}
		if (j == 0 || map[i][j] != '0')
			return (ft_putendl_fd("Error\nMap isn't close", 2), 1);
	}
	j = stock;
	while (map[i][j])
	{
		if (map[i][j] == '1')
			return (0);
		if (map[i][j] != '0')
			return (ft_putendl_fd("Error\nMap isn't close", 2), 1);
		j++;
	}
	return (ft_putendl_fd("Error\nMap isn't close", 2), 1);
}

int	ft_bottom(char **map, int i, int j)
{
	int	stock;

	stock = j;
	i++;
	j = 0;
	while (map[i])
	{
		while (map[i][j] && j < stock)
			j++;
		if (j < stock || (map[i][j] != '0' && map[i][j] != '1'))
			return (ft_putendl_fd("Error\nMap isn't close", 2), 1);
		if (map[i][j] == '1')
			return (0);
		i++;
	}
	return (ft_putendl_fd("Error\nMap isn't close", 2), 1);
}

int	ft_wall(char **map, int i, int j)
{
	int	stock[2];

	if (ft_left_right(map, i, j) != 0)
		return (1);
	stock[0] = i;
	stock[1] = j;
	while (i > 0)
	{
		i--;
		j = 0;
		while (map[i][j] && j < stock[1])
			j++;
		if (j < stock[1] || (map[i][j] != '0' && map[i][j] != '1'))
			return (ft_putendl_fd("Error\nMap isn't close", 2), 1);
		if (map[i][j] == '1')
			break ;
	}
	return (ft_bottom(map, stock[0], stock[1]));
}

int	ft_check_wall(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] == '0')
			{
				if (j == 0 || i == 0)
					return (ft_putendl_fd("Error\nMap isn't close", 2), 1);
				if (ft_wall(map, i, j) != 0 || j == 0)
					return (1);
			}
			j++;
		}
		i++;
		j = 0;
	}
	return (ft_check_emptyline(map, 0, 0));
}
