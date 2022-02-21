#include "signals.h"

/**
 * main -  sends the signal SIGINT to a process, given its PID
 * @argc: argument counter.
 * @argv: pointer 
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 **/

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		printf("Usage: %s <pid>\n", argv[0]);
		return (EXIT_FAILURE);
	}
	if (kill(atoi(argv[1]), SIGINT) == -1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
