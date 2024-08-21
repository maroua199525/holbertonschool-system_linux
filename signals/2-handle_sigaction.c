#include <stdio.h>
#include <signal.h>
#include "signals.h"

/**
 * sigint_handler - print gotcha
 *
 * @signum: signal code
 */
void sigint_handler(int signum)
{
	printf("Gotcha! [%i]\n", signum);
	fflush(stdout);
}


/**
 * handle_sigaction - handler for SIGINT
 * Return: 0 or, -1
 */
int handle_sigaction(void)
{
	struct sigaction sigact;

	sigact.sa_handler = sigint_handler;

	return (sigaction(SIGINT, &sigact, NULL));
}
