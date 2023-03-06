#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>

/**
 * die_with_error - Print message to stderr and exit
 * @str:    String to print
 * @sockid: Socket descriptor to close
 *
 * Returns: Nothing
 */
void die_with_error(char *str, int sockid)
{
	fprintf(stderr, "%s\n", str);
	if (close(sockid) == -1)
		fprintf(stderr, "close error\n");
	exit(EXIT_FAILURE);
}

/**
 * create_socket - Create a socket
 *
 * Return: A new socket
 */
int create_socket(void)
{
	int sockid;

	sockid = socket(PF_INET, SOCK_STREAM, 0);
	if (sockid == -1)
	{
		fprintf(stderr, "socket error\n");
		return (-1);
	}
	return (sockid);
}

/**
 * assgin_address_to_socket - Associates and reserves a port for use
 * by the Socket
 * @sockid: Socket descriptor
 * @port:   The port number to connect
 *
 * Return: A pointer to address port
 */
struct sockaddr_in assgin_address_to_socket(int sockid, int port)
{
	struct sockaddr_in addrport;

	addrport.sin_family = AF_INET;
	addrport.sin_port = htons(port);
	addrport.sin_addr.s_addr = htonl(INADDR_ANY);
	if (bind(sockid, (struct sockaddr *)&addrport, sizeof(addrport)) == -1)
		die_with_error("bind error", sockid);
	return (addrport);
}

/**
 * main - Opens an IPv4/TCP socket, and listens to traffic on port 12345.
 *
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure
 */
int main(void)
{
	int sockid;
	int port = 12345;

	sockid = create_socket();
	if (sockid == -1)
		exit(EXIT_FAILURE);
	assgin_address_to_socket(sockid, port);
	printf("Server listening %d\n", port);
	if (listen(sockid, 0) == -1)
		die_with_error("listen error", sockid);
	while (1)
	{}
	return (EXIT_SUCCESS);
}