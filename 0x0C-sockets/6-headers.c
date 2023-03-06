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
	return (start_server(6));
}

/**
 * response - Print and send HTTP response
 * @buf: buffer to split and print
 *
 * Return: Always EXIT_SUCCESS
 */
int response(char *buf)
{
	char *user_agent, *user_agent2, *host, *host2, *accept, *accept2;
	char *delim1 = " \r\t\n";

	strtok(buf, delim1);
	strtok(NULL, delim1);
	strtok(NULL, delim1);
	host = strtok(NULL, delim1);
	host2 = strtok(NULL, delim1);
	host[strlen(host) - 1] = '\0';
	user_agent = strtok(NULL, delim1);
	user_agent2 = strtok(NULL, delim1);
	user_agent[strlen(user_agent) - 1] = '\0';
	accept = strtok(NULL, delim1);
	accept2 = strtok(NULL, delim1);
	accept[strlen(accept) - 1] = '\0';
	printf("Header: \"%s\" -> \"%s\"\n", user_agent, user_agent2);
	printf("Header: \"%s\" -> \"%s\"\n", host, host2);
	printf("Header: \"%s\" -> \"%s\"\n", accept, accept2);
	return (http_response(200, NULL));
}