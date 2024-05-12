/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doji <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 16:31:24 by doji              #+#    #+#             */
/*   Updated: 2024/05/11 20:37:44 by doji             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	search_next_line(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*join_and_free(char **s1, char *s2)
{
	char	*new;
	int		s1_len;
	int		s2_len;
	int		i;

	if (*s1 == NULL)
		s1_len = 0;
	else
		s1_len = len(*s1);
	s2_len = len(s2);
	new = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (new == NULL)
		return (NULL);
	i = 0;
	while (s1_len-- != 0)
	{
		new[i] = (*s1)[i];
		i++;
	}
	while (s2_len-- != 0)
		new[i++] = *s2++;
	new[i] = '\0';
	free(*s1);
	*s1 = NULL;
	return (new);
}

char	*move(char **str, int n_idx)
{
	char	*new;
	int		new_len;
	int		i;

	if (n_idx == -1 || len(*str) == n_idx + 1)
	{
		free(*str);
		*str = NULL;
		return (NULL);
	}
	new_len = len(&((*str)[n_idx + 1]));
	new = (char *)malloc(sizeof(char) * (new_len + 1));
	i = 0;
	while ((*str)[n_idx + 1 + i] != '\0')
	{
		new[i] = (*str)[n_idx + 1 + i];
		i++;
	}
	new[i] = '\0';
	free(*str);
	*str = NULL;
	return (new);
}

char	*str_dup(char **str, int n_idx)
{
	char	*result;
	int		size;
	int		i;

	if (n_idx == -1)
		size = len(*str);
	else
		size = n_idx + 1;
	result = (char *)malloc(sizeof(char) * (size + 1));
	if (result == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		result[i] = (*str)[i];
		i++;
	}
	result[i] = '\0';
	*str = move(str, n_idx);
	return (result);
}

char	*get_next_line(int fd)
{
	static t_list	*list;
	t_list			*current;
	char			buf[BUFFER_SIZE + 1];
	char			*result;
	int				ret;

	current = search_fd(fd, &list);
	result = NULL;
	ret = read(fd, buf, BUFFER_SIZE);
	while (ret > 0)
	{
		buf[ret] = '\0';
		current->str = join_and_free(&(current->str), buf);
		if (search_next_line(current->str) >= 0)
			return (str_dup(&(current->str), search_next_line(current->str)));
		ret = read(fd, buf, BUFFER_SIZE);
	}
	if (current->str != NULL)
		result = str_dup(&(current->str), search_next_line(current->str));
	if (current->str == NULL)
		remove_fd(fd, &list);
	return (result);
}
