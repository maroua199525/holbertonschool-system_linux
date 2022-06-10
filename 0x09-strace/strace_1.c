#include <stdio.h>
#include "strace.h"

/**
* main - program that executes and
* traces a given command.
* @argc: arg count
* @argv: list of arguments
* @en: list of environ variables
* Return: 0 on success, 1 otherwise
*/
int main(int argc, char **argv, char **en)
{
	pid_t child = 0;
	int status = 0, flag = 0;
	struct user_regs_struct regs;

	if (argc < 2)
	{
		printf("./strace_1 command [args...]\n");
		return (1);
	}
	setbuf(stdout, NULL);
	child = fork();
	if (child == 0)
	{
		ptrace(PTRACE_TRACEME, child, NULL, NULL);
		raise(SIGSTOP);
		execve(argv[1], &(argv[1]), en);
	}
	else
	{
		wait(&status);
		if (WIFEXITED(status))
			return (0);
		ptrace(PTRACE_SYSCALL, child, NULL, NULL);
		while (wait(&status) && !WIFEXITED(status))
		{
			if (flag)
				(printf("\n"), flag = 0);
			memset(&regs, 0, sizeof(regs));
			ptrace(PTRACE_GETREGS, child, NULL, &regs);
			if (WSTOPSIG(status) == SIGTRAP && (long) regs.rax == -38)
			{
				flag = 1;
				printf("%s", (char *) syscalls_64_g[(unsigned long)regs.orig_rax].name);
			}
			ptrace(PTRACE_SYSCALL, child, NULL, NULL);
		}
		printf("\n");
	}
	return (0);
}
