#include "strace.h"

void _trace_child(char **argv, char **env);
void _trace_parent(pid_t child_pid);
int _await_syscall(pid_t child_pid);

/**
 * main - entry point
 * @argc: argument count
 * @argv: argument vector
 * @env: environ
 * Return: EXIT_SUCCESS or error.
 */
int main(int argc, char **argv, char **env)
{
	pid_t child_pid;

	if (argc < 2)
	{
		printf("Usage: %s command [args...]\n", argv[0]);
		return (EXIT_FAILURE);
	}
	setbuf(stdout, NULL);
	child_pid = fork();
	if (child_pid == -1)
	{
		dprintf(STDERR_FILENO, "Fork failed: %d\n", errno);
		exit(-1);
	}
	else if (!child_pid)
		_trace_child(argv, env);
	else
		_trace_parent(child_pid);
	return (0);
}
/**
 * _trace_child - traces child process
 * @argv: argument vector for execve
 * @env: environ for execve
 */
void _trace_child(char **argv, char **env)
{
	ptrace(PTRACE_TRACEME, 0, 0, 0);
	kill(getpid(), SIGSTOP);
	if (execve(argv[1], argv + 1, env) == -1)
	{
		dprintf(STDERR_FILENO, "Exec failed: %d\n", errno);
		exit(-1);
	}
}

/**
 * _trace_parent - calls made by tracing parent
 * @child_pid: pid of child to trace
 */
void _trace_parent(pid_t child_pid)
{
	int status;
	struct user_regs_struct registers;

	waitpid(child_pid, &status, 0);
	ptrace(PTRACE_SETOPTIONS, child_pid, 0, PTRACE_O_TRACESYSGOOD);
	while (1)
	{
		if (_await_syscall(child_pid))
			break;
		memset(&registers, 0, sizeof(registers));
		ptrace(PTRACE_GETREGS, child_pid, 0, &registers);
		printf("%lu\n", (long)registers.orig_rax);
		if (_await_syscall(child_pid))
			break;
	}
}

/**
 * _await_syscall - waits for a syscall
 * @child_pid: pid of process to await
 * Return: 0 if child stopped, 1 if exited
 */
int _await_syscall(pid_t child_pid)
{
	int status;

	while (1)
	{
		ptrace(PTRACE_SYSCALL, child_pid, 0, 0);
		waitpid(child_pid, &status, 0);
		if (WIFSTOPPED(status) && WSTOPSIG(status) & 0x80)
			return (0);
		if (WIFEXITED(status))
			return (1);
	}
}
