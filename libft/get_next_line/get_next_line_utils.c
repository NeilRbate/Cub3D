/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efirmino <efirmino@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 22:45:23 by efirmino          #+#    #+#             */
/*   Updated: 2022/11/29 10:57:22 by efirmino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*	Sub function of : get_line
	Allocate the necessary amount of memory for a complete line and returns
	a pointer of the memory emplacement
				Parameter	:	A pointer on the first list of the linked list
				Return Value :	A pointer on the memory emplacement allocated */
void	ft_line_len(t_list *draft, char **line)
{
	int	i;
	int	len;

	len = 0;
	while (draft)
	{
		i = 0;
		while (draft->content[i])
		{
			if (draft->content[i] == '\n')
			{
				len++;
				break ;
			}
			len++;
			i++;
		}
		draft = draft->next;
	}
	*line = malloc(sizeof(char) * (len + 1));
}

/*	Clean-up the linked list by removing the contend already retuned,
	permit to keep in memory the exedent wich will be needed on the next
	function call, then free the entire list and initialise the pointer of the 
	list to the new list (with only exedent charaters)
				Parameters	:	A pointer on the linked list to clean
				Return Valur :	No return value, the list is cleaned up
									by his memory address */
void	ft_clean_draft(t_list **draft)
{
	t_list	*curent;
	t_list	*new;
	int		i;
	int		j;

	curent = *draft;
	while (curent->next)
		curent = curent->next;
	i = 0;
	while (curent->content[i] && curent->content[i] != '\n')
		i++;
	if (curent->content && curent->content[i] == '\n')
		i++;
	new = malloc(sizeof(t_list));
	new->content = malloc(sizeof(char) * ((ft_len(curent->content) - i) + 1));
	new->next = 0;
	if (new->content == 0 || new == 0)
		return ;
	j = 0;
	while (curent->content[i])
		new->content[j++] = curent->content[i++];
	new->content[j] = '\0';
	ft_free_list(*draft);
	new_checker(new, draft);
}

/*	Free all the linked list. Go through every element of the list and free his
	content then the list himself, keeps the pointer on the next list on a 
	temporary variable
						Parameters	:	The list to be freed,
						Return Value :	No return value */
void	ft_free_list(t_list	*draft)
{
	t_list	*current;
	t_list	*next;

	current = draft;
	while (current)
	{
		free(current->content);
		current->content = 0;
		next = current->next;
		free(current);
		current = 0;
		current = next;
	}
}

/*	Get the lenth of a string, Go through a string and get his lenth to
	allocate memory for this string for exemple
				Parameter	:	A pointer on the first character on a string
				Return Value :	the lenth of this strinh */
size_t	ft_len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	new_checker(t_list *new, t_list **draft)
{
	if (new->content[0] == '\0')
	{
		free(new->content);
		free(new);
		*draft = 0;
		return ;
	}	
	*draft = new;
}
