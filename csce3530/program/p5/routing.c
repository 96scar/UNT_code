/*
Scarlett Jones
CSCE 3530
Programming Assignment #5
Description: Finds the least cost forwarding path for all routers using Dijkstra's algorithm.
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


int nodePos(char n, char node[256], int length);
int minimum(int min[256], int inPath[256], int length);
int minVal(int num1, int num2);
void dijkstra(char start, int costTable[256][256], char node[256], int length);

int main()
{
	char tempNode1, tempNode2; //start node to end node
	int tempCost; //cost between the nodes
	int costTable[256][256]; //adjacency matrix that tells the costs between nodes connected by 1 hop
	int length = 0; //length of the list, or the number of nodes total
	char node[256]; //an array of the nodes names
	int exists = 0; //tells you whether or not a node has been put in the node array yet
	int i, j; //iterators to loop through arrays and matrices
	
	FILE *fp; //file pointer
	fp = fopen("router.txt", "r"); //open the file to read it
	
	if(fp == NULL) //if the file pointer points to null
	{
		perror("Error"); //file can't be opened
		exit(1); //exit the program
	} //end if

	for(i=0; i<256; i++) //initialize costTable to infinity
	{
		for(j=0; j<256; j++)
		{
			costTable[i][j] = INT_MAX;
		} //end for
	} //end for	
	
	while((fscanf(fp, " %c %c %d", &tempNode1, &tempNode2, &tempCost)) == 3) //scan in formatted input from the file until scanf returns something other than 3 (scanf returns number of items successfully read)
	{
		//printf("%c %c %d\n", tempNode1, tempNode2, tempCost);
		exists=0; //set exists to 0 at the beginning
		
		//printf("length: %d\n", length);
		if(length == 0) //if nothing is in the list to begin with, add both routers to the list
		{
			node[length] = tempNode1;		
			length++;
			
			node[length] = tempNode2;			
			length++;
		} //end if

		exists = 0;
		for(i=0; i<length; i++) //search list for 1st node
		{
			if(exists == 1)
			{
				break;
			} //end if
			else
			{
				if(node[i] == tempNode1)
				{
					exists = 1;
					break;
				} //end if					
			} //end else
		} //end for
		if(exists == 0)
		{
			node[length] = tempNode1;
			length++;				
		} //end if

		exists = 0;
		for(i=0; i<length; i++) //search list for 2nd node
		{
			if(exists == 1)
			{
				break;
			} //end if 
			else
			{
				if(node[i] == tempNode2)
				{
					exists = 1;
					break;
				} //end if					
			} //end else

		} //end for
		if(exists == 0)
		{
			node[length] = tempNode2;
			length++;					
		} //end if
		exists=0;
	

		for(i=0; i<length; i++) //fill in the costTable
		{
			if(node[i] == tempNode1)
			{
				for(j=0; j<length; j++)
				{
					if(node[j] == tempNode2)
					{
						costTable[i][j] = tempCost;
						costTable[j][i] = tempCost;
					} //end if
				} //end for
			} // end if
		} // end for


	} //end while

	for(i=0; i<length; i++) //make the diagonals of the costTable 0
	{
		for(j=0; j<length; j++)
		{
			if(i==j)
				costTable[i][j] = 0;
		} //end for
	} //end for	

	 //this just prints out the cost table
	for(i=0; i<length; i++)
	{
		printf("%11c ", node[i]);
	} //end for
	printf("\n");
	for(i=0; i<length; i++)
	{
		printf("%c", node[i]);
		for(j=0; j<length; j++)
		{
			printf("%11d ", costTable[i][j]);
		} //end for
		printf("\n");
	} //end for
	printf("\n");

	
	//loop through how many times to do the algorithm (for each node)
	for(i=0; i<length; i++)
	{
		dijkstra(node[i], costTable, node, length);
	}
	
	fclose(fp); //close the file
	return 0;
} //end main

/*
function: nodePos
parameters: node, node list, length
returns: position of node
description: returns the position of the node
*/
int nodePos(char n, char node[256], int length)
{
	int i;
	
	for(i=0; i<length; i++)
	{
		if(node[i] == n)
		{
			return i;
		}
	}
	
	return -1;
}

/*
function: minimum
parameters: min values list, inPath(T/F), length of list
returns: minimum position
description: tells you the minimum position
*/
int minimum(int min[256], int inPath[256], int length)
{
	int least, i, node;
	least = INT_MAX;
	
	for(node=0; node<length; node++)
	{
		if((inPath==0) && (min[node] <= least))
		{
			least = min[node];
			i = node;
		}
	}
	//printf("minposition: %d\n", i);
	
	return i;
}

/*
function: minVal
parameters: 2 numbers
returns: the smaller number
description: tells you the smaller number
*/
int minVal(int num1, int num2)
{
	int least, i;
	least = INT_MAX;
	
	if(num1 < num2)
	{
		least = num1;
	}
	else
	{
		least = num2;
	}

	return least;
}

/*
function: dijkstra
parameters: Cost table, nodes list, length
returns: nothing
description: Performs Dijkstra's algorithm starting from the node entered.
				  Prints out the routing table for the node entered.
*/
void dijkstra(char start, int costTable[256][256], char node[256], int length) 
{
	int i, j; //iterators
	int min[256]; //the minimum cost from start to i
	//int d1, d2; //distance 1 distance 2
	//char previous, next; //the previous node and the next node
	char path[256] ; //the path taken
	int inPath[256]; //true or false that a node is in the path
	int leastCost[256][256]; //the least cost graph to fill in
	//int pathCount=1; //the count of the number of nodes in the path
	int count=0;
	int node1, node2;
	char next[256];
	
	FILE *ls;
	ls = fopen("LS.txt", "a");
	
	for(i=0; i<length; i++)
	{
		min[i] = INT_MAX; //infinity value
		inPath[i] = 0; //nothing is in the path yet
	}
	
	min[nodePos(start, node, length)] = 0; // the minimum distance for the start to start is 0
	
	path[0] = start; //the path starts with the first node
	for(i=0; i<length; i++)
	{
		path[i] = start; //intitialize the path list to something
	}
	for(i=0; i<length; i++)
	{
		if(i+1<length)
			next[i] = path[i+1];
		else if(i+1==length)
			next[i] = path[0];
	}
	
	//find shortest path for the rest 
	for(count=0; count<length-1; count++)
	{
		//find the min distance vertex from start
		//node1 = minimum(min, inPath, length);
		
		//when a node gets put in the path, make it true that it's contained
		inPath[nodePos(start, node, length)] = 1;
		path[nodePos(start, node, length)] = node[nodePos(start, node, length) + 1];
		
		//put the distance values that exist that aren't infinity in the min values
		for(i=0; i<length; i++)
		{
		//	if((inPath[i]==0) && (costTable[node1][i] != 0) && (min[node1] != INT_MAX) && ((min[node1] + costTable[node1][i]) < min[i]))
		//	{
		//		min[i] = min[node1] + costTable[node1][i];
			//}
			min[nodePos(start, node, length)] = 0;
			if((costTable[start][i] != INT_MAX) && costTable[start][i] != 0)
			{
				min[i] = minVal(min[i], min[nodePos(start, node, length)]+costTable[nodePos(start, node, length)][i]);
				//next[i] = node[i];			
			}

			
		}
	}
	
	//printf("Routing Table for %c\n", start);
	//fprintf(ls, "Routing Table for %c\n", start);
	//printf("Node	Link		Distance\n");
	//fprintf(ls, "Node	Link		Distance\n");
	for(i=0; i<length; i++)
	{
		if(node[i] != start)
		{
			if(i+1 == length)
			{
				printf("%c (%c, %c)\n", node[i], start, node[0]);
				fprintf(ls, "%c (%c, %c)\n", node[i], start, node[0]);				
			}
			else
			{
				printf("%c (%c, %c)\n", node[i], start, node[i+1]);
				fprintf(ls, "%c (%c, %c)\n", node[i], start, node[i+1]);					
			}

			//printf("%c	(%c, %c)		%d\n", node[i], start, path[1] ,min[i]);
			//fprintf(ls, "%c	(%c, %c)		%d\n", node[i], start, path[1], min[i]);			
		}

	}
	printf("--------\n");
	fprintf(ls, "--------\n");
	
	fclose(ls);
	return;
}