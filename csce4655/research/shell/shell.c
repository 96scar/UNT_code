/*
Names: Jacob Hanson, Scarlett Jones, M. Kellen Mills
Course: CSCE 3600.001: Systems Programming
Due Date: 11:59 PM on Monday, April 4, 2016
Project: Major Assignment 1 – The Shell and System Calls
Description: This is a command line interpreter or shell. The shell 
            creates a child process that executes the command you entered and
            then prompts for more input when it has finished. There is an
            interactive mode and a mode that reads a batchfile. We handle 
            internal commands like exit and cd.
*/

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int TRUE = 1;
int FALSE = 0;
size_t BUFFERSIZE = 256;
char *splitToken1 = {";\n"};    // characters to split one line by: semicolons(;) and line breaks(\n)
char *splitToken2 = {" \n"};    // characters to split one command by in order to separate commands from arguments: spaces( ) and dashes(-)
char *prompt = {"prompt"};      // prompt string

void Close(int signum);
void runCommands(char *in);     // splits and runs one line containing one or more commands
void trimWhiteSpace(char *in);  // trims leading or trailing spaces from a string

/*
This main section accepts command line arguments in the following format: ./shell [batchFile]
The file name in brackets is optional 
There should only be 1 or 2 command line arguments
*/
int main(int argc, char *argv[]) {
    signal(SIGINT, Close);
    signal(SIGHUP, Close);
    signal(-1, Close);
    if(argc == 1) //shell, interactive mode
    {
        printf("*** interactive mode ***\n");
        char *input = (char*) malloc(BUFFERSIZE);
        printf("\n%s> ", prompt);
        while( (getline(&input, &BUFFERSIZE, stdin)) != EOF ) {
            runCommands(input);
            printf("%s> ", prompt);
        }                   
        Close(EOF);
    }
    else if(argc == 2) //shell [batchFile], batch mode
    {
        /* batchFile: an optional argument (indicated by square brackets as above). If
        present, your shell will read each line of the batchFile for commands to be
        executed. If not present, your shell will run in interactive mode by printing a
        prompt to the user at stdout and reading the command stdin. */
        
        FILE *ptr;
        ptr = fopen(argv[1], "r");
        if(ptr==NULL)
        {
            perror ("Error opening file"); //prints out error message
            exit(1);
        }
        //int line = 0;
        char *input = (char*) malloc(BUFFERSIZE);
        printf("*** batch mode ***\n--> file: %s", argv[1]);
        while( (getline(&input, &BUFFERSIZE, ptr)) != EOF )
        {
            printf("batch line> %s\n",input);
            runCommands(input);
        }
        
        fclose(ptr); //close file after we are done with it
    }
    else //too many command line arguments
    {
        printf("\nUsage: ./shell [batchFile]\n\n");
        exit(1);
    }
    return 0;
}

/*
Name: trimWhiteSpace
Parameters: A string
Returns: nothing
Description: This function gets rid of whitespace that we don't need in a word.
*/
void trimWhiteSpace(char *in) {
    int length = 0; // length of string
    while (in[length++] != '\0'); length--; // count string length
    int first = 0, last = length; // first and last indices of nonwhitespace characters
    while (in[first++] == ' ' && first < length); first--; // find index of first nonwhitespace character
    while (in[last--] == ' ' && last > 0); last++; // find index of last nonwhitespace character, looking back to front
    char *temp = (char*) malloc(BUFFERSIZE); // allocate a temp string
    memcpy(temp, &in[first], last-first); // copy the correct, trimmed string into temp, starting at first and copying the differences of bytes between first and last
    temp[last-first] = '\0'; // null terminate temp
    strcpy(in, temp); // copy the correct, trimmed string back into the original
}

/*
Name: runCommands
Parameters: a c string (array of characters)
Returns: nothing
Description: 
*/
void runCommands(char *in) 
{
    int numberOfCommands = 0;
    char *input = in;
    char *token1 = (char*) malloc(BUFFERSIZE);
    int index = 0;
    char *change = (char*) malloc(BUFFERSIZE);
    char *commands[BUFFERSIZE];

    int n; for (n = 0; n < BUFFERSIZE; n++) { // allocate commands array
        (commands)[n] = (char*) malloc(BUFFERSIZE);
    }
        
    // get the first token
    token1 = strtok(input, splitToken1);
    
    // walk through other tokens
    while( token1 != NULL ) {
        numberOfCommands++;
        commands[index] = token1;
        token1 = strtok(NULL, splitToken1);
        index++;
    }
    
    //printf("Number of commands: %d\n", numberOfCommands); //this is for error checking only, right? yes -jeb
    int i; for (i = 0; i < numberOfCommands; i++) { // trim whitespace from each command
        trimWhiteSpace(commands[i]);
        //printf("%s\n", commands[i]);
    }
    int shouldQuit = FALSE;
    int shouldExit = FALSE;
    int shouldCD   = FALSE;
    for (i = 0; i < numberOfCommands; i++) {
       // printf("%s\n", commands[i]);
        if(!(strcmp(commands[i], "quit"))) {
            shouldQuit = TRUE;
        }
        if(!(strcmp(commands[i], "exit"))) {
            shouldExit = TRUE;
        }
        if((commands[i][0] == 'c') && (commands[i][1] == 'd') && (commands[i][2] == ' '))   {
            strtok(commands[i], splitToken2);
            change = strtok(NULL, "");
            shouldCD = TRUE;
        }
    }
    // Commands are executed here. fork is called for each command, and then it is run.
    int numberOfCommandsToHandle = numberOfCommands;
    pid_t pids[numberOfCommands];
    /* Start children. */
    int k; for (k = 0; k < numberOfCommandsToHandle; ++k) {
        if ((pids[k] = fork()) < 0) {
            perror("fork");
            abort();
        } else if (pids[k] == 0) {
            // finally execute command k from the array of commands
            // check if command line contains forward slash, if this is true then we are assuming it is in the path format of /bin/ls
            int containsForwardSlash = FALSE; int b = 0; while (b < strlen(commands[k])) if (commands[k][b++] == '/') containsForwardSlash = TRUE; 
            // path condition
            if (containsForwardSlash) {
                int numberOfArgs = 0;
                char *token2 = (char*) malloc(BUFFERSIZE);
                char *command = (char*) malloc(BUFFERSIZE);
                char *tempArgs[BUFFERSIZE];
                int z; for (z = 0; z < BUFFERSIZE; z++) { // allocate args array
                    (tempArgs)[z] = (char*) malloc(BUFFERSIZE);
                }
                // get the first token, command from the line
                command = strtok(commands[k], splitToken2);
                // walk through other tokens and place them into the arg array
                while( token2 != NULL ) {
                    tempArgs[numberOfArgs] = token2;
                    numberOfArgs++;
                    token2 = strtok(NULL, splitToken2);
                }
                char *args[numberOfArgs+2]; // need to add two, one for the command at the beginning, and one at the end for the null terminator
                args[0] = command;
                int g; for (g = 0; g < numberOfArgs; g++) {
                    (args)[z] = (char*) malloc(BUFFERSIZE);
                    tempArgs[g] = tempArgs[g+1];
                    args[g+1] = tempArgs[g];
                }
                numberOfArgs+=1;
                args[numberOfArgs-1] = NULL; // null terminator for the arg array
                
                char *toCzech = (char*) malloc(BUFFERSIZE);
                strcat(toCzech, "which ");
                strcat(toCzech, command);
                strcat(toCzech, " > /dev/null");
                if(system(toCzech) != '\0')
                {
                    printf("ERROR: command not found: %s\n", command);
                    exit(0);
                }
                
                execv(command, args);
            }
            else { // if there are no forward slashes (/) in the command argument, we assume it isn't in the path format
                int numberOfArgs = 0;
                char *token2 = (char*) malloc(BUFFERSIZE);
                char *command = (char*) malloc(BUFFERSIZE);
                char *tempArgs[BUFFERSIZE];
                int z; for (z = 0; z < BUFFERSIZE; z++) { // allocate args array
                    (tempArgs)[z] = (char*) malloc(BUFFERSIZE);
                }
                // get the first token, command from the line
                command = strtok(commands[k], splitToken2);
                // walk through other tokens and place them into the arg array
                while( token2 != NULL ) {
                    tempArgs[numberOfArgs] = token2;
                    numberOfArgs++;
                    token2 = strtok(NULL, splitToken2);
                }
                char *args[numberOfArgs+2]; // need to add two, one for the command at the beginning, and one at the end for the null terminator
                args[0] = command;
                int g; for (g = 0; g < numberOfArgs; g++) {
                    (args)[z] = (char*) malloc(BUFFERSIZE);
                    tempArgs[g] = tempArgs[g+1];
                    args[g+1] = tempArgs[g];
                }
                numberOfArgs+=1;
                args[numberOfArgs-1] = NULL; // null terminator for the arg array
                if (!strcmp(command, "quit")) exit(0); // if the child detects one of the internal commands, just exit the child and let the parent handle it later
                if (!strcmp(command, "exit")) exit(0);
                if(!strcmp(command, "cd"))   exit(0);

                    char *toCzech = (char*) malloc(BUFFERSIZE);
                    strcat(toCzech, "which ");
                    strcat(toCzech, command);
                    strcat(toCzech, " > /dev/null"); // send the output of the system call to /dev/null where it isn't preserved
                    if(system(toCzech) != '\0')
                    {
                        printf("ERROR: command not found: %s\n", command);
                        exit(0);
                    }
                
                    execvp(command, args);
            }
            exit(0);
        }
    }
    
    // wait for child processes to finish
    while (numberOfCommandsToHandle > 0) {
        wait(NULL);
        numberOfCommandsToHandle--;
    }
    if (shouldQuit == TRUE) {
        // quit here
        Close(0);
    }
    if (shouldExit == TRUE) {
        // exit here
        exit(0);
    }
    

    
    if(shouldCD == TRUE){
        if(chdir(change) == -1)
            printf("ERROR: specified directory does not exist\n");
    }
    return;
}

/*
Name: Close
Parameters: a signal number
Returns: nothing
Description: exits when a signal is caught, like CTRL D
*/
void Close(int signum) {
    printf("Exiting shell. Goodbye!\n");
    exit(SIGINT);
}