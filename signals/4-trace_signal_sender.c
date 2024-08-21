#include <stdio.h>
#include <signal.h>
#include "signals.h"

/**
* sigquit_handler - signal register
* @signum: code
* @si: pointer
* @ucontext: context
*/
void sigquit_handler(int signum, siginfo_t *si, void *ucontext)
{
	(void)ucontext;

	if (signum == SIGQUIT)
		printf("SIGQUIT sent by %u\n", si->si_pid);
}

/**
* trace_signal_sender - trace signal
* Return: 0, -1
*/
int trace_signal_sender(void)
{
	struct sigaction sa;

	sa.sa_sigaction = sigquit_handler;
	return (sigaction(SIGQUIT, &sa, NULL));
}
