#include <signal.h>
#include <stddef.h>
#include "signals.h"

/**
* current_handler_signal - return pointer to current handler signal
* Return: pointer
*/
void (*current_handler_signal(void))(int)
{
	sighandler_t handler;

	handler = signal(SIGINT, SIG_IGN);
	if (handler == SIG_ERR)
		return (NULL);

	if (signal(SIGINT, handler) == SIG_ERR)
		return (NULL);

	return (handler);
}
