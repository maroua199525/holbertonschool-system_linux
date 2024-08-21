#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <signal.h>
#include "signals.h"

/**
* signal_handler - self explanatory
* @signum: code
*/
void signal_handler(int signum)
{
	printf("Caught %i\n", signum);

	if (sigaction(SIGINT, NULL, NULL) != 0)
	{
		return;
	}
}

/**
* main - caught signal
* @argc: counter
* @argv: vector
* Return: int
*/
int main(int argc, char *argv[])
{
	struct sigaction sa;

	(void)argc;
	(void)argv;

	sa.sa_handler = signal_handler;
	if (sigaction(SIGINT, &sa, NULL) != 0)
	{
		return (EXIT_FAILURE);
	}

	pause();
	if (errno == EINTR)
		printf("Signal received\n");

	return (EXIT_SUCCESS);
}
