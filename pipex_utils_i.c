#include "pipex.h"

int argc_handler(int argc, const char *filepath)
{
	if (argc <= 1)
		exit(1);
	else if ((argc - 1) % 2 != 0)
		exit(1);
	if (access(filepath, F_OK) || access(filepath, R_OK) ||
			access(filepath, W_OK))
		exit(1);
	printf("%s", filepath);
	return (argc - 1);
}
