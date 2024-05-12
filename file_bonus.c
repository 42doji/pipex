/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doji <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 16:31:16 by doji              #+#    #+#             */
/*   Updated: 2024/05/11 20:12:34 by doji             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	infile_check(const char *pathname)
{
	if (access(pathname, F_OK) == -1)
	{
		write(STDERR_FILENO, "Not exist file.\n", 16);
		exit(EXIT_FAILURE);
	}
	if (access(pathname, R_OK) == -1)
	{
		write(STDERR_FILENO, "Read Error.\n", 12);
		exit(EXIT_FAILURE);
	}
	if (access(pathname, W_OK) == -1)
	{
		write(STDERR_FILENO, "Write Error.\n", 13);
		exit(EXIT_FAILURE);
	}
}

void	open_infile(const char *pathname)
{
	const int	fd = open(pathname, O_RDONLY);

	if (fd == -1)
	{
		perror("Failed to open file");
		exit(EXIT_FAILURE);
	}
	ft_dup2(fd, STDIN_FILENO);
	close(fd);
}

void	save_outfile(const char *pathname, int is_here_doc)
{
	int	file_fd;

	if (is_here_doc)
		file_fd = open(pathname, O_RDWR | O_CREAT | O_APPEND, 0644);
	else
		file_fd = open(pathname, O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (file_fd == -1)
	{
		perror("Failed to open file");
		exit(EXIT_FAILURE);
	}
	ft_dup2(file_fd, STDOUT_FILENO);
	close(file_fd);
}
