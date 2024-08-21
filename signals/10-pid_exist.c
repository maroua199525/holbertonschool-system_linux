#include <sys/types.h>
#include <signal.h>

/**
* pid_exist - check PID
* @pid: pid
* Return: 0, 1
*/
int pid_exist(pid_t pid)
{
	return (kill(pid, 0) + 1);
}
