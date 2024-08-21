#include <signal.h>
#include <stddef.h>
#include "signals.h"

/**
* signal_handler - handle signals
* @signum: code
* @si: pointer
* @ucontext: context
*/
void signal_handler(int signum, siginfo_t *si, void *ucontext)
{
	(void)signum;
	(void)ucontext;

	psiginfo(si, "Caught");
}

/**
* all_in_one - all signals
*/
void all_in_one(void)
{
	struct sigaction sigact;
	int sig;

	sigact.sa_flags |= SA_SIGINFO;
	sigact.sa_sigaction = signal_handler;
	for (sig = 1; sig < SIGRTMIN; sig++)
	{
		if (sig != SIGKILL && sig != SIGSTOP)
			sigaction(sig, &sigact, NULL);
	}
}
