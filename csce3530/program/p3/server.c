/*
Scarlett Jones
CSCE 3530
Program 3
Due 11/9/16 at midnight

Description:
Demonstrate the TCP 3-way handshake and closing a TCP connection using a client-server architechture.

Server side
Must run on cse01.cse.unt.edu machine
Accepts a single client's request on using sockets
*/

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
 
 
  //Modified the below struct that was given by Dr. Robin
struct tcp_hdr{
                unsigned short int src; //16 bit source port
                unsigned short int des; //16 bit destination port
                unsigned int seq; //32 bit sequence number
                unsigned int ack; //32 bit acknowledgment number
				//4 bit data offset of header length (in multiples of 32 bit)
				//6 bit reserved section
				//6 bit flags (unsigned short int combines the 3 fields above)
                unsigned short int hdr_flags; //the 3 fields above are in this variable
                unsigned short int rec; //16 bit receive window for flow control, set to zero
                unsigned short int cksum; //16 bit checksum, computed after the header and data is populated
                unsigned short int ptr; //16 bit urgent data pointer, set to zero
                unsigned int opt; //32 bit options, set to zero
              };
 
int main(int argc, char *argv[])
{
	system("clear");
	printf("\n\n\n\n\n");
	system("date");
	
	/* check the command line input */
	if(argc == 1)
	{
		printf("\npserver <port_number>\n\n");
		exit(1);
	}
	else if(argc > 2)
	{
		printf("\npserver <port_number>\n\n");
		exit(1);
	}
	else
	{
		//correct format, can continue on
	}
 
    char str[200];
	bzero(str, 200);
    int listen_fd, conn_fd, n;
     struct sockaddr_in servaddr;
 	struct tcp_hdr tcp_seg; //creates a variable to modify data in struct
	unsigned short int cksum_arr[12]; //will copy the struct to this array
	unsigned short int rec_arr[12]; //will copy the recieved string of tcp segment to this array	
	unsigned int i,sum=0, cksum; 
	time_t t;
	srand((unsigned) time(&t)); //initialize random number seed

	FILE *fp; //file pointer to open and write to server.out
	fp=fopen("server.out", "a");
 
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
		FILE *fp; //file pointer to open and write to server.out
		fp=fopen("server.out", "a");
      /* Accepts an incoming connection */
	  conn_fd = accept(listen_fd, (struct sockaddr*)NULL, NULL);

	  printf("\n\nONE\nServer receives client's connection request.\n");
	  fprintf(fp, "\n\nONE\nServer receives client's connection request.\n");
    n = read(conn_fd, str, sizeof(str));	  //read the client's request to connect
	
	char *token = strtok(str, " "); //tokenize by space	
	i=0;
	while(token)
	{
		rec_arr[i] = atoi(token);
		token = strtok(NULL, " ");
		i++;
	}
	
//	printf("recieved below: \n");
	for(i=0; i<12; i++)
	{
		printf("rec_arr[%d]: %d\n", i, rec_arr[i]);	
		fprintf(fp, "rec_arr[%d]: %d\n", i, rec_arr[i]);	
	}		

	printf("\n\nTWO\nServer sends connection granted response.\n");
	fprintf(fp, "\n\nTWO\nServer sends connection granted response.\n");
	bzero(str, 200);
	tcp_seg.src = atoi(argv[1]); //set the source port
	tcp_seg.des = atoi(argv[1]); //set the destination port
	tcp_seg.seq = rand()%100; //initial sequence number is random
	tcp_seg.ack = rec_arr[2] + 1; //initial ack number is intial client sequence number plus 1
	tcp_seg.hdr_flags = 0x5012; //data offset, reserved, URG, ACK, PSH, RST, SYN, FIN
	//above sets SYN & ACk bit to 1., 0101 0000 0001 0010 -> 0x5012
	tcp_seg.rec = 0; //receive window initially zero
	tcp_seg.cksum = 0;//checksum initially zero before calculated
	tcp_seg.ptr = 0;//urgent pointer
	tcp_seg.opt = 0;//options

	memcpy(cksum_arr, &tcp_seg, 24); //Copying 24 bytes	
	
	//compute the checksum
	  for (i=0;i<12;i++)               // Compute sum
	   sum = sum + cksum_arr[i];

	  cksum = sum >> 16;              // Fold once
	  sum = sum & 0x0000FFFF; 
	  sum = cksum + sum;

	  cksum = sum >> 16;             // Fold once more
	  sum = sum & 0x0000FFFF;
	  cksum = cksum + sum;

	  /* XOR the sum for checksum */
//	  printf("Checksum Value: 0x%04X\n", (0xFFFF^cksum));	
	  tcp_seg.cksum = 0xFFFF^cksum;  
	  
      bzero(str, 200);

	memcpy(cksum_arr, &tcp_seg, 24); //Copying 24 bytes	  	 

//	printf("sending the below: \n");
	for(i=0; i<12; i++)
	{
		printf("cksum_arr[%d]: %d\n", i, cksum_arr[i]);
		fprintf(fp, "cksum_arr[%d]: %d\n", i, cksum_arr[i]);
	}
	
	for(i=0; i<12; i++)
	{
		sprintf(str+strlen(str), "%hu ", cksum_arr[i]);
	}	  
	
      write(conn_fd, str, strlen(str)); // write to the client the ack 
	  
	  printf("\n\nTHREE\nServer recieves acknowledgment from client.\n");
	  fprintf(fp, "\n\nTHREE\nServer recieves acknowledgment from client.\n");
	  bzero(str, 200);
	  n=read(conn_fd, str, sizeof(str)); // read the client's response to ack
	  
	token = strtok(str, " "); //tokenize by space
	i=0;
	while(token)
	{
		rec_arr[i] = atoi(token);
		token = strtok(NULL, " ");
		i++;
	}
	
//	printf("recieved below: \n");
	for(i=0; i<12; i++)
	{
		printf("rec_arr[%d]: %d\n", i, rec_arr[i]);	
		fprintf(fp, "rec_arr[%d]: %d\n", i, rec_arr[i]);	
	}		  
	  
	
	//server reads the request from the client
	printf("\n\nFOUR\nServer receives client's close request.\n");
	fprintf(fp, "\n\nFOUR\nServer receives client's close request.\n");
    n = read(conn_fd, str, sizeof(str));	  //read the client's request to connect
	
	token = strtok(str, " "); //tokenize by space
	i=0;
	while(token)
	{
		rec_arr[i] = atoi(token);
		token = strtok(NULL, " ");
		i++;
	}
	
//	printf("recieved below: \n");
	for(i=0; i<12; i++)
	{
		printf("rec_arr[%d]: %d\n", i, rec_arr[i]);	
		fprintf(fp, "rec_arr[%d]: %d\n", i, rec_arr[i]);	
	}		
	
	//server responds with 1st ACK to client close request	
	printf("\n\nFIVE\nServer sends acknowledgment to client.\n");
	fprintf(fp, "\n\nFIVE\nServer sends acknowledgment to client.\n");
	tcp_seg.src = atoi(argv[1]); //set the source port
	tcp_seg.des = atoi(argv[1]); //set the destination port
	tcp_seg.seq = rand()%100; //initial sequence number is random
	tcp_seg.ack = rec_arr[2] + 1; //initial ack number is intial client sequence number plus 1
	tcp_seg.hdr_flags = 0x5010; //data offset, reserved, URG, ACK, PSH, RST, SYN, FIN
	//above sets ACk bit to 1., 0101 0000 0001 0000 -> 0x5010
	tcp_seg.rec = 0; //receive window initially zero
	tcp_seg.cksum = 0;//checksum initially zero before calculated
	tcp_seg.ptr = 0;//urgent pointer
	tcp_seg.opt = 0;//options

	memcpy(cksum_arr, &tcp_seg, 24); //Copying 24 bytes	
	
	//compute the checksum
	  for (i=0;i<12;i++)               // Compute sum
	   sum = sum + cksum_arr[i];

	  cksum = sum >> 16;              // Fold once
	  sum = sum & 0x0000FFFF; 
	  sum = cksum + sum;

	  cksum = sum >> 16;             // Fold once more
	  sum = sum & 0x0000FFFF;
	  cksum = cksum + sum;

	  /* XOR the sum for checksum */
//	  printf("Checksum Value: 0x%04X\n", (0xFFFF^cksum));	
	  tcp_seg.cksum = 0xFFFF^cksum;  
	  
      bzero(str, 200);

	memcpy(cksum_arr, &tcp_seg, 24); //Copying 24 bytes	  	 

//	printf("sending the below: \n");
	for(i=0; i<12; i++)
	{
		printf("cksum_arr[%d]: %d\n", i, cksum_arr[i]);
		fprintf(fp, "cksum_arr[%d]: %d\n", i, cksum_arr[i]);
	}
	
	for(i=0; i<12; i++)
	{
		sprintf(str+strlen(str), "%hu ", cksum_arr[i]);
	}	  

      write(conn_fd, str, strlen(str)); // write to the client the ack 
	
	//server responds with 2nd ACK to client close request	
	printf("\n\nSIX\nServer sends close acknowledgment to client.\n");
	fprintf(fp, "\n\nSIX\nServer sends close acknowledgment to client.\n");
	tcp_seg.src = atoi(argv[1]); //set the source port
	tcp_seg.des = atoi(argv[1]); //set the destination port
	tcp_seg.seq = rand()%100; //initial sequence number is random
	tcp_seg.ack = rec_arr[2] + 1; //initial ack number is intial client sequence number plus 1
	tcp_seg.hdr_flags = 0x5001; //data offset, reserved, URG, ACK, PSH, RST, SYN, FIN
	//above sets FIN bit to 1., 0101 0000 0000 0001 -> 0x5001
	tcp_seg.rec = 0; //receive window initially zero
	tcp_seg.cksum = 0;//checksum initially zero before calculated
	tcp_seg.ptr = 0;//urgent pointer
	tcp_seg.opt = 0;//options

	memcpy(cksum_arr, &tcp_seg, 24); //Copying 24 bytes	
	
	//compute the checksum
	  for (i=0;i<12;i++)               // Compute sum
	   sum = sum + cksum_arr[i];

	  cksum = sum >> 16;              // Fold once
	  sum = sum & 0x0000FFFF; 
	  sum = cksum + sum;

	  cksum = sum >> 16;             // Fold once more
	  sum = sum & 0x0000FFFF;
	  cksum = cksum + sum;

	  /* XOR the sum for checksum */
//	  printf("Checksum Value: 0x%04X\n", (0xFFFF^cksum));	
	  tcp_seg.cksum = 0xFFFF^cksum;
	  
      bzero(str, 200);

	memcpy(cksum_arr, &tcp_seg, 24); //Copying 24 bytes	  	 

//	printf("sending the below: \n");
	for(i=0; i<12; i++)
	{
		printf("cksum_arr[%d]: %d\n", i, cksum_arr[i]);
		fprintf(fp, "cksum_arr[%d]: %d\n", i, cksum_arr[i]);
	}
	
	for(i=0; i<12; i++)
	{
		sprintf(str+strlen(str), "%hu ", cksum_arr[i]);
	}	  
	
      write(conn_fd, str, strlen(str)); // write to the client the ack 
	  
	//read the client's ack to close the connection
	//server reads the request from the client
	printf("\n\nSEVEN\nServer receives acknowledgment from client.\n");
	fprintf(fp, "\n\nSEVEN\nServer receives acknowledgment from client.\n");
    n = read(conn_fd, str, sizeof(str));	  //read the client's request to connect
	
	token = strtok(str, " "); //tokenize by space
	i=0;
	while(token)
	{
		rec_arr[i] = atoi(token);
		token = strtok(NULL, " ");
		i++;
	}
	
//	printf("recieved below: \n");
	for(i=0; i<12; i++)
	{
		printf("rec_arr[%d]: %d\n", i, rec_arr[i]);	
		fprintf(fp, "rec_arr[%d]: %d\n", i, rec_arr[i]);	
	}	
	
	  	fclose(fp);
      close (conn_fd); //close the co	fclose(fp);nnection
    }
	
}