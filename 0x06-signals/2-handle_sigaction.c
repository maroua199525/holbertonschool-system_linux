#include "signals.h"

/**
 * sig_handler - action to take on SIGINT delivery
 * @signal: signal value to print
 */
void sig_handler(int signal)
{
	printf("Gotcha! [%i]\n", signal);
	fflush(stdout);
}
/**
 * handle_sigaction - set handler for the signal SIGINT
 *
 * Return: 0 on success, or -1 on error
 */
int handle_sigaction(void)
{
	struct sigaction signal_action;

	signal_action.sa_handler = sig_handler;
	signal_action.sa_flags = 0;

	if (sigaction(SIGINT, &signal_action, NULL) < 0)
		return (-1);
	return (0);
}
