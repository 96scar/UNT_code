/*
Scarlett Jones
CSCE 3530
Program 4
Due 11/23/16 at midnight

Description:
Demonstrate the TCP 3-way handshake and closing a TCP connection using a client-server architechture.

Client side
Must run on cse02.cse.unt.edu machine
Connects to the server
Communicates with the server using TCP segments
Demonstrates a 3-way TCP handshake with the server
Demonstrates closing a TCP connection
*/

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
 
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
 
 struct tcp_data_hdr{
                unsigned short int src; //16 bit source port
                unsigned short int des; //16 bit destination port
                unsigned int seq; //32 bit sequence number
                unsigned int ack; //32 bit acknowledgment number
				//4 bit data offset of header length (in multiples of 32 bit)
				//6 bit reserved section
				//6 bit flags (unsigned short int combines the 3 fields above)
                unsigned short int hdr_flags; //the 3 fields above are in this variable
                unsigned short int rec; //16 bit receive window for flow control, set to 128 bytes
                unsigned short int cksum; //16 bit checksum, computed after the header and data is populated
                unsigned short int ptr; //16 bit urgent data pointer, set to zero
                unsigned int opt; //32 bit options, set to zero
				char data[128]; //128 byte data = 1024 bits
              };

 
int main(int argc,char *argv[])
{
	system("clear");
	printf("\n\n\n\n\n");
	
	/* check the command line input */
	if(argc < 3)
	{
		printf("\npserver <port_number> <filename>\n\n");
		exit(1);
	}
	else if(argc > 3)
	{
		printf("\npserver <port_number> <filename>\n\n");
		exit(1);
	}
	else
	{
		//correct format, can continue on
	}	
	
    int sockfd, n;
    int len = sizeof(struct sockaddr);
	char str[1000];
	bzero(str, 1000);
    struct sockaddr_in servaddr;
	struct tcp_hdr tcp_seg; //creates a variable to modify data in struct
	unsigned short int cksum_arr[12]; //will copy the struct to this array
	unsigned short int rec_arr[12]; //will copy the recieved string of tcp segment to this array		
	unsigned int i,sum=0, cksum; 
	
	struct tcp_data_hdr tcp_data_seg; //creates a variable to modify data in struct with data
	unsigned short int cksum_data_arr[76]; //will copy the struct to this array
	unsigned short int rec_data_arr[76]; //will copy the recieved string of tcp data segment to this array		
	//unsigned int i,sum=0, cksum; 
	
	time_t t;
	srand((unsigned) time(&t)); //initialize random number seed

	FILE *fp, *fpr; //file pointer to open and write to client.out, and file pointer to read from file to send over socket
	fp=fopen("client.out", "w");
	fpr = fopen(argv[2], "rb");
	if(fpr == NULL)
	{
		printf("File error\n"); //means that you didn't make a file to read from
		exit(1);
	}
	
	printf("\n\nONE\nClient sends connection request to server.\n");
	fprintf(fp, "\n\nONE\nClient sends connection request to server.\n");
	tcp_seg.src = atoi(argv[1]); //set the source port
	tcp_seg.des = atoi(argv[1]); //set the destination port
	tcp_seg.seq = rand()%100; //initial sequence number is random
	tcp_seg.ack = 0; //initial ack number is 0
	tcp_seg.hdr_flags = 0x5002; //data offset, reserved, URG, ACK, PSH, RST, SYN, FIN
	//above sets SYN bit to 1., 0101 0000 0000 0010 -> 0x5002
	tcp_seg.rec = 0; //receive window initially zero
	tcp_seg.cksum = 0;//checksum initially zero before calculated
	tcp_seg.ptr = 0;//urgent pointer
	tcp_seg.opt = 0;//options

	memcpy(cksum_arr, &tcp_seg, 24); //Copying 24 bytes	
	
	//compute the checksum
	sum=0;
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
	  
	memcpy(cksum_arr, &tcp_seg, 24); //Copying 24 bytes	  
	
//	printf("sending below: \n");
	for(i=0; i<12; i++)
	{
		printf("cksum_arr[%d]: %d\n", i, cksum_arr[i]);	
		fprintf(fp, "cksum_arr[%d]: %d\n", i, cksum_arr[i]);	
	}

	
	for(i=0; i<12; i++)
	{
		sprintf(str+strlen(str), "%hu ", cksum_arr[i]); //putting the segment data into a string separated by space 
	}
	
    /* AF_INET - IPv4 IP , Type of socket, protocol*/
    sockfd=socket(AF_INET, SOCK_STREAM, 0);
    bzero(&servaddr,sizeof(servaddr));
 
    servaddr.sin_family=AF_INET;
    servaddr.sin_port=htons(atoi(argv[1])); // Server port number, enter by command line argument
 
    /* Convert IPv4 and IPv6 addresses from text to binary form */
	inet_pton(AF_INET,"129.120.151.94",&(servaddr.sin_addr)); // cse01 server's ip address
 
    /* Connect to the server */
    connect(sockfd,(struct sockaddr *)&servaddr,sizeof(servaddr));
	
	write(sockfd, str, strlen(str)); //write to the server the TCP segment requesting connection
	
	printf("\n\nTWO\nClient recieves the server's connection granted response.\n");
	fprintf(fp, "\n\nTWO\nClient recieves the server's connection granted response.\n");
	bzero(str, 1000);
	n=read(sockfd, str, sizeof(str)); //read the server's ack
	
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
	
	printf("\n\nTHREE\nClient sends acknowledgment to server.\n");
	fprintf(fp, "\n\nTHREE\nClient sends acknowledgment to server.\n");
	bzero(str, 1000);
	
	tcp_seg.src = atoi(argv[1]); //set the source port
	tcp_seg.des = atoi(argv[1]); //set the destination port
	tcp_seg.seq = cksum_arr[2] + 1; //sequence number is initial client seq# plus 1
	tcp_seg.ack = rec_arr[2] + 1; //ack number is initial server seq# plus 1
	tcp_seg.hdr_flags = 0x5010; //data offset, reserved, URG, ACK, PSH, RST, SYN, FIN
	//above sets ACK bit to 1., 0101 0000 0001 0000 -> 0x5010
	tcp_seg.rec = 0; //receive window initially zero
	tcp_seg.cksum = 0;//checksum initially zero before calculated
	tcp_seg.ptr = 0;//urgent pointer
	tcp_seg.opt = 0;//options

	memcpy(cksum_arr, &tcp_seg, 24); //Copying 24 bytes	
	
	//compute the checksum
	sum=0;
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
	
	write(sockfd, str, strlen(str)); //write to the server the ack message to establish a connection
	
	
	
	
	/*
	this is where i am adding the part that sends the data
	it will be broken up into 8 times. each time it takes 128 bytes from the file
	and it adds 128 to the sequence number and ack number
	*/
	//tcp_data_seg = tcp_seg from the most recent segement
	tcp_data_seg.src = tcp_seg.src; //set the source port
	tcp_data_seg.des = tcp_seg.des; //set the destination port
	tcp_data_seg.seq = tcp_seg.seq; //sequence number is initial client seq# plus 1
	tcp_data_seg.ack = tcp_seg.ack; //ack number is initial server seq# plus 1
	tcp_data_seg.hdr_flags = tcp_seg.hdr_flags; //data offset, reserved, URG, ACK, PSH, RST, SYN, FIN
	//above sets ACK bit to 1., 0101 0000 0001 0000 -> 0x5010
	tcp_data_seg.rec = tcp_seg.rec; //receive window initially zero
	tcp_data_seg.cksum = tcp_seg.cksum;//checksum initially zero before calculated
	tcp_data_seg.ptr = tcp_seg.ptr;//urgent pointer
	tcp_data_seg.opt = tcp_seg.opt;//options

	int j=0;
	while(j<8)
	{
		printf("\n\nClient sends data segment to server.\n");
		fprintf(fp, "\n\nClient sends data segment to server.\n");
		bzero(str, 1000);
		fseek(fpr, 128*j, SEEK_SET); //moves current position forward 128 bytes each time
		fread(tcp_data_seg.data, 1, 128, fpr);	//reads 128 bytes
	//	printf("\n\ndata to send %s\n\n", tcp_data_seg.data);
		memcpy(cksum_data_arr, &tcp_data_seg, 152); //Copying 152 bytes
		
			//compute the checksum
			sum=0;
			  for (i=0;i<76;i++)               // Compute sum
			   sum = sum + cksum_data_arr[i];

			  cksum = sum >> 16;              // Fold once
			  sum = sum & 0x0000FFFF; 
			  sum = cksum + sum;

			  cksum = sum >> 16;             // Fold once more
			  sum = sum & 0x0000FFFF;
			  cksum = cksum + sum;

			  /* XOR the sum for checksum */
		//	  printf("Checksum Value: 0x%04X\n", (0xFFFF^cksum));	
			  tcp_data_seg.cksum = 0xFFFF^cksum;
			  
			memcpy(cksum_data_arr, &tcp_data_seg, 152); //Copying 152 bytes	
			
		//	printf("sending the below: \n");
			for(i=0; i<12; i++)
			{
				printf("cksum_data_arr[%d]: %d\n", i, cksum_data_arr[i]);	
				fprintf(fp, "cksum_data_arr[%d]: %d\n", i, cksum_data_arr[i]);	
			}
			
//			for(i=12; i<76; i++)
//			{
//				printf("cksum_data_arr[%d]: %c\n", i, cksum_data_arr[i]);
//			}
			
			for(i=0; i<12; i++)
			{
				sprintf(str+strlen(str), "%hu ", cksum_data_arr[i]);
			}
			
			sprintf(str+strlen(str), "|"); //split the header from the data with a |
			
			for(i=0; i<128; i++)
			{
		//		sprintf(str+strlen(str), "%c", cksum_data_arr[i]);
				sprintf(str+strlen(str), "%c", tcp_data_seg.data[i]);
			}
			sprintf(str+strlen(str), "|");
			
//			printf("\nstring sending: %s\n\n", str);
//			printf("\nsize of string: %d\n\n", sizeof(str));
//			printf("\nlength of string: %d\n\n", strlen(str));			
			write(sockfd, str, strlen(str)); //write to the server the data segment
//			printf("\nstring sent: %s\n\n", str);
			
			printf("\n\nClient receives data ack from the server.\n");
			fprintf(fp, "\n\nClient receives data ack from the server.\n");
			bzero(str, 1000);			
			
			read(sockfd, str, sizeof(str)); // read from the server the data acknowledgment
			
			token = strtok(str, " "); //tokenize by space
			i=0;
			while(token)
			{
				rec_data_arr[i] = atoi(token);
				token = strtok(NULL, " ");
				i++;
			}
			
		//	printf("recieved below: \n");
			for(i=0; i<12; i++)
			{
				printf("rec_data_arr[%d]: %d\n", i, rec_data_arr[i]);	
				fprintf(fp, "rec_data_arr[%d]: %d\n", i, rec_data_arr[i]);	
			}	

		//set the client's new segment values here
		tcp_data_seg.src = atoi(argv[1]); //set the source port
		tcp_data_seg.des = atoi(argv[1]); //set the destination port
		tcp_data_seg.seq = cksum_data_arr[2] + 1; //sequence number is what the server's ack number was
		tcp_data_seg.ack = cksum_data_arr[4] + 1; //ack number is initial server seq# plus 1
		tcp_seg.hdr_flags = 0x5010; //data offset, reserved, URG, ACK, PSH, RST, SYN, FIN
		//above sets ACK bit to 1., 0101 0000 0001 0000 -> 0x5010
		tcp_data_seg.rec = 0; //receive window initially zero
		tcp_data_seg.cksum = 0;//checksum initially zero before calculated
		tcp_data_seg.ptr = 0;//urgent pointer
		tcp_data_seg.opt = 0;//options	
		
		j++;
	}	
	
	
	
	
	//close request
	printf("\n\nFOUR\nClient sends close request to server.\n");
	fprintf(fp, "\n\nFOUR\nClient sends close request to server.\n");
	bzero(str, 1000);
	tcp_seg.src = atoi(argv[1]); //set the source port
	tcp_seg.des = atoi(argv[1]); //set the destination port
	tcp_seg.seq = rand()%100; //initial sequence number is random
	tcp_seg.ack = 0; //initial ack number is 0
	tcp_seg.hdr_flags = 0x5001; //data offset, reserved, URG, ACK, PSH, RST, SYN, FIN
	//above sets FIN bit to 1., 0101 0000 0000 0001 -> 0x5001
	tcp_seg.rec = 0; //receive window initially zero
	tcp_seg.cksum = 0;//checksum initially zero before calculated
	tcp_seg.ptr = 0;//urgent pointer
	tcp_seg.opt = 0;//options

	memcpy(cksum_arr, &tcp_seg, 24); //Copying 24 bytes	
	
	//compute the checksum
	sum=0;
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
	  
	memcpy(cksum_arr, &tcp_seg, 24); //Copying 24 bytes	  
	
//	printf("sending below: \n");
	for(i=0; i<12; i++)
	{
		printf("cksum_arr[%d]: %d\n", i, cksum_arr[i]);	
		fprintf(fp, "cksum_arr[%d]: %d\n", i, cksum_arr[i]);	
	}

	
	for(i=0; i<12; i++)
	{
		sprintf(str+strlen(str), "%hu ", cksum_arr[i]);
	}	
	
	write(sockfd, str, strlen(str)); //write to the server the TCP segment requesting connection
	
	//client reads the 1st ack tcp segement from server
	printf("\n\nFIVE\nClient receives acknowledgment from server.\n");
	fprintf(fp, "\n\nFIVE\nClient receives acknowledgment from server.\n");
	bzero(str, 1000);
	n=read(sockfd, str, sizeof(str)); //read the server's ack
	
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
	
	//client reads the 2nd ack tcp segment from server
 	printf("\n\nSIX\nClient recieves close acknowledgment from server.\n");
	fprintf(fp, "\n\nSIX\nClient recieves close acknowledgment from server.\n");
	bzero(str, 1000);
	n=read(sockfd, str, sizeof(str)); //read the server's ack
	
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
	
	//client responds back to server with ACK tcp segment
	printf("\n\nSEVEN\nClient sends acknowledgment to server.\n");
	fprintf(fp, "\n\nSEVEN\nClient sends acknowledgment to server.\n");
	bzero(str, 1000);
	
	tcp_seg.src = atoi(argv[1]); //set the source port
	tcp_seg.des = atoi(argv[1]); //set the destination port
	tcp_seg.seq = cksum_arr[2] + 1; //sequence number is initial client seq# plus 1
	tcp_seg.ack = rec_arr[2] + 1; //ack number is initial server seq# plus 1
	tcp_seg.hdr_flags = 0x5010; //data offset, reserved, URG, ACK, PSH, RST, SYN, FIN
	//above sets ACK bit to 1., 0101 0000 0001 0000 -> 0x5010
	tcp_seg.rec = 0; //receive window initially zero
	tcp_seg.cksum = 0;//checksum initially zero before calculated
	tcp_seg.ptr = 0;//urgent pointer
	tcp_seg.opt = 0;//options

	memcpy(cksum_arr, &tcp_seg, 24); //Copying 24 bytes	
	
	//compute the checksum
	sum=0;
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
	
	write(sockfd, str, strlen(str)); //write to the server the ack message to end the connection	
	
	fclose(fp);
	fclose(fpr);
}