CC = gcc
CFLAGS = -Wall -Wextra -Werror -pedantic -g3
HEADER = socket.h
BETTY = betty

SRC0 = 0-server.c
OBJ0 = $(patsubst %.c, obj/%.o, $(SRC0))
NAME0 = bin/0-server

SRC1 = 1-server.c
OBJ1 = $(patsubst %.c, obj/%.o, $(SRC1))
NAME1 = bin/1-server

SRC2 = 2-client.c
OBJ2 = $(patsubst %.c, obj/%.o, $(SRC2))
NAME2 = bin/2-client

SRC3 = 3-server.c
OBJ3 = $(patsubst %.c, obj/%.o, $(SRC3))
NAME3 = bin/3-server

SRC4 = server.c status_code.c 4-request.c
OBJ4 = $(patsubst %.c, obj/%.o, $(SRC4))
NAME4 = todo_api_0

SRC5 = server.c status_code.c 5-queries.c
OBJ5 = $(patsubst %.c, obj/%.o, $(SRC5))
NAME5 = todo_api_1

SRC6 = server.c status_code.c 6-headers.c
OBJ6 = $(patsubst %.c, obj/%.o, $(SRC6))
NAME6 = todo_api_2

SRC7 = server.c status_code.c 7-body.c
OBJ7 = $(patsubst %.c, obj/%.o, $(SRC7))
NAME7 = todo_api_3

SRC8 = server.c status_code.c 8-create_todo.c
OBJ8 = $(patsubst %.c, obj/%.o, $(SRC8))
NAME8 = todo_api_4

SRC9 = server.c status_code.c 9-all_todo.c
OBJ9 = $(patsubst %.c, obj/%.o, $(SRC9))
NAME9 = todo_api_5

SRC10 = server.c status_code.c 10-get_query.c
OBJ10 = $(patsubst %.c, obj/%.o, $(SRC10))
NAME10 = todo_api_6

SRC11 = server.c status_code.c 11-delete_todo.c
OBJ11 = $(patsubst %.c, obj/%.o, $(SRC11))
NAME11 = todo_api_7

ALLOBJ = $(OBJ0) $(OBJ1) $(OBJ2) $(OBJ3) $(OBJ4) $(OBJ5) $(OBJ6) $(OBJ7) $(OBJ8) $(OBJ9) $(OBJ10) $(OBJ11)
ALLNAME = $(NAME0) $(NAME1) $(NAME2) $(NAME3) $(NAME4) $(NAME5) $(NAME6) $(NAME7) $(NAME8) $(NAME9) $(NAME10) $(NAME11)

.PHONY: task0 task1 task2 task3 todo_api_0 todo_api_1 todo_api_2 todo_api_3 todo_api_4 todo_api_5 todo_api_6 todo_api_7

all: task0 task1 task2 task3 todo_api_0 todo_api_1 todo_api_2 todo_api_3 todo_api_4 todo_api_5 todo_api_6 todo_api_7

directories:
	mkdir -p obj bin

obj/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Task 0-3
task0: directories $(OBJ0)
	$(CC) $(CFLAGS) $(OBJ0) -o $(NAME0)

task1: directories $(OBJ1)
	$(CC) $(CFLAGS) $(OBJ1) -o $(NAME1)

task2: directories $(OBJ2)
	$(CC) $(CFLAGS) $(OBJ2) -o $(NAME2)

task3: directories $(OBJ3)
	$(CC) $(CFLAGS) $(OBJ3) -o $(NAME3)

# API tasks 4 - 11
todo_api_0: directories $(HEADER) $(OBJ4)
	$(CC) $(CFLAGS) $(OBJ4) -o $(NAME4)

todo_api_1: directories $(HEADER) $(OBJ5)
	$(CC) $(CFLAGS) $(OBJ5) -o $(NAME5)

todo_api_2: directories $(HEADER) $(OBJ6)
	$(CC) $(CFLAGS) $(OBJ6) -o $(NAME6)

todo_api_3: directories $(HEADER) $(OBJ7)
	$(CC) $(CFLAGS) $(OBJ7) -o $(NAME7)

todo_api_4: directories $(HEADER) $(OBJ8)
	$(CC) $(CFLAGS) $(OBJ8) -o $(NAME8)

todo_api_5: directories $(HEADER) $(OBJ9)
	$(CC) $(CFLAGS) $(OBJ9) -o $(NAME9)

todo_api_6: directories $(HEADER) $(OBJ10)
	$(CC) $(CFLAGS) $(OBJ10) -o $(NAME10)

todo_api_7: directories $(HEADER) $(OBJ11)
	$(CC) $(CFLAGS) $(OBJ11) -o $(NAME11)

clean:
	$(foreach var, $(ALLNAME), $(RM) *~ $(var))

oclean:
	$(foreach var, $(ALLOBJ), $(RM) $(var))

fclean: clean oclean

re: oclean all

betty:
	$(BETTY) *.c *.h Makefile