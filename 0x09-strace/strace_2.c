#include "strace.h"

/**
 * syscall_param - print the parametres of a given syscall
 * @registers: struct with the register syscall
 * Return: nothing
 */
void syscall_param(struct user_regs_struct registers)
{
	unsigned long parameter[6] = {0};
	size_t nb_params, i = 0;

	parameter[0] = (unsigned long) registers.rdi;
	parameter[1] = (unsigned long) registers.rsi;
	parameter[2] = (unsigned long) registers.rdx;
	parameter[3] = (unsigned long) registers.r10;
	parameter[4] = (unsigned long) registers.r8;
	parameter[5] = (unsigned long) registers.r9;

	nb_params = syscalls_64_g[(unsigned long)registers.orig_rax].nb_params;

	while (i < nb_params)
	{
		if (i > 0)
			printf(", ");
		if (syscalls_64_g[(unsigned long) registers.orig_rax].params[i] == VARARGS)
			printf("...");
		else if (syscalls_64_g[(unsigned long) registers.orig_rax].params[i] != VOID)
			printf("%#lx", parameter[i]);
		i++;
	}
}


/**
 * main - use ptrace for getting the syscall name and return value
 * @ac: number of arguments
 * @av: list of arguments
 * @en: list of environ variables
 * Return: 0 on success, 1 otherwise
 */
int main(int ac, char **av, char **en)
{
	pid_t child = 0;
	int status = 0, flag = 0;
	struct user_regs_struct registers;

	if (ac < 2)
	{
		printf("./strace_3 command [args...]\n");
		return (1);
	}
	setbuf(stdout, NULL);
	child = fork();
	if (child == 0)
	{
		ptrace(PTRACE_TRACEME, child, NULL, NULL);
		raise(SIGSTOP);
		execve(av[1], &(av[1]), en);
	}
	else
	{
		wait(&status);
		if (WIFEXITED(status))
			return (0);
		ptrace(PTRACE_SYSCALL, child, NULL, NULL);
		while (wait(&status) && !WIFEXITED(status))
		{
			memset(&registers, 0, sizeof(registers));
			ptrace(PTRACE_GETREGS, child, NULL, &registers);
			if (flag)
				(printf(") = %#lx\n", (unsigned long) registers.rax), flag = 0);
			if (WSTOPSIG(status) == SIGTRAP && (long) registers.rax == -38)
				(printf("%s(",
					(char *) syscalls_64_g[(unsigned long)registers.orig_rax].name),
				 syscall_param(registers), flag = 1);
			ptrace(PTRACE_SYSCALL, child, NULL, NULL);
		}
		printf(") = ?\n");
	}
	return (0);
}
