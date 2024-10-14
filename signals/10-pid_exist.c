#include <signal.h>

/**
 * pid_exist - check if a pid is running
 * @pid: pid to check
 *
 * Return: 1 if exists, 0 if not
 */
int pid_exist(pid_t pid)
{
	return (kill(pid, 0));
}