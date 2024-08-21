#include "signals.h"

/**
 * sig_handler - action to take on SIGQUIT intercept
 * @signal: number of the signal that caused invocation of the handler
 * @info: pointer to a siginfo_t
 * @ptr: pointer to a ucontext_t
 */
void sig_handler(int signal, siginfo_t *info, void *ptr)
{
	(void) signal;
	(void) ptr;
	psiginfo(info, "Caught");
}

/**
 * all_in_one - sets up a single handler for all the signals
 */
void all_in_one(void)
{
	int signal;
	struct sigaction action;

	action.sa_flags = SA_SIGINFO;
	action.sa_sigaction = sig_handler;
	for (signal = 1; signal <= SIGRTMAX; ++signal)
		sigaction(signal, &action, NULL);
}
