/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbate <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 10:41:10 by jbarbate          #+#    #+#             */
/*   Updated: 2023/05/16 09:31:26 by jbarbate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

/*For open*/
# include <fcntl.h>
/*For read*/
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

# define SIZE 256

typedef struct s_file
{
	char			*line;
	struct s_file	*next;
	struct s_file	*prev;
}				t_file;

t_file	*ft_create_file(char *line);
t_file	*ft_read(int fd);
t_file	*ft_del_ws(t_file *list);
void	ft_add_listelem(char *line, t_file *list);
void	ft_free_file(t_file *list);
void	ft_print_file(t_file *list);
int		ft_init(t_all *all);
int		ft_open_color(int *color, char *line, int *i, int count);
int		ft_file_size(t_file *list);
int		ft_parsing(char *filename, t_all *all);
int		ft_open(char *filename);
int		ft_check_file(t_file *list, t_all *all);
int		ft_check_elem(t_img *img);
int		ft_check_map(t_all *all);
int		ft_check_wall(char **map);
int		ft_convert_tab(t_all *all);
char	*ft_strndup(char *str, int size);
char	**ft_char_map(t_file *list);

#endif
