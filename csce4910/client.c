#include "Communications.h"

int main()
{		
	int sockfd = ConnectToServer("cse01", 2048);

	char * data = "Some data from the client in C to the server in Python";
	int n = SendString(data, sockfd); //Send data to the server
	if(n < 0)
		error("error writing to socket");
	else
		printf("Sent: %s\n", data);
	
	close(sockfd);
	
	return 0;
}