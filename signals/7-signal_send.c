#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <signal.h>
#include "signals.h"

/**
* main - send signal to process
* @argc: counter
* @argv: vector
* Return: 0 , 1
*/
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		printf("Usage: %s <pid>\n", argv[0]);
		return (EXIT_FAILURE);
	}

	if (kill((pid_t)atoi(argv[1]), SIGINT) != 0)
		return (EXIT_FAILURE);

	return (EXIT_SUCCESS);
}
