/*
Name: Scarlett Jones
Course: CSCE 3600: Systems Programming
Due Date: Tuesday, April 12, 2016 at midnight
Description: client side - sends the server requests to buy or return tickets. Gets 15 requests.
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h> 
#include <time.h> //for true randomness
#define R_MAX 99999 //maximum random 5 digit number
#define R_MIN 10000 //minimum random 5 digit number 

void error(const char *msg);

int main(int argc, char *argv[])
{
	int tickets[15]; //tickets the client has bought
	int sockfd, portno, n, request; //the socket to use, the port number, return value of write&read to check errors, random number between 0&4 in switch statement
	int i, j, length, temp; //iterator, iterator, length of sprintf, random number to try to return
	struct sockaddr_in serv_addr; //socket address for server
	struct hostent *server; //
	char buffer[256]; //things to be sent and recieved in socket
	char rticket[5]; //the character array version of the ticket to write to socket
	time_t t; //make time variable
	srand((unsigned)time(&t)); //generate random seed with time

	bzero(buffer, 256); //initialize buffer to all zeros
	
	if (argc < 3) //error checking for the correct amount of command line arguments
	{
		fprintf(stderr,"usage %s hostname port\n", argv[0]);
		exit(0);
	}

	for(i=0; i<15; i++) //initialize tickets owned array to all zeros, start with none
	{
		tickets[i] = 0;
	}
	
	portno = atoi(argv[2]); //convert the command line argument of the port number to an int
	sockfd = socket(AF_INET, SOCK_STREAM, 0); //set the socket file descriptor

	if (sockfd < 0) //error checking for opening socket
	{
		error("ERROR opening socket");
	}

	server = gethostbyname(argv[1]); //convert the command line argument of the cse machine to the correct host name ip address

	if (server == NULL) //error checking for wrong host entered
	{
		fprintf(stderr,"ERROR, no such host\n");
		exit(0);
	}
	
	bzero((char *) &serv_addr, sizeof(serv_addr)); //server address initizlied to zeros
	serv_addr.sin_family = AF_INET; //server address is using INET
	bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length); //copy 
	serv_addr.sin_port = htons(portno); //set server port number to correct format

	if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) //error checking for connecting to the socket
	{
		error("ERROR connecting");
	}
	

	for(i=0; i<15; i++) //client gets to make 15 requests
	{	
			bzero(buffer,256); //make sure buffer is all zeros
			request = rand()%5; //make a random request between 0 and 4
			switch(request)//20% return, 80% buy over time
			{
				case 0: //return
						bzero(buffer, 256);//make sure buffer is all zeros
						strcpy(buffer, "RETURN "); //put RETURN into buffer
						for(j=14; j>=0; j--)//try to return last ticket bought
						{
							if(tickets[j] != 0)//first ticket that's not zero will be returned
							{
								length = sprintf(rticket, "%d", tickets[j]);//convert int ticket number to a char[5]
								strcat(buffer, rticket); //add the ticket number to the buffer
								tickets[j] = 0; //just returned this ticket, no longer in the tickets owned array
								break;//leave this for loop now because we have what we need
							}
							else if(j == 0)//if you make it to here, there aren't any tickets bought
							{
								temp = (rand()%(R_MAX - R_MIN)+ R_MIN);//just make up a random ticket number to return
								sprintf(rticket, "%d", temp);//convert this int into a char[5]
								strcat(buffer, rticket);//add the ticket number to the buffer
							}
						}
				
						printf("[Client]: %s\n", buffer); //print out the message that the client wants to return a certain ticket number
						n = write(sockfd,buffer,strlen(buffer));//write what the client wants to do to the socket
						if (n < 0) //error checking for writing to socket
						{
							error("ERROR writing to socket");
						}
						
						bzero(buffer,256);//reset buffer to zero
						n = read(sockfd,buffer,255);//read from the socket to see what the message back from the server is
						if (n < 0) //error checking for reading from socket
						{
							error("ERROR reading from socket");
						}						
						
						if(strncmp(buffer, "Ticket not exist", 16) == 0) //server said the ticket doesn't exist
						{
							printf("[Server]: %s\n", buffer);//print out the server's message
						}
						else //ticket found in server
						{
							printf("[Server]: RETURN %s\n", rticket); //print out ticket returned
							printf("[Client]: %s\n", buffer); //print out server's message
						}
						
						bzero(buffer, 256);//make sure buffer is all zeros
				break;
				case 1: //buy (1 to 4 with no break until after everthing in 4)
				case 2:
				case 3:
				case 4:
						printf("[Client]: BUY\n");//print that the client wants to buy
						n = write(sockfd,"BUY",3);//write to socket that client wants to buy
						if (n < 0) //error checking for writing to socket
						{
							error("ERROR writing to socket");
						}
						
						bzero(buffer,256);//reset buffer to zeros
						n = read(sockfd,buffer,255);//read message back from server on the socket
						if (n < 0) //error checking for reading from socket
						{
							error("ERROR reading from socket");
						}

						if(strncmp(buffer, "Database full", 13) != 0)//if there are tickets left to buy
						{
							printf("[Server]: %d\n",atoi(buffer));//conver the ticket to buy into an int, print it out
							for(j=0; j<15; j++)//go through the clients array of tickets owned
							{
								if(tickets[j] == 0)//if there is not a ticket there
								{
									tickets[j] = atoi(buffer);//then put the new ticket just bought there as an int
									j=15;//get out of the loop
									break;//leave loop now
								}
							}
						}
						else //if the database is full
						{
							printf("[Server]: %s\n",buffer);//print out the server's message
							printf("[Client]: Buy failed\n");//print out from client that the buy failed					
							//tickets[i] = 0;//the ticket here should just stay zero? do i even need this?
						}
						bzero(buffer, 256);//reset buffer to zeros
				break;
				default: //shouldn't get here
				break;
			}		
	}
	
	for(i=0; i<15; i++) //loop through tickets owned
	{
		printf("[%d] %d\n", i, tickets[i]); //print out all the tickets the client owns
	}
	
	close(sockfd);	//close the socket
	
	
	return 0;
}

void error(const char *msg)//just print out the error message that comes up
{
    perror(msg);
    exit(0);
}