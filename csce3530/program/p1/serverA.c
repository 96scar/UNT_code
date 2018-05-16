/*
	Scarlett Jones
	CSCE 3530
	9/28/2016
	Program 1
	Proxy server requesting website for client from webserver
	Usage: pserver <port_number>
*/

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
 
int main(int argc, char *argv[])
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
 
    char str[50960];
	char webaddress[100];
	char buffer[50960];
	char input[200];
    int listen_fd, conn_fd, n;
     struct sockaddr_in servaddr;
 
    /* AF_INET - IPv4 IP , Type of socket, protocol*/
    listen_fd = socket(AF_INET, SOCK_STREAM, 0);
 
    bzero(&servaddr, sizeof(servaddr));
 
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htons(INADDR_ANY);
    servaddr.sin_port = htons(atoi(argv[1])); //port number needs to be entered by command line argument
 
    /* Binds the above details to the socket */
	bind(listen_fd,  (struct sockaddr *) &servaddr, sizeof(servaddr));
	/* Start listening to incoming connections */
	listen(listen_fd, 10);

    while(1)
    {
      /* Accepts an incoming connection */
	  conn_fd = accept(listen_fd, (struct sockaddr*)NULL, NULL);
	  bzero(webaddress, 100);
	  n = read(conn_fd, webaddress, sizeof(webaddress));
	
	system("echo GET / HTTP/1.1 > request"); //put get request into file called request
	strcpy(input, "echo Host: "); //append host to file
	strncat(input, webaddress, strlen(webaddress)); //append address to file
	strcat(input, " >> request"); //concat the full request with append to file
	system(input); //call the input to make a file
	system("echo >>request"); //add newline
	system("more request"); //print out the get request
	
	  
	  //netcat to web address
	  printf("\nWeb address: %s\n", webaddress);
	  strcpy(input, "cat request | nc ");
	  strncat(input, webaddress, strlen(webaddress));
	  strcat(input, " 80 > output.html");
	//  cat request | nc [website] 80 > output.html
	system(input);
	
	printf("\nTo view file, open output.html\n");
		
		bzero(str, 50960);
		bzero(buffer, 50960);
		FILE *fp;

		int len=0;

    	fp = fopen("output.html", "r");
		
		while(fgets(str, sizeof(str), fp) != NULL)
		{
			if(!strcmp(str, "0")) //if the strings are equal
			{
				break;
			}

			len += sprintf(buffer + strlen(buffer), "%s", str);
		}

		fclose(fp);

      write(conn_fd, buffer, strlen(buffer)); // write to the client
      close (conn_fd); //close the connection
    }

	return 0;
}