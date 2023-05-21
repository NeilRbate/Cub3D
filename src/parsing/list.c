/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbate <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 11:15:26 by jbarbate          #+#    #+#             */
/*   Updated: 2023/04/20 13:26:26 by jbarbate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	ft_free_file(t_file *list)
{
	if (!list)
		return ;
	while (list->next)
	{
		if (list->line)
			free(list->line);
		list = list->next;
		free(list->prev);
		list->prev = NULL;
	}
	if (list->line)
		free(list->line);
	free(list);
	list = NULL;
}

void	ft_print_file(t_file *list)
{
	while (list)
	{
		if (list->line)
			ft_putstr_fd(list->line, 1);
		list = list->next;
	}
}

int	ft_file_size(t_file *list)
{
	int	i;

	i = 0;
	if (!list)
		return (0);
	while (list->next != NULL)
	{
		i++;
		list = list->next;
	}
	i++;
	return (i);
}

t_file	*ft_create_file(char *line)
{
	t_file	*list;

	list = malloc(sizeof(*list));
	if (!list)
		return (ft_putendl_fd("Error\nMalloc fail", 2), NULL);
	list->line = line;
	list->next = NULL;
	list->prev = NULL;
	return (list);
}

void	ft_add_listelem(char *line, t_file *list)
{
	t_file	*last;

	last = ft_create_file(line);
	while (list->next != NULL)
		list = list->next;
	last->prev = list;
	last->next = NULL;
	list->next = last;
}
