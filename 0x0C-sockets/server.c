#include "socket.h"

static int server_fd;
static int client_fd;

/**
 * die_with_error - Print message to stderr and exit
 * @str:    String to print
 *
 * Returns: Nothing
 */
void die_with_error(const char *str)
{
	fprintf(stderr, "%s\n", str);
	if (client_fd != 0 && close(client_fd) == -1)
		fprintf(stderr, "close client error\n");
	if (server_fd != 0 && close(server_fd) == -1)
		fprintf(stderr, "close server error\n");
}

/**
 * start_server - Start the server and connect
 * @task: Task number to evaluate
 *
 * Return: EXIT_SUCCESS if successful otherwise EXIT_FAILURE
 */
int start_server(void)
{
	struct sockaddr_in server;
	int sd;

	setbuf(stdout, NULL);
	sd = socket(PF_INET, SOCK_STREAM, 0);
	if (sd < 0)
	{
		perror("socket failed");
		return (EXIT_FAILURE);
	}
	server.sin_family = AF_INET;
	server.sin_port = htons(PORT);
	server.sin_addr.s_addr = htonl(INADDR_ANY);
	if (bind(sd, (struct sockaddr *)&server, sizeof(server)) < 0)
	{
		perror("bind failure");
		return (EXIT_FAILURE);
	}
	if (listen(sd, SOMAXCONN) < 0)
	{
		perror("listen failure");
		return (EXIT_FAILURE);
	}
	printf("Server listening on port %d\n", ntohs(server.sin_port));
	while (1)
		accept_message(sd);
	close(sd);
}

/**
 * response_signal - Close client_fd and server_fd
 * @x: Unused number
 *
 * Return: Nothing
 */
void response_signal(int x)
{
	(void) x;

	if (server_fd != 0 && close(server_fd) == -1)
		fprintf(stderr, "close server error\n");
	server_fd = 0;
	if (client_fd != 0 && close(client_fd) == -1)
		fprintf(stderr, "close client error\n");
	client_fd = 0;
	putchar(0xA);
	exit(EXIT_FAILURE);
}

/**
 * accept_message - Accept a message from the server
 * @task: Task number to evaluate
 *
 * Return: EXIT_SUCCESS if successful otherwise EXIT_FAILURE
 */
int accept_message(int task)
{
	char *client_ip, buf[BUFSIZ] = {0};
	int rd;
	struct sockaddr_in ClientAddress;
	socklen_t adddrLen = sizeof(ClientAddress);

	client_fd = accept(server_fd, (struct sockaddr *)&ClientAddress, &adddrLen);
	if (client_fd == -1)
		return (die_with_error("accept error"), EXIT_FAILURE);
	client_ip = inet_ntoa(ClientAddress.sin_addr);
	if (client_ip == NULL)
		return (die_with_error("inet_ntoa error"), EXIT_FAILURE);
	if (task < 8)
		printf("Client connected: %s\n", client_ip);
	else
		printf("%s ", client_ip);
	rd = recv(client_fd, buf, BUFSIZ, 0);
	if (rd == -1)
		return (die_with_error("recv error"), EXIT_FAILURE);
	if (task < 8)
		printf("Raw request: \"%s\"\n", buf);
	return (response(buf));
}

/**
 * http_response - Validates the response and send it to the client
 * @status_code: Status code to evaluate
 * @body: Pointer to JSON object or list of JSON objects
 *
 * Return: EXIT_SUCCESS if successful otherwise EXIT_FAILURE
 */
int http_response(int status_code, char *body)
{
	char *cl = "Content-Length: ";
	char *ct = "Content-Type: application/json";
	int len = 10 + strlen(cl) + strlen(ct), len2 = 0;
	char *response = NULL;
	char *buf = NULL, flag = 1;

	response = get_response(status_code);
	if (body)
	{
		len2 = (strlen(response) + MAX_SIZE + len + 4);
		buf = calloc(len2, sizeof(char));
		if (buf == NULL)
			flag = 0;
		sprintf(buf, "HTTP/1.1 %d %s" CRLF "Content-Length: %lu"
		CRLF "Content-Type: application/json" CRLF CRLF "%s",
		status_code, response, strlen(body), body);
	}
	else
	{
		len2 = (strlen(response) + 18);
		buf = calloc(len2, sizeof(char));
		if (buf == NULL)
			flag = 0;
		sprintf(buf, "HTTP/1.1 %d %s" CRLF CRLF, status_code, response);
	}
	if (flag == 1)
	{
		send(client_fd, buf, strlen(buf), 0);
		free(buf);
	}
	else
		send(client_fd, "HTTP/1.1 500 Internal Server Error" CRLF CRLF, 43, 0);
	if (body)
		free(body);
	if (client_fd != 0 && close(client_fd) == -1)
		return (fprintf(stderr, "close client error\n"), EXIT_FAILURE);
	client_fd = 0;
	return (EXIT_SUCCESS);
}