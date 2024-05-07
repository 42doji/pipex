//
// Created by dotte on 2024-05-07.
//
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void	exit_test(void)
{
	printf("exit");
	exit(EXIT_SUCCESS);
}

int	main(void)
{
	exit_test();
	return (0);
}