#include "socket.h"

/**
 * main - Opens an IPv4/TCP socket, and listens to traffic on port 8080.
 * - Accept an entering connection
 * - Print the IP address of the connected client
 * - Wait for an incoming message from the connected client
 * - Print the full received HTTP request
 * - Print the break-down of the first line of the received HTTP request
 * - Send back a response to the connected client (HTTP 200 OK)
 * - Close the connection with the client
 * - Wait for the next connection
 *
 * Return: Return: EXIT_SUCCESS if successful otherwise EXIT_FAILURE
 */
int main(void)
{
	return (start_server(7));
}

/**
 * response - Print and send HTTP response
 * @buf: buffer to split and print
 *
 * Return: Always EXIT_SUCCESS
 */
int response(char *buf)
{
	char *delim1 = " \r\t\n";
	char *delim2 = "& ";
	char *all_body, *body;
	int i = 10;

	strtok(buf, delim1);
	printf("Path: %s\n", strtok(NULL, delim1));
	for (i = 12; i; i--)
		all_body = strtok(NULL, delim1);
	while ((body = strtok(all_body, delim2)))
	{
		all_body = NULL;
		printf("Body param: \"");
		for (; *body != '='; body++)
			putchar(*body);
		printf("\" -> \"");
		body++;
		for (; *body; body++)
			putchar(*body);
		putchar(0x22);
		putchar(0xA);
	}
	return (http_response(200, NULL));
}