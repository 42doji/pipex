#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	main(int argc, char *argv[], char **env)
{
	pid_t	pid;
	int 	pipefd[2];
	char	buf;

	pid = fork();
	if (pid == 0)
	{
		pid_t pid2;

		close(pipefd[0]);
		dup2(pipefd[1], STDOUT_FILENO);
		dup2(STDIN_FILEN, pipefd[1]);
		pid = fork();
		if (pid == 0)
		{
			execve
		}
	}
	else if (pid > 0)
	{
		int 	n;

		close(pipefd[1]);
		wait(NULL);
		n = read(pipefd[0], buffer, 1);
		while (n)
		{
			write(STDOUT_FILENO, &buffer, 1);
			n = read(pipefd[0], buffer, 1);
		}
		close(pipefd[0]);
		exit(EXIT_SUCCESS);
	}
	return (0);
}
