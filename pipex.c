/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doji <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 16:32:04 by doji              #+#    #+#             */
/*   Updated: 2024/05/11 21:00:56 by doji             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	argv_check(int argc)
{
	if (argc != 5)
	{
		perror("argv_check");
		exit(EXIT_FAILURE);
	}
}

void	child_process(int pipefd[2], const char *argv, char **envp, int is_last)
{
	char	**args;
	char	*first_command;
	char	*exe_path;

	if (!is_last)
	{
		close(pipefd[0]);
		ft_dup2(pipefd[1], STDOUT_FILENO);
		close(pipefd[1]);
	}
	args = ft_split((char *)argv, " ", "\'\"");
	first_command = search_first_command((char *)argv);
	exe_path = ft_strjoin(EXE_PATH, first_command);
	execve((const char *)exe_path, (char *const *)args, (char *const *)envp);
	execve_error(&args, &first_command, &exe_path);
}

void	parent_process(int pipefd[2])
{
	close(pipefd[1]);
	ft_wait(NULL);
	ft_dup2(pipefd[0], STDIN_FILENO);
	close(pipefd[0]);
}

void	pipex(int argc, const char *argv[], const char *envp[])
{
	pid_t	pid;
	int		pipefd[2];
	int		i;

	i = 2;
	while (i <= argc - 3)
	{
		ft_pipe(pipefd);
		pid = ft_fork();
		if (pid == 0)
			child_process(pipefd, argv[i], (char **)envp, 0);
		else
			parent_process(pipefd);
		i++;
	}
	save_outfile(argv[argc - 1]);
	child_process(pipefd, argv[i], (char **)envp, 1);
}

int	main(int argc, const char *argv[], char *env[])
{
	const char	*envp[] = {search_path(env), NULL};

	argv_check(argc);
	infile_check(argv[1]);
	open_infile(argv[1]);
	pipex(argc, argv, envp);
	return (0);
}
