#include "socket.h"

/**
 * main - program tha build a socket listening
 * Return: if successful return EXIT_SUCCESS otherwise EXIT_FAILURE
 */

int main(void)
{
	return (setup_socket());
}

/**
 * parse_request - parse a request and get option values
 * @clientId: client identifier
 * @buf: request buffer
 * Return: if successful return EXIT_SUCCESS otherwise EXIT_FAILURE
 */
int parse_request(int clientId, char *buf)
{
	char *delim = " \t\r\n";
	char *method, *path, *version;

	method = strtok(buf, delim);
	path = strtok(NULL, delim);
	version = strtok(NULL, delim);

	printf("Method: %s\nPath: %s\nVersion: %s\n", method, path, version);
	return (send_response(clientId, RESPONSE_200));
}