/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapelem.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbate <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 12:45:01 by jbarbate          #+#    #+#             */
/*   Updated: 2023/05/16 09:30:46 by jbarbate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	*ft_openxlm(t_all *all, char *filename)
{
	void	*stock;
	int		*size;
	int		s;

	s = SIZE;
	size = &s;
	stock = mlx_xpm_file_to_image(all->id, filename, size, size);
	free(filename);
	if (!stock)
	{
		ft_putendl_fd("Error\nInvalid texture", 2);
		return (NULL);
	}
	return (stock);
}

void	*ft_open_img(char *line, int *i, t_all *all)
{
	int		j;
	char	*filename;

	*i += 2;
	while (line[*i] && line[*i] == 32)
		*i += 1;
	j = *i;
	if (line[*i])
	{
		while (line[*i] && line[*i] != 32 && line[*i] != 10)
			*i += 1;
		if (*i == j)
			return (ft_putendl_fd("Error\nInvalid texture", 2), NULL);
		filename = ft_strndup(line + j, (*i - j));
		if (!filename)
			return (NULL);
		*i += 1;
		return (ft_openxlm(all, filename));
	}
	else
		return (ft_putendl_fd("Error\nInvalid texture", 2), NULL);
}

int	ft_find(t_all *all, char *line, int *i)
{
	if (line[*i] == 'W' && line[*i + 1] == 'E' && all->imgs->we == NULL)
	{
		all->imgs->we = ft_open_img(line, i, all);
		if (all->imgs->we == NULL)
			return (1);
	}
	else if (line[*i] == 'E' && line[*i + 1] == 'A' && all->imgs->ea == NULL)
	{
		all->imgs->ea = ft_open_img(line, i, all);
		if (all->imgs->ea == NULL)
			return (1);
	}
	else if (line[*i] == 'F' && all->imgs->f_color == -1)
	{
		if (ft_open_color(&all->imgs->f_color, line, i, 0) != 0)
			return (1);
	}
	else if (line[*i] == 'C' && all->imgs->c_color == -1)
	{
		if (ft_open_color(&all->imgs->c_color, line, i, 0) != 0)
			return (1);
	}
	else
		return (ft_putendl_fd("Error\nInvalid texture arg", 2), 1);
	return (0);
}

int	ft_search_data(char *line, t_all *all, int *i)
{
	while (line[*i])
	{
		if (line[*i] && line[*i] != 32 && line[*i] != '\n')
		{
			if (line[*i] == 'N' && line[*i + 1] == 'O' && all->imgs->no == NULL)
			{
				all->imgs->no = ft_open_img(line, i, all);
				if (all->imgs->no == NULL)
					return (1);
			}
			else if (line[*i] == 'S' && line[*i + 1] == 'O'
				&& all->imgs->so == NULL)
			{
				all->imgs->so = ft_open_img(line, i, all);
				if (all->imgs->so == NULL)
					return (1);
			}
			else if (ft_find(all, line, i) != 0)
				return (1);
		}
		else
			*i += 1;
	}
	return (0);
}

int	ft_check_file(t_file *list, t_all *all)
{
	int		i;

	i = 0;
	while (list->next != NULL && ft_check_elem(all->imgs) == 0)
	{
		if (ft_search_data(list->line, all, &i) != 0)
			return (1);
		i = 0;
		list = list->next;
	}
	if (ft_file_size(list) < 2)
		return (ft_putendl_fd("Error\nMap too short", 2), 1);
	if (ft_init(all) != 0)
		return (1);
	list = ft_del_ws(list);
	if (!list)
		return (1);
	all->map->mapy = ft_char_map(list);
	if (!all->map->mapy)
		return (1);
	if (ft_check_map(all) != 0)
		return (1);
	return (0);
}
