#include "My_ls.h"

/**
 * main - entry point of the ls program
 * @argc: number of arguments
 * @argv: pointer to array of strings
 *
 * Return: 1 on success
 */

int main(int argc, char *argv[])
{
	(void)argv;
	DIR *current;
	struct dirent *directory;

	if (argc == 1)
	{
		current = opendir(".");

		if (current)
		{
			while ((directory = readdir(current)) != NULL)
			{
				if ((directory->d_name)[0] != '.')
					printf("%s  ", directory->d_name);
			}
			printf("\n");
			closedir(current);
		}
	}
	return (0);
}
