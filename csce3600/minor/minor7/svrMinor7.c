/*
Name: Scarlett Jones
Course: CSCE 3600: Systems Programming
Due Date: Tuesday, April 12, 2016 at midnight
Description: server side - handles 2 different client requests from sockets. Accepts 30 requests.
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include <time.h>//randomness based on time
#define N 20 //number of tickets to be generated
#define R_MAX 99999 //maximum random 5 digit number
#define R_MIN 10000 //minimum random 5 digit number 

void error(const char *msg);

int main(int argc, char *argv[])
{
	int tickets[N], bought[N]; //randomly generated 5digit tickets, 0/1 -> false/true for bought
	char output[5]; //char version of current ticket
	int i, j, fill=0, length; //iterator, iterator, the amount of tickets bought so far, the length of the output[5] version of ticket
	time_t t;//time variable
	int sockfd, newsockfd, newsockfd2, portno;//main socket, first socket, 2nd socket, port number
	socklen_t clilen; //client len
	char buffer[256]; //buffer used to read and write from sockets
	struct sockaddr_in serv_addr, cli_addr; //server address, client address
	int n, nready; //gets return value of read and write to error check, tells whether ready to go after select polling
	int maxfd; //maximum amount of file descriptors
	fd_set fds; //set the file descriptors
	
	if (argc < 2)//error checking to see if the correct amount of command line arguments were input
	{
		fprintf(stderr,"ERROR, no port provided\n");
		exit(1);
	}
	
	bzero(buffer, 256);//initialize buffer to zeros
	
	sockfd = socket(AF_INET, SOCK_STREAM, 0); //original socket gets initizlied, using INET and TCP
	if (sockfd < 0) //error checking for opening socket
	{
		error("ERROR opening socket");
	}
	
	for(i=0; i<N; i++) //initialize both the tickets and bought arrays to all zeros
	{
		tickets[i] = 0;
		bought[i] = 0;
	}

	srand((unsigned)time(&t)); //generate the random seed based on time

	for(i=0; i<N; i++) //initialize tickets array to randomly generated numbers in a range min to max
	{
		tickets[i] = (rand()%(R_MAX - R_MIN)+ R_MIN); //randomly generated
	}

	bzero((char *) &serv_addr, sizeof(serv_addr));//server address initialized to zero
	portno = atoi(argv[1]); //convert the port number given as a string to an int
	serv_addr.sin_family = AF_INET; //the server address is INET
	serv_addr.sin_addr.s_addr = INADDR_ANY; //the server address is accepting any INET address
	serv_addr.sin_port = htons(portno); //the port number is converted to correct format

	if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) //error checking for binding the socket
	{
		error("ERROR on binding");
	}

	listen(sockfd,5); //the server has a backlog of 5 clients it could listen to 
	clilen = sizeof(cli_addr); //the length of the client address
	if((newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen)) < 0)//error checking for accepting a socket connection from 1st client
	{
		error("ERROR on accept");		
	}

	if ((newsockfd2 = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen)) < 0) //error checking for accepting a socket connection from 2nd client
	{
		error("ERROR on accept");
	}
	
	maxfd = (newsockfd > newsockfd2 ? newsockfd : newsockfd2) + 1;//set the max number file descriptors

	for(i=0; i<30; )//for loop doesn't increment here because it has to do it where something actually happens
	{	
		FD_ZERO(&fds); //set up polling
		FD_SET(newsockfd, &fds); //set up polling
		FD_SET(newsockfd2, &fds); //set up polling
		
		nready = select(maxfd, &fds, (fd_set *) 0, (fd_set *) 0, (struct timeval *) 0); //use select to have to wait to start
		
		if(FD_ISSET(newsockfd, &fds))//inside 1st client
		{
			bzero(buffer,256); //set buffer to zeros
			n = read(newsockfd,buffer,255);//read from socket to see what request is made
			if (n < 0)//error checking for reading from socket
			{
				error("ERROR reading from socket");
			}	
			if((strncmp(buffer, "BUY", 3)) == 0) //compare first 3 characters of buffer to see if it's BUY
			{
				printf("[Client 1]: %s\n", buffer); //print that client wants to buy
				
				for(j=0; j<N; j++)//go through tickets array
				{
					if(fill == N) //check to see if we have given away all tickets
					{
						printf("[Sever X]: Database full\n"); //message to self
						n = write(newsockfd, "Database full", 13); //message to client
						j=N;//get out of loop
						break;//leave loop
					}
					
					if(bought[j] == 0) //if the current ticket at hasn't been bought yet
					{
						printf("[Server X]: Client 1 buy %d\n", tickets[j]); //print to self what you're going to do

						length = sprintf(output, "%d", tickets[j]); //convert the current ticket to a char[5]

						n = write(newsockfd, output, length);//write to the client socket the ticket they are buying
						bought[j] = 1; //this ticket is now bought
						fill++; //another ticket has been bought
						j=N; //get out of loop
						break;//leave loop
					}
				}
				
				if (n < 0)//error checking for writing to socket
				{
					error("ERROR writing to socket");
				}
				i++; //increment i because we have just bought something, or tried to
			}
			else if((strncmp(buffer, "RETURN", 6)) == 0) //compare 1st 6 characters to see if client wants to RETURN
			{
				for(j=0; j<N; j++) //go through tickets array to see if ticket exists
				{
					sprintf(output, "%d", tickets[j]); //convert ticket to char[5]
					if((strncmp(buffer+7, output, 11)) == 0)//compare from 7 to 11 of buffer to see if the return ticket matches any existing tickets
					{
						bought[j] = 0; //now this ticket is returned, no longer bought
						fill--; //we just got a ticket back
						
						printf("[Client 1]: %s\n", buffer); //print to self what ticket was returned
						printf("[Server X]: Client 1 cancel %d\n", tickets[j]);//print to self what the client just canceled

						strcpy(buffer, "Ticket "); //put Ticket in the buffer
						strcat(buffer, output); //concatenate the ticket number to the buffer
						strcat(buffer, " returned"); //concatenate returned to the buffer
						n = write(newsockfd, buffer, strlen(buffer)); //write to the client socket the buffer message of what was returned
						if (n < 0) //error checking for writing to the socket
						{
							error("ERROR writing to socket");
						}
						i++; //increment i because we just returned a ticket					
						
						break; //get out of loop
					}
					else if(j == N-1) //if we get here, the ticket doesn't exist
					{
						printf("[Client 1]: %s\n", buffer); //message to self of what the client wanted to do
						printf("[Server X]: Client 1 cancel failed\n"); //message to self that the cancel failed
						n = write(newsockfd, "Ticket not exist", 16); //write to client socket that the ticket doesn't exist
						if (n < 0)//error checking for writing to socket
						{
							error("ERROR writing to socket");
						}
						i++; //increment i because we tried to return a ticket
					}
				}
			}
			else//shouldn't get here, but it would happen if something other than BUY or RETURN was writen to socket
			{
				;
			}	
			bzero(buffer, 256); //make sure buffer is zeros
		}
		
		if(FD_ISSET(newsockfd2, &fds)) //in the 2nd client
		{
			bzero(buffer,256); //buffer is zeros now
			n = read(newsockfd2,buffer,255);//read from socket to see what request is made
			if (n < 0)//error checking for reading from socket
			{
				error("ERROR reading from socket");
			}
			if((strncmp(buffer, "BUY", 3)) == 0)//compare first 3 characters of buffer to see if it's BUY
			{
				printf("[Client 2]: %s\n", buffer);//print that client wants to buy
				
				for(j=0; j<N; j++)//go through tickets array
				{				
					if(fill == N)//check to see if we have given away all tickets
					{
						printf("[Server X]: Database full\n");//message to self
						n = write(newsockfd2, "Database full", 13);//message to client
						j=N;//get out of loop
						break;//leave loop
					}
					
					if(bought[j] == 0)//if the current ticket at hasn't been bought yet
					{
						printf("[Server X]: Client 2 buy %d\n", tickets[j]);//print to self what you're going to do
						length = sprintf(output, "%d", tickets[j]);//convert the current ticket to a char[5]

						n = write(newsockfd2, output, length);//write to the client socket the ticket they are buying

						bought[j] = 1;//this ticket is now bought
						fill++;//another ticket has been bought
						j=N;//get out of loop
						break;//leave loop
					}
				}
				
				if (n < 0)//error checking for writing to socket
				{
					error("ERROR writing to socket");
				}
				i++;//increment i because we have just bought something, or tried to
			}
			else if((strncmp(buffer, "RETURN", 6)) == 0)//compare 1st 6 characters to see if client wants to RETURN
			{
				for(j=0; j<N; j++)//go through tickets array to see if ticket exists
				{
					sprintf(output, "%d", tickets[j]); //convert ticket to char[5]
					if((strncmp(buffer+7, output, 11)) == 0)//compare from 7 to 11 of buffer to see if the return ticket matches any existing tickets
					{
						bought[j] = 0;//now this ticket is returned, no longer bought
						fill--;//we just got a ticket back
						
						printf("[Client 2]: %s\n", buffer);//print to self what ticket was returned
						printf("[Server X]: Client 2 cancel %d\n", tickets[j]);//print to self what the client just canceled

						strcpy(buffer, "Ticket ");//put Ticket in the buffer
						strcat(buffer, output);//concatenate the ticket number to the buffer
						strcat(buffer, " returned");//concatenate returned to the buffer
						n = write(newsockfd2, buffer, strlen(buffer));//write to the client socket the buffer message of what was returned
						if (n < 0)//error checking for writing to the socket
						{
							error("ERROR writing to socket");
						}
						i++;//increment i because we just returned a ticket						
						break;//get out of loop
					}
					else if(j == N-1)//if we get here, the ticket doesn't exist
					{
						printf("[Client 2]: %s\n", buffer);//message to self of what the client wanted to do
						printf("[Server X]: Client 2 cancel failed\n");//message to self that the cancel failed
						n = write(newsockfd2, "Ticket not exist", 16);//write to client socket that the ticket doesn't exist
						if (n < 0)//error checking for writing to socket
						{
							error("ERROR writing to socket");
						}
						i++;//increment i because we tried to return a ticket
					}
				}					
			}
			else//shouldn't get here, but it would happen if something other than BUY or RETURN was writen to socket
			{
				;
			}
			bzero(buffer, 256); //make sure buffer is clear
		}
	}

	close(newsockfd); //close the client 1 socket
	close(newsockfd2); //close client 2 socket
	close(sockfd); //close the original socket
	
	return 0;
}

void error(const char *msg)//just print out the error message that comes up
{
    perror(msg);
    exit(1);
}