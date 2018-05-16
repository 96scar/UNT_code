/*
Name: Scarlett Jones
Class: CSCE 3612
Teacher: Dr. Robin
Due: 4/19/2017
Description: Write a C program to create a dynamic queue to store non-zero positive integers.
The input and output is shown below. Each line is an input followed by a single line
output, where C is used to create a queue and it is followed by a non-zero positive
size of the queue, I is used to write values into the queue and it is followed by the
input value, R is used to read the head of the queue, P is used to print the queue
contents, L is used to get the length of the queue, M is used to modify the length of
the queue and it is followed by the new size of the queue (new size > old size), and
E is used to exit the program. Comment your code. 

Whenenver I resize, the output for my code doesn't match the sample output. 
Other than that, I think my code is working correctly.
*/

#include <stdio.h>
#include <stdlib.h>

/*
function prototypes
*/
void create(int size);
void queue_init();
void get_length();
void modify_length(int length);
void print_queue();
void enqueue(int val);
int dequeue();


/*
global variables
*/
int head, tail; //index of current queue head and tail
int qsize =0; //the size of the queue
int qmax=0; //the max size of the queue to access in array
int *q; //dynamically allocate q array
int count=0; //keep count of how many things are in the queue

int main()
{	
	char letter='a';//make sure the letter doesn't start at e or E
	int num=0; //num that gets read in
	
	while((letter != 'e')&&(letter != 'E')) // keep going until the letter received is e, shouldn't need to check this
	{
		scanf("%c", &letter); //read in a letter

		switch(letter) //based on the letter, decide what to do next
		{
			case 'c': //create a queue of size num
			case 'C':
				scanf("%d", &num); //read in the size of the queue
				create(num);
				break;
			case 'i': //write values into queue
			case 'I':
				scanf("%d", &num); //read in value to write to queue
				enqueue(num);
				break;
			case 'r': //read the head of the queue
			case 'R':
				dequeue();
				break;
			case 'p': //print the queue
			case 'P':
				print_queue();
				break;
			case 'l': //print the length of queue
			case 'L':
				get_length();
				break;
			case 'm': //modify length of queue
			case 'M':
				scanf("%d", &num); //read in size of the queue
				modify_length(num);
				break;
			case 'e': //exit the program
			case 'E':
				exit(0);
				//exit program
				break;
			default:
				//Wrong input
				break;
		}
	}

	
	return 0;
}

void create(int size) //create queue
{
	//create queue
	qsize=size; //initialize qsize and qmax
	qmax = qsize-1;
	
	q = malloc((qsize)*sizeof (int*)); //dynamically allocates space for the array of size qsize
	queue_init(); //initialize head and tail
	
	print_queue(); //print queue
}

void queue_init()
{
	//initialize queue data structure
	head = 0;
	tail = 0;
}

void get_length()
{
	//print length of queue
	printf("%d\n", qsize);
}

void modify_length(int length)
{
	int i;
	//change the length of the queue
	qsize=length; //set qsize to new value
	
	q=(int*)realloc(q, (qsize)*sizeof(int*)); //dynamically reallocate space for the rest of the array
	
	for(i=qmax+1; i<qsize; i++) 
	{
		q[i] = 0; //initialize all the newly allocated space to 0
	}
	qmax = qsize-1; //set qmax to new value
	
	print_queue();//print the queue
}


void print_queue() //print the queue
{
	int i;
	for(i=0; i<qsize; i++)
	{
		printf("%d ", q[i]);
	}
	printf("\n");
}

void enqueue(int val) //add something to queue
{
	if(count == qsize) //if the amount in queue is equal to size of queue, then queue is full
	{
		printf("Full\n");
		return;
	}
	
	q[tail] = val; //put new value into q at tail
	
	//update the tail
	if(tail==qmax)
	{
		tail = 0; //wrap tail around
	}
	else
	{
		tail++; //increment tail
	}
	
	print_queue();// print queue
	count++; //increment how much is in queue
}

int dequeue() // read head of queue
{
	int returnval;
	if(head==tail) //if nothing in queue
	{
		printf("Empty\n");
		return returnval;
	}
	
	returnval=q[head]; //the head of the queue

	if(head!=tail) //if there is somthing in queue
	{
		printf("%d\n", returnval); //print out queue
	}
	
	if(head==qmax) //if head reaches the max
	{
		head=0; //wrap head around
	}
	else
	{
		head++; //increment head
	}
	
	count--; //decrement how much is in the queue
	return returnval;
}