#ifndef SIGNALS_H
#define SIGNALS_H

typedef void (*sighandler_t)(int);

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

/* Functions for Tasks*/
int handle_signal(void);

void (*current_handler_signal(void))(int);
void print_hello(int signum);
void set_print_hello(void);

int handle_sigaction(void);

void (*current_handler_sigaction(void))(int);

int trace_signal_sender(void);
void sigquit_handler(int signum);

int pid_exist(pid_t pid);
void all_in_one(void);
int sigset_init(sigset_t *set, int *signals);
int signals_block(int *signals);
int signals_unblock(int *signals);
int handle_pending(void (*handler)(int));

#endif /* SIGNALS_H */
