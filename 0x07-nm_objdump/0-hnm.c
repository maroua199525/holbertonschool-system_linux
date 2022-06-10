#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

/**
 * main - entry point to hnm
 * @argc: command line arg count
 * @argv: command line arg array
 * @env:  the environment
 * Return: 0 on succes -1 in failure.
 */
int main(int argc, char **argv, char **env)
{
	char *command[] = {"./hnm", "-p", "", NULL};

	(void)argc;

	command[2] = argv[1];
	if (execve("/usr/bin/nm", command, env) == -1)
	{
		perror("execv");
		return (-1);
	}
	return (0);
}
