#include <unistd.h>
#include <stdio.h>

int	main(int argc,const char *argv[], char **envp)
{
	if (!access("README.md", F_OK))
	{
		printf("ok");
	}
	else
	{
		printf("nok");
	}
}
