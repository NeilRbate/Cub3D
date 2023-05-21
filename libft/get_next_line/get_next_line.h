/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efirmino <efirmino@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 22:43:21 by efirmino          #+#    #+#             */
/*   Updated: 2022/11/29 10:59:31 by efirmino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 54
# endif

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}					t_list;

char	*get_next_line(int fd);
void	ft_read_to_draft(int fd, t_list **draft, int *read_size);
int		ft_new_line_in(t_list *list);
void	ft_add_to_draft(char *buffer, int *read_size, t_list **draft);
void	ft_get_line(t_list *draft, char **line);

/* UTILS - UTILS - UTILS - UTILS - UTILS - UTILS - UTILS - UTILS - UTILS */

void	ft_line_len(t_list *draft, char **line);
void	ft_clean_draft(t_list **draft);
void	ft_free_list(t_list	*draft);
size_t	ft_len(char *str);
void	new_checker(t_list *new, t_list **draft);

/* UTILS - UTILS - UTILS - UTILS - UTILS - UTILS - UTILS - UTILS - UTILS */

#endif