/*
Author: Scarlett Jones
Course: CSCE 3600.001 - Systems Programming
Minor Assignment 6: Implementing Command Line Pipe
Due Date: 11:59 PM on Monday, March 28, 2016
Description: Launches 2 applications given as command line
	arguments using execvp(). Standard output of the first
	argument(not the executable) is piped into the standard
	input of the second argument. Create 2 child processes,
	the output of one will be piped as the input of the other,
	the parent waits for both child processes to terminate 
	before it prints out a message and exits. No flag options 
	supported. Handle error cases as applicable.
*/

#include <stdio.h>
#include <stdlib.h> // exit
#include <unistd.h> // STDIN_FILENO, STDOUT_FILENO, execvp, dup2, pipe, fork, close
#include <sys/types.h> // pid_t
#include <fcntl.h> // open

int main(int argc, char *argv[])
{
	pid_t childA, childB; //process id's of children
	int fd[2]; // file descriptor with fd[0] and fd[1], in and out
	
    if(pipe(fd) == -1)  //create a pipe with fd
	{
          perror("Pipe failed\n");
          exit(1);
    }
	
	if(argc < 3) //too few arguments
	{
		printf("error: too few or too many arguments: %d\n", argc);
		exit(1);
	}
	else if(argc > 3) //too many arguments
	{
		printf("error: too few or too many arguments: %d\n", argc);
		exit(1);
	}
	else //exactly 3
	{
		;
	}
	
	printf("executing: %s | %s\n", argv[1], argv[2]); // print out command to be executed
	
	childA = fork(); //create childA process
	
	if(childA == 0) //in childA
	{
		//standard output redirect
		close(STDOUT_FILENO); //close stdout
		dup2(fd[1], 1); //duplicated fd[1] to stdout
		close(fd[0]); //close fd[0 & 1] to save space
		close(fd[1]);
		
		char* const pA[] = {argv[1], 0}; //make a string of type char* const* that has command line argument 1
		execvp(pA[0], pA); //execute the 1st command
		
		printf("execvp failed\n"); //shouldn't get here
		exit(1);
	}
	else //in parent
	{
		childB = fork(); //create childB process
		
		if(childB == 0) //in childB
		{
			//standard input redirect
			close(STDIN_FILENO); //close stdin
			dup2(fd[0], 0); //duplicated fd[0] to stdin
			close(fd[1]); //close fd[1 & 0] to save space
			close(fd[0]);
			
			char* const pB[] = {argv[2], 0}; //make a string of type char*const* that has command line arg 2
			execvp(pB[0], pB); //execute the 2nd command
			
			printf("execvp failed\n"); //shouldn't get here
			exit(1);
		}
		else //in parent
		{			
			close(fd[0]); //close fd[0 & 1] in the parent
			close(fd[1]);
			wait(0); //wait for childA
			wait(0); //wait for childB

			printf("command line pipe completed\n"); 
		}
	}
	
	return 0;
}