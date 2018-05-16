#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <netdb.h>

int ConnectToServer(char * ip, int port)
{
	int sockfd, n;
	struct sockaddr_in server_addr;
	struct hostent *server;
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if(sockfd < 0)
		error("Error opening socket");
	server = gethostbyname(ip);
	if(server == NULL)
	{
		fprintf(stderr, "Error, host not found\n");
		exit(0);
	}
	bzero((char *) &server_addr, sizeof(server_addr));
	server_addr.sin_family = AF_INET;
	bcopy((char *)server->h_addr, (char *)&server_addr.sin_addr.s_addr, server->h_length);
	server_addr.sin_port = htons(port);
	if(connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) //Connect to the server
		error("Error connecting");	
		
	return sockfd;
}

int SendString(char * string, int sockfd)
{
	int n = write(sockfd, string, strlen(string));
	return n;
}