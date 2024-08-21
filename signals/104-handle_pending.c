#include <signal.h>
#include <stddef.h>
#include "signals.h"

/**
* handle_pending - manage pending signals
* @handler: pointer function
* Return: 0, -1
*/
int handle_pending(void (*handler)(int))
{
	struct sigaction sa;
	sigset_t sigset;
	int sig, retval;

	if (sigemptyset(&sigset) != 0)
		return (-1);

	if (sigpending(&sigset) != 0)
		return (-1);

	sa.sa_handler = handler;

	for (sig = 1; sig < SIGRTMIN; sig++)
	{
		retval = sigismember(&sigset, sig);
		if (retval == -1)
			return (-1);
		if (retval == 1)
			sigaction(sig, &sa, NULL);
	}

	return (0);
}
