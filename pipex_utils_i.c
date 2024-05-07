#include "pipex.h"

int argc_handler(int argc)
{
	int r;

	r = 0;
	if (argc <= 1 )
		printf("Error: Needs Args.\n");
	else if (argc / 2 - 1 != 0)
		printf("Error: Wrong Arg counts.");
	else
		r = 1;
	if (!r)
		exit(0);
	else
		return (argc - 1);
}
