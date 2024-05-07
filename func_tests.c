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
		close(pipefd[0]);
		char *args[] = {"ls", "-la", NULL};
		dup2(pipefd[1], STDOUT_FILENO);
		execve("/bin/ls", args, NULL);
		exit(EXIT_FAILURE);
	}
	else if (pid > 0)
	{
		char	buffer[1024];
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