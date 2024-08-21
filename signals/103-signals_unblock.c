#include <signal.h>
#include <stddef.h>
#include "signals.h"

/**
* sigset_init - signal set
* @set: pointer
* @signals: array
* Return: 0, -1
*/
int sigset_init(sigset_t *set, int *signals)
{
	int i;

	if (sigemptyset(set) == -1)
		return (-1);

	for (i = 0; signals[i]; i++)
	{
		if (sigaddset(set, signals[i]) != 0)
			return (-1);
	}

	return (0);
}

/**
* signals_unblock - Unblock signal
* @signals: array
* Return: 0, -1
*/
int signals_unblock(int *signals)
{
	sigset_t sigset;

	if (sigset_init(&sigset, signals) != 0)
		return (-1);

	return (sigprocmask(SIG_UNBLOCK, &sigset, NULL));
}
