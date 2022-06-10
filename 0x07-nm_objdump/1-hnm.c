#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

/**
 * main - display information from object files.
 * @argc: the count of args
 * @argv: the args
 * @env:  the environment
 * Return: -1 in fail and 0 in success
 */
int main(int argc, char **argv, char **env)
{
	char *args[] = {"/usr/bin/objdump", "-s", "-f", "", NULL};

	(void)argc;
	args[3] = argv[1];
	if (execve("/usr/bin/objdump", args, env) == -1)
	{
		perror("execv");
		return (-1);
	}
	return (0);
}
