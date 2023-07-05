#include "socket.h"
/**
 * setup_socket - run the server
 * Return: if successful return EXIT_SUCCESS otherwise EXIT_FAILURE
 */

int setup_socket(void)
{
	struct sockaddr_in addrport;
	int socketid;

	socketid = socket(AF_INET, SOCK_STREAM, 0);
	if (socketid < 0)
	{
		perror("socket failed");
		return (EXIT_FAILURE);
	}
	addrport.sin_family = AF_INET;
	addrport.sin_port = htons(PORT);
	addrport.sin_addr.s_addr = htonl(INADDR_ANY);
	if (bind(socketid, (struct sockaddr *)&addrport, sizeof(addrport)) < 0)
	{
		perror("bind failed");
		return (EXIT_FAILURE);
	}
	if (listen(socketid, 10) < 0)
	{
		perror("listen failed");
		return (EXIT_FAILURE);
	}
	printf("Server listening on port 12345\n");
	while (1)
	{
		recive_messages(socketid);
	}

	close(socketid);
	return (EXIT_SUCCESS);
}
/**
 * recive_messages- function to receive a message from the client
 * @socketId: the socket identifier of the server
 * Return: if successful return EXIT_SUCCESS otherwise EXIT_FAILURE
 */
int recive_messages(int socketId)
{
	struct sockaddr_in client;
	int clientId;
	socklen_t client_size = sizeof(client);
	char buff[buffSize + 1];
	ssize_t bytes_read;

	clientId = accept(socketId, (struct sockaddr *)&client, &client_size);
	if (clientId < 0)
	{
		perror("accept failed");
		return (EXIT_FAILURE);
	}

	inet_ntop(AF_INET, &client.sin_addr, buff, INET_ADDRSTRLEN);
	printf("Client connected: %s\n", buff);

	bytes_read = recv(clientId, buff, buffSize, 0);
	if (bytes_read > 0)
	{
		buff[bytes_read] = 0;
		printf("Raw request: \"%s\"\n", buff);
		parse_request(clientId, buff);
	}
	close(clientId);
	return (EXIT_SUCCESS);
}

/**
 * send_response - sends response back to client
 * @clientId: client socket descriptor
 * @response: the response message
 * Return: 0 on success else 1
 */
int send_response(int clientId, char *response)
{
	send(clientId, response, strlen(response), 0);
	return (0);
}