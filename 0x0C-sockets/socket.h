#ifndef _HTTP_H_
#define _HTTP_H_

#include <stdio.h>
#include <sys/socket.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>

#define buffSize 9216
#define PORT 8080

#define RESPONSE_200 "HTTP/1.1 200 OK\r\n\r\n"

int setup_socket(void);
int recive_messages(int socketId);
int send_response(int client_sd, char *response);
int parse_request(int clientId, char *buf);

#endif