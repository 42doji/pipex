/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doji <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 16:32:37 by doji              #+#    #+#             */
/*   Updated: 2024/05/11 20:29:40 by doji             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	execve_error(char ***args, char **cmd, char **path)
{
	int	i;

	i = 0;
	while ((*args)[i])
	{
		free((*args)[i]);
		(*args)[i++] = NULL;
	}
	free(*args);
	free(*cmd);
	free(*path);
	*args = NULL;
	*cmd = NULL;
	*path = NULL;
	perror("execve error");
	exit(EXIT_FAILURE);
}

void	ft_pipe(int pipefd[2])
{
	if (pipe(pipefd) == -1)
	{
		perror("pipe error");
		exit(EXIT_FAILURE);
	}
}

pid_t	ft_fork(void)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	return (pid);
}

void	ft_dup2(int pipefd, int no)
{
	if (dup2(pipefd, no) == -1)
	{
		perror("dup2");
		exit(EXIT_FAILURE);
	}
}

void	ft_wait(int *status)
{
	if (wait(status) == -1)
	{
		perror("wait");
		exit(EXIT_FAILURE);
	}
}
