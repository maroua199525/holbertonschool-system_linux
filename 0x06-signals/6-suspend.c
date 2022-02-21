#include "signals.h"

/**
 * sig_handler - action to take on SIGINT
 * @signal: signal value to print
 */
void sig_handler(int signal)
{
	printf("Caught %d\n", signal);
	fflush(stdout);
}

/**
 * main - sets a handler for the signal SIGINT, and exits right after the signal is received and handled
 *
 * Return: EXIT_SUCCESS, or EXIT_FAILURE
 */
int main(void)
{
	struct sigaction new;

	new.sa_handler = sig_handler;
	sigaction(SIGINT, &new, NULL);
	pause();
	puts("Signal received");
	return (EXIT_SUCCESS);
}
