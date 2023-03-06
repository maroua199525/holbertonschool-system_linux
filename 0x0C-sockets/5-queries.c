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
	return (start_server(5));
}

/**
 * response - Print and send HTTP response
 * @buf: buffer to split and print
 *
 * Return: Always EXIT_SUCCESS
 */
int response(char *buf)
{
	char *allpath, *path, *queries;
	char *delim1 = " \r\t\n";
	char *delim2 = "&?";

	strtok(buf, delim1);
	allpath = strtok(NULL, delim1);
	path = strtok(allpath, delim2);
	printf("Path: %s\n", path);
	while ((queries = strtok(NULL, delim2)))
	{
		printf("Query: \"");
		for (; *queries != '='; queries++)
			putchar(*queries);
		printf("\" -> \"");
		queries++;
		for (; *queries; queries++)
			putchar(*queries);
		putchar(0x22);
		putchar(0xA);
	}
	return (http_response(200, NULL));
}