/*
	Scarlett Jones
	CSCE 3530
	9/28/2016
	Program 1
	Client requesting website
	Usage: client <port_number>
							url: <url>
*/

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
int main(int argc,char *argv[])
{
	system("clear");
	
	/* check the command line input */
	if(argc == 1)
	{
		printf("\nUsage: pserver <port_number>\n\n");
		exit(1);
	}
	else if(argc > 2)
	{
		printf("\nUsage: pserver <port_number>\n\n");
		exit(1);
	}
	else
	{
		//correct format, can continue on
	}	
	
    int sockfd, n;
    int len = sizeof(struct sockaddr);
	char webaddress[100];
    char recvline[50960];
    struct sockaddr_in servaddr;

	bzero(recvline, 50960);
	bzero(webaddress, 100);
	
    /* AF_INET - IPv4 IP , Type of socket, protocol*/
    sockfd=socket(AF_INET, SOCK_STREAM, 0);
    bzero(&servaddr,sizeof(servaddr));
 
    servaddr.sin_family=AF_INET;
    servaddr.sin_port=htons(atoi(argv[1])); // Server port number, enter by command line argument
 
    /* Convert IPv4 and IPv6 addresses from text to binary form */
	inet_pton(AF_INET,"129.120.151.94",&(servaddr.sin_addr)); // cse01 server's ip address
 
    /* Connect to the server */
    connect(sockfd,(struct sockaddr *)&servaddr,sizeof(servaddr));
 
	printf("url: ");
	scanf("%s", webaddress);
	
	write(sockfd, webaddress, strlen(webaddress)); //write to the server
		
	FILE *fp;
	fp = fopen("openme.html", "w");
		
	read(sockfd, recvline, sizeof(recvline));
	fprintf(fp, "%s\n", recvline);
	printf("\nTo view file, open openme.html\n");

    fclose(fp);
 
	return 0;
}