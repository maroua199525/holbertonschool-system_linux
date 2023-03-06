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
	return (start_server(9));
}

/**
 * validate_method - Validate the method
 * @method: Method to validate
 *
 * Return: Status code
 */
int validate_method(char *method)
{
	if (!strncmp(method, "GET", 3))
		return (200);
	if (!strncmp(method, "POST", 4))
		return (201);
	if (!strncmp(method, "DELETE", 6))
		return (204);
	return (404);
}

/**
 * content - Save data in body(JSON)
 * @response: Status code
 * @ram_json: JSON representation
 * @query1: Query value1 string
 * @query2: Query value2 string
 * @id: Id of the JSON object
 * @path: Path with query string
 *
 * Return: Pointer to JSON object or list of JSON objects
*/
char *content(int *response, char ram_json[MAX_SIZE][MAX_SIZE], char *query1,
	      char *query2, int *id, char *path)
{
	char *body = NULL;
	int i = 0, len = 0, find = 0;

	if (*response == 200)
	{
		body = malloc(sizeof(char) * BUFSIZ);
		if (body == NULL)
			return (fprintf(stderr, "Can not malloc\n"), NULL);
		if (*path)
		{
			find = atoi(&path[4]);
			if (strncmp(path, "?id=", 3) || find < 0 || find > *id)
				return (*response = 404, NULL);
			strcpy(body, ram_json[find]);
		}
		else
		{
			body[0] = '[';
			for (i = 0; i < *id; i++)
			{
				strcpy(&body[1 + len], ram_json[i]);
				len += strlen(ram_json[i]) + 1;
				body[len] = ',';
			}
			body[(len ? len : 1)] = ']';
			body[(len ? len : 1) + 1] = 0;
		}
	}
	else if (*response == 201)
	{
		body = malloc(sizeof(char) * MAX_SIZE);
		sprintf(ram_json[*id], "{\"id\":%d,\"title\":\"%s\",\"description\":\"%s\"}",
			(*id), &query1[6], &query2[12]);
		strcpy(body, ram_json[*id]);
		(*id)++;
	}
	return (body);
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
	char *delim = " \r\t\n", *delim2 = "&", *body;
	static char ram_json[MAX_SIZE][MAX_SIZE];
	static int id;
	int i = 12, response = 404;

	method = strtok(buf, delim);
	response = validate_method(method);
	path = strtok(NULL, delim);
	if (strncmp(path, "/todos", 6))
		response = 404;
	if (response == 201)
	{
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
	}
	if (id == 0)
		memset(ram_json[0], 0, MAX_SIZE);
	body = content(&response, ram_json, query1, query2, &id, &path[6]);
	path[6] = '\0';
	printf("%s %s -> %d %s\n", method, path, response, get_response(response));
	return (http_response(response, body));
}