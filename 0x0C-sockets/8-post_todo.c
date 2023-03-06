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
	return (start_server(8));
}

/**
 * response - Print and send HTTP response
 * @buf: buffer to split and print
 *
 * Return: Always EXIT_SUCCESS
 */
int response(char *buf)
{
	char *method, *path, *content_lenght, *queries, *query1, *query2;
	char *delim = " \r\t\n", *delim2 = "&", *body = NULL;
	static char ram_json[MAX_SIZE][MAX_SIZE];
	static int id;
	int i = 12, response = 201;

	method = strtok(buf, delim);
	if (strcmp(method, "POST"))
		response = 404;
	path = strtok(NULL, delim);
	if (strcmp(path, "/todos"))
		response = 404;
	printf("%s ", method);
	printf("%s -> ", path);
	for (i = 7; i; i--)
		strtok(NULL, delim);
	content_lenght = strtok(NULL, delim);
	if (!content_lenght || strcmp(content_lenght, "Content-Length:"))
		response = 404;
	for (i = 3; i; i--)
		strtok(NULL, delim);
	queries = strtok(NULL, delim);
	query1 = strtok(queries, delim2);
	if (response == 201 && (!query1 || strncmp(query1, "title", 5)))
		response = 422;
	query2 = strtok(NULL, delim2);
	if (response == 201 && (!query2 || strncmp(query2, "description", 11)))
		response = 422;
	printf("%d %s\n", response, get_response(response));
	if (response == 201)
	{
		sprintf(ram_json[id], "{\"id\":%d,\"title\":\"%s\",\"description\":\"%s\"}",
		id, &query1[6], &query2[12]);
		body = malloc(sizeof(char) * MAX_SIZE);
		strcpy(body, ram_json[id]);
		id++;
	}
	return (http_response(response, body));
}