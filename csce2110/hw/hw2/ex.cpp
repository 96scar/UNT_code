/*
Author: Scarlett Jones
Course: CSCE 2110
Due Date: April 1, 2016
Description: This solves the traveling salesman problem,
given input on the cities and the costs to travel between
them. This assumes the travel cost is symmetric between
cities. The way to travel between the cities and back to 
the original cities is printed out with the cost. Only the
least expensive is printed out. Solved recursively. Find 
each possible path and the total cost for each trip. Save
the lowest cost and path each time a cheaper one is found.
*/

#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <cstdlib>
#include <cstdio>
#define MAX 15
using namespace std;

int getCost(int tour[MAX], int costs[MAX][MAX], int length, int cities[MAX]);
void swap(int *a, int *b);
void permute(int array[MAX], int start, int end, int costs[MAX][MAX], int copy[MAX], int finalCost[1], int finalTour[MAX]);
int getPosition(int input, int array[MAX], int length);

int main()
{
	string str; //input string
	int i, j, val, start, end, startPos, endPos; // iterator, iterator, value of cost, start city, end city, start array position, end array position
	int cities[MAX], copy[MAX], lowestCost[1], bestTour[MAX]; //array of cities, copy of cities array, lowest cost, best tour
	int length = 0; //length of array
	int cost[MAX][MAX]; //cost graph to figure out how much a trip costs
	char type; // either a or c to input an arc or a city
	
	//initialize arrays to -1, because that is not going to be used
	for(i=0; i<MAX; i++)
	{
		cities[i] = -1;
		copy[i] = -1;
	}
	for(i=0; i<MAX; i++)
	{
		for(j=0; j<MAX; j++)
		{
			cost[i][j] = -1;
		}
	}
	
	//get input until the end
	while(getline(cin, str))
	{
		int spacePos1 = str.find(' '); //finds 1st space
		string arg1 = str.substr(0, spacePos1); //from start to 1st space
		string str2 = str.substr(spacePos1 + 1); //from 1st space to end
		
		type = arg1.at(0); // is it an a or a b?
		if(type == 'a') //arc cost
		{
			int spacePos2 = str2.find(' '); //finds 2nd space
			string arg2 = str2.substr(0, spacePos2); //from 1st space to 2nd space
			string str3 = str2.substr(spacePos2 + 1); //from 2nd space to end
			int spacePos3 = str3.find(' '); //find 3rd space
			string arg3 = str3.substr(0, spacePos3); //from 2nd space to 3rd space
			string arg4 = str3.substr(spacePos3 + 1); //from 3rd space to end
			
			start = atoi(arg2.c_str()); //convert arg2 to int
			end = atoi(arg3.c_str()); //convert arg3 to int
			startPos = getPosition(start, cities, length); //find position start is in cities array
			endPos = getPosition(end, cities, length); //find position end is in cities array
			val = atoi(arg4.c_str()); //convert arg4 to int value
			cost[startPos][endPos] = val; //set cost array to value input in 1st spot
			cost[endPos][startPos] = val; //set cost array to value input in 2nd spot
			
			//set cost[i][j] to zero where i and j match, it costs zero to go from a city to itself
			for(i=0; i<length; i++)
			{
				for(j=0; j<length; j++)
				{
					if(i == j)
					{
						cost[i][j] = 0;	
					}
				}
			}
		}
		else if(type == 'c') //city
		{
			string arg2 = str2;
			
			val = atoi(arg2.c_str()); //convert arg2 to int

			cities[length++] = val; //put city into the cities array and increment length of cities
		}
		else
		{
			cout << "Must be an 'a' or a 'c'" << endl; // error message for wrong type
		}
	}
	
	//copies cities array so that i have a copy that doesn't move around
	for(i=0; i<MAX; i++)
	{
		copy[i] = cities[i];
	}
	
	/* cost array imagined picture
		  1		  2		  3
	     -------------------- 
	  1 | 0		  10	  15 |
							 |
	  2 | 10	  0		  20 |
							 |
	  3 | 15	  20	  0  |
	     --------------------
	*/
	
	
/*	testing
	cout << "Cost: " << endl;
	for(int d=0; d<length; d++)
	{
		for(int e=0; e<length; e++)
		{
			cout << setw(5) << cost[d][e] << " ";
		}
		cout << endl;
	}
	
	cout << "Array: ";

	for(int x=0; x<length; x++)
	{
		cout << cities[x] << " ";
	}
	
	cout << endl << "Length: " << length << endl; */
	
	//call permute function that starts everything
	permute(cities, 0, length - 1, cost, copy, lowestCost, bestTour);	
	
	//prints out the best tour and cost
	cout << "The tour ";
	for(i=0; i<length; i++)
	{
		cout << bestTour[i] << " ";
	}
	cout << bestTour[0] << " ";
	cout << "costs " << lowestCost[0] << endl;
	
	return 0;
}

/*
Name: getCost
Parameters: the current tour, the costs matrix, the length of the array, the copy of the cities array
Returns: the cost
Description: adds up the cost from the cost matrix and returns it
*/
int getCost(int tour[MAX], int costs[MAX][MAX], int length, int cities[MAX])
{
	int cost = 0, i; // the cost starts at 0, and an iterator
	
	for(i=0; i<length-1; i++)
	{
		//adds the cost between each city in the permuatation
		cost += costs[getPosition(tour[i], cities, length)][getPosition(tour[i+1], cities, length)];
	}

	//adds up the cost from the final element in the cities permutation with the first element, to travel back to where started
	cost += costs[getPosition(tour[length-1], cities, length)][getPosition(tour[0], cities, length)];

	return cost; //returns the cost
}

/*
Name: swap
Parameters: two places in array to swap
Returns: nothing
Description: manipulates part of an array to permute it
*/
void swap(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
	
	return;
}

/*
Name: permute
Paramters: the array of cities that gets manipulated, the start position, the end position, the costs matrix graph, the copy of the
			original cities array that stays the same, the final cost that gets updated to main, and the final tour that gets updated
			to main
Returns: nothing
Description: this permutes the int array by the backtracking method. this is recursive.
*/
void permute(int array[MAX], int start, int end, int costs[MAX][MAX], int copy[MAX], int finalCost[1], int finalTour[MAX])
{
	int i, cost; // iterator, local cost value
	
	if(start == end) //found a permutation
	{
		cost = getCost(array, costs, end+1, copy); //calculate cost for current permuatation
		
		if(finalCost[0] == 0) //cost starts at zero, so make it an actual cost
		{
			finalCost[0] = cost; //update final cost
			
			for(i=0; i<end+1; i++)
			{
				finalTour[i] = array[i]; //update final tour
			}
		}
		else if(cost < finalCost[0]) //if cost is less than the final cost, update the final cost
		{
			finalCost[0] = cost; //update final cost
			
			for(i=0; i<end+1; i++)
			{
				finalTour[i] = array[i]; // update final tour
			}
		}
	}
	else //continue manipulating array
	{
		for(i = start; i <= end; i++)
		{
			swap((array + start), (array + i));
			permute(array, start + 1, end, costs, copy, finalCost, finalTour); //recursive call to self
			swap((array + start), (array + i)); //backtrack
		}
	}
	
	return;
}

/*
Name: getPosition
Parameters: the city number, the array of cities, the length of cities array
Returns: the position in the array for the city
Description: finds the position that the number is in for the array
*/
int getPosition(int input, int array[MAX], int length)
{
	int position, i; //the position in an array, and an iterator
	
	for(i = 0; i < length; i++) //find where a number is in the original cities array
	{
		if(array[i] == input)
		{
			position = i;
			
			return (position);
		}
	}
	
	cout << endl << input << " is not in the cities array" << endl;
	
	return (input-1); //error
}