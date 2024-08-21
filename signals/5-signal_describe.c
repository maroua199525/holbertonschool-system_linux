#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "signals.h"

/**
* main - describe signal
* @argc: counter
* @argv: vector
* Return: 0 or 1
*/
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		printf("Usage: %s <signum>\n", argv[0]);
		return (EXIT_FAILURE);
	}

	printf("%s: %s\n", argv[1], strsignal(atoi(argv[1])));

	return (EXIT_SUCCESS);
}
