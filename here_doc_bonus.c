/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doji <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 16:31:57 by doji              #+#    #+#             */
/*   Updated: 2024/05/11 20:27:21 by doji             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	is_same(char *str, char *limiter)
{
	while (*limiter)
	{
		if (*str != *limiter)
			return (0);
		str++;
		limiter++;
	}
	return (1);
}

int	limiter_check(char *str, char *limiter)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == *limiter)
			if (is_same(&(str[i + 1]), limiter + 1))
				return (i);
		i++;
	}
	return (-1);
}

void	write_stdout(int write_fd, char **str)
{
	write(write_fd, *str, strlen(*str));
	free(*str);
	*str = NULL;
}

int	is_here_doc(const char *argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (argv[i] != HERE_DOC[i])
			return (0);
		i++;
	}
	return (1);
}

void	here_doc_input(const char *argv[])
{
	char	*str;
	int		pipefd[2];
	int		limiter_idx;

	ft_pipe(pipefd);
	limiter_idx = -1;
	while (1)
	{
		str = get_next_line(STDIN_FILENO);
		if (limiter_check(str, (char *)argv[2]) >= 0)
		{
			limiter_idx = limiter_check(str, (char *)argv[2]);
			str[limiter_idx] = '\0';
			break ;
		}
		write_stdout(pipefd[1], &str);
	}
	write_stdout(pipefd[1], &str);
	close(pipefd[1]);
	ft_dup2(pipefd[0], STDIN_FILENO);
	close(pipefd[0]);
}
