/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efirmino <efirmino@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 22:44:49 by efirmino          #+#    #+#             */
/*   Updated: 2022/11/29 10:49:28 by efirmino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*	Principal function, it reads from a file descriptor and return a line
	('\n' included. Contains a static variable that keep in memory the exedent
	if the buffer size permit to read after the '\n'
	BUFFER_SIZE is not a parameter but defined at compiling and it defines the
	number of bytes the read function have to read.
						Parameter : the file desciptor
						Return Value : One line from the file descriptor)*/
char	*get_next_line(int fd)
{
	static t_list	*draft;
	char			*next_line;
	int				read_size;

	next_line = 0;
	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, next_line, 0) == -1)
		return (0);
	read_size = 1;
	ft_read_to_draft(fd, &draft, &read_size);
	if (!(draft))
		return (0);
	ft_get_line(draft, &next_line);
	if (next_line[0] == '\0')
	{
		free(next_line);
		ft_free_list(draft);
		draft = 0;
		return (0);
	}
	ft_clean_draft(&draft);
	return (next_line);
}

/*	This function read from the file descriptor and stock the content in a 
	linked list passed by address (my choice, can be done with a string)
						Parameters : The file descriptor it have to read from,
									 The linked list it have to put content in
						Return Value : No return Value, it put the contend 
										directly in the linked list. */
void	ft_read_to_draft(int fd, t_list **draft, int *rd_size)
{
	char	buffer[BUFFER_SIZE + 1];

	*rd_size = 1;
	while (!(ft_new_line_in(*draft)) && *rd_size > 0)
	{
		*rd_size = (int)read(fd, buffer, BUFFER_SIZE);
		if (*rd_size == -1)
		{
			ft_free_list(*draft);
			break ;
		}
		buffer[*rd_size] = '\0';
		ft_add_to_draft(buffer, rd_size, draft);
	}
	return ;
}

/*	Look for a new line ('\n') in a linked list, so the content have to be 
	a pointer on string (char *).
							Parameter :	The list it have to look '\n' in.
							Return Value :	1 : A '\n' has been found
											0 : No '\n' found in the list. */
int	ft_new_line_in(t_list *list)
{
	t_list	*curent;
	int		i;

	if (list == 0)
		return (0);
	curent = list;
	while (curent->next)
		curent = curent->next;
	i = 0;
	while (curent->content[i])
	{
		if (curent->content[i] == '\n')
			return (1);
		i++;
	}	
	return (0);
}

/*	This function take a string (char *) and add it to a linked list,
	no matter if the list if empty on not.
						Parameters	:	The string (content) it adds,
										The size of this string, so it can 
											allocate sufisant memory,
										The list in wich the content will be 
											added
						Return Value :	No return value, the content is added
											to the list in parameter*/
void	ft_add_to_draft(char *buffer, int *read_size, t_list **draft)
{
	t_list	*new_element;
	t_list	*curent;
	int		i;

	new_element = malloc(sizeof(t_list));
	new_element->content = malloc(sizeof(char) * (*read_size + 1));
	if (!(new_element) || !(new_element->content))
		return ;
	new_element->next = 0;
	i = 0;
	while (buffer[i])
	{
		new_element->content[i] = buffer[i];
		i++;
	}
	new_element->content[i] = '\0';
	if (*draft == 0)
	{
		*draft = new_element;
		return ;
	}
	curent = *draft;
	while (curent->next)
			curent = curent->next;
	curent->next = new_element;
}

/*	This function allocate sufisant memory to write the contend read 
	('\n' inclded) and return a freshly allocated string with the content
					Parameter	:	the list it have to extract content from
					Return Value :	A fresh allocated string with the wanted
										content. */
void	ft_get_line(t_list *draft, char **line)
{
	int		i;
	int		j;
	char	*str;

	ft_line_len(draft, line);
	j = 0;
	str = *line;
	if (!(str))
		return ;
	while (draft)
	{
		i = 0;
		while (draft->content[i])
		{
			if (draft->content[i] == '\n')
			{
				str[j++] = draft->content[i];
				break ;
			}
			str[j++] = draft->content[i++];
		}
		draft = draft->next;
	}
	str[j] = '\0';
	return ;
}
