#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

/**
* main - displays the information contained in the ELF sections an ELF file
* @argc: arguments
* @argv: argument
* @env:  environment
* Return: -1 in fail and 0 in success
*/
int main(int argc, char **argv, char **env)
{
	char *args[] = {"/usr/bin/readelf", "-W", "-S", "", NULL};

	(void)argc;
	args[3] = argv[1];
	if (execve("/usr/bin/readelf", args, env) == -1)
	{
		perror("execv");
		return (-1);
	}
	return (0);
}
