#include "signals.h"

/**
 * main - prints a description of a given signal
 * @argc: argument count
 * @argv: argument vector
 * Return: 1 or -1
 */
int main(int argc, char **argv)
{
	if (argc != 2)
	{
		printf("Usage: %s <signum>\n", argv[0]);
		return (EXIT_FAILURE);
	}
	printf("%d Unknown signal %d\n", atoi(argv[1]), strsignal(atoi(argv[1])));
	return (EXIT_SUCCESS);
}
