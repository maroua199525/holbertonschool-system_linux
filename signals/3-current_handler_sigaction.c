#include <signal.h>
#include <stddef.h>
#include "signals.h"

/**
 * current_handler_sigaction - handler of sigint
 * Return: pointer
 */
void (*current_handler_sigaction(void))(int)
{
	struct sigaction curr_sigact;

	if (sigaction(SIGINT, NULL, &curr_sigact) == -1)
		return (NULL);

	if (sigaction(SIGINT, &curr_sigact, NULL) == -1)
		return (NULL);

	return (curr_sigact.sa_handler);
}
