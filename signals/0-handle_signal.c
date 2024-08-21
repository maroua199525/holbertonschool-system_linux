#include <stdio.h>
#include <signal.h>
#include "signals.h"

/**
* s_handler - Prints Gotcha
* @signalnum: signal code
*/
void s_handler(int signalnum)
{
	printf("Gotcha! [%i]\n", signalnum);
	fflush(stdout);
}

/**
* handle_signal - Handle for SIGINT signal
* Return: 0 or -1
*/
int handle_signal(void)
{
	if (signal(SIGINT, s_handler) == SIG_ERR)
		return (-1);
	return (0);
}
