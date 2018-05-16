/*
	Scarlett Jones
	CSCE 3530
	10/26/2016
	Program 2
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
	char listbuff[50960];
	char input[200];
    int listen_fd, conn_fd, n;
     struct sockaddr_in servaddr;
	 
	bzero(str, 50960);
	bzero(webaddress, 100);
	bzero(buffer, 50960);
	bzero(listbuff, 50960);
	bzero(input, 200);
 
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
	  
	  //Check the webaddress to see if it is on the blacklist
	  //if it is on blacklist, then write to client a message denying request
	  //then quit(0) to end program
	  
	  //otherwise continue on
	  
	  //do a HEADrequest to see if file has been updated recently
	  //compare date with one on list.txt
	  //update the file OR use the file already made
	
		system("echo HEAD / HTTP/1.1 > HEADrequest"); //put head request into file called HEADrequest
		strcpy(input, "echo Host: "); //append host to file
		strncat(input, webaddress, strlen(webaddress)); //append address to file
		strcat(input, " >> HEADrequest"); //concat the full request with append to file
		system(input); //call the input to make a file
		system("echo >>HEADrequest"); //add newline
		system("more HEADrequest"); //print out the head request
	
	
		system("echo GET / HTTP/1.1 > GETrequest"); //put get request into file called GETrequest
		strcpy(input, "echo Host: "); //append host to file
		strncat(input, webaddress, strlen(webaddress)); //append address to file
		strcat(input, " >> GETrequest"); //concat the full request with append to file
		system(input); //call the input to make a file
		system("echo >>GETrequest"); //add newline
		system("more GETrequest"); //print out the get request
	
	  
		  //netcat to web address
		  printf("\nWeb address: %s\n", webaddress);
		  strcpy(input, "cat GETrequest | nc ");
		  strncat(input, webaddress, strlen(webaddress));
		  
		  FILE *pFP;
		  pFP = popen("date +%Y%m%d%H%M%S", "r");
		  char filename[14]; // the length is 15, but goes 0 to 14. has a null character
		  bzero(filename, 14);
		  char temp[14];
		  bzero(temp, 14);
		  while(fgets(filename, sizeof(filename), pFP) != NULL)
		  {
				sprintf(temp + strlen(temp), "%s", filename);
		  }
		  strcpy(filename, temp);
//		  printf("%s\n", filename);
		  //  filename = system("echo `date +%Y%m%d%H%M%S`");
		  strcat(input, " 80 > "); 
		  strcat(input, filename);
		  
		//  FILE *listFPa;
		  FILE *listFPb;
		//  listFPa = fopen("list.txt", "r"); //read mode
		  listFPb = fopen("list.txt", "a"); //append mode

		  //while(fgets(listbuff, sizeof(listbuff), listFPa))
		//  {
			  fprintf(listFPb, "%s %s\n", webaddress, filename); //write the webaddress and filename just created
		//  }
		  
		//  printf("%s\n", input);
		  //  cat GETrequest | nc [website] 80 > `date +%Y%m%d%H%M%S`
		  system(input);
		
/*		  FILE *listFPa;
		  FILE *listFPb;
		  listFPa = fopen("list.txt", "r"); //read mode
		  listFPb = fopen("list.txt", "a"); //append mode

		  while(fgets(listbuff, sizeof(listbuff), listFPa))
		  {
			  fprintf(listFPb, "%s %s\n", webaddress, filename); //write the webaddress and filename just created
		  }*/

//		 fprintf(listFP, "%s %s\n", webaddress, filename); //write the webaddress and filename just created

	
	
		  //printf("\nTo view file, open output.html\n"); 
		
		  bzero(str, 50960);
		  bzero(buffer, 50960);
		  FILE *fp;

		  //open list.txt to read it
		  FILE *list2FP;
		  list2FP = fopen("list.txt", "r"); //read mode
		  //look for webaddress and then get the filename associated with it
		
		  //set filename to the one needed
		 // strcpy(filename, );
		  //open that filename
		//  printf("Opening %s\n", filename);
		  fp = fopen(filename, "r"); //have to open the file that corresponds to the one on list.txt
		//  printf("file opened\n");
		
		int len=0;
		
		printf("before while\n");
		while(fgets(str, sizeof(str), fp) != NULL)
		{
			printf("%d\n", len);
			if(!strcmp(str, "0")) //if the strings are equal
			{
				break;
			}

			len += sprintf(buffer + strlen(buffer), "%s", str);
		}
		printf("after while\n");

		system("rm GETrequest");
		system("rm HEADrequest");
		
		fclose(fp);
	//	fclose(listFPa);
		fclose(listFPb);
		fclose(pFP);
		fclose(list2FP);
printf("line 185\n");
      write(conn_fd, buffer, strlen(buffer)); // write to the client
      close (conn_fd); //close the connection
    }

	return 0;
}