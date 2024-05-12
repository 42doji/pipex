/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doji <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 16:31:33 by doji              #+#    #+#             */
/*   Updated: 2024/05/11 20:19:02 by doji             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_list	*add_fd(int fd, t_list **list)
{
	t_list	*temp;
	t_list	*current;

	temp = (t_list *)malloc(sizeof(t_list));
	if (temp == NULL)
		return (NULL);
	temp->fd = fd;
	temp->str = NULL;
	temp->next = NULL;
	current = *list;
	if (*list == NULL)
		*list = temp;
	else
	{
		while (current->next != NULL)
			current = current->next;
		current->next = temp;
	}
	return (temp);
}

t_list	*search_fd(int fd, t_list **list)
{
	t_list	*temp;

	temp = *list;
	while (temp != NULL)
	{
		if (fd == temp->fd)
			return (temp);
		temp = temp->next;
	}
	return (add_fd(fd, list));
}

void	free_fd(t_list **list)
{
	t_list	*temp;

	temp = *list;
	if (temp->str != NULL)
	{
		free(temp->str);
		temp->str = NULL;
	}
	if (temp != NULL)
	{
		free(temp);
		temp = NULL;
	}
}

void	remove_fd(int fd, t_list **list)
{
	t_list	*temp;
	t_list	*current;

	temp = *list;
	if (fd == (*list)->fd)
	{
		*list = (*list)->next;
		free_fd(&temp);
		return ;
	}
	while (temp->next != NULL)
	{
		current = temp;
		temp = temp->next;
		if (fd == temp->fd)
		{
			current->next = temp->next;
			free_fd(&temp);
			return ;
		}
	}
}

int	len(char *str)
{
	int	count;

	count = 0;
	while (*str++ != '\0')
		count++;
	return (count);
}
