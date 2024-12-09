C= gcc
FLAGS = -Wall -Werror -Wextra -pedantic -std=gnu99 -g

source_0 = strace_0.c
object_0 = $(source_0:.c=.o)
name_0 = strace_0

source_1 = strace_1.c
object_1 = $(source_1:.c=.o)
name_1 = strace_1

source_2 = strace_2.c
object_2 = $(source_2:.c=.o)
name_2 = strace_2

source_3 = strace_3.c
object_3 = $(source_3:.c=.o)
name_3 = strace_3

strace_0: strace.h $(object_0)
	$(CC) $(object_0) -o $(name_0)

strace_1: $(object_1) $(object_5)
	$(CC) $(object_1) -o $(name_1)

strace_2: strace.h $(object_2)
	$(CC) $(object_2) -o $(name_2)

strace_3: strace.h $(object_3)
	$(CC) $(object_3) -o $(name_3)
