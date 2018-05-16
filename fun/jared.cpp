#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>

using namespace std;

int main()
{
	string first, last, temp;
	int i=0;
	double salary=0, total=0, average=0, people=0;
	char *token;
	ifstream in;
	in.open("file.txt");
	
	
	while(getline(in, temp))
	{

		token=strtok((char *)temp.c_str(), " ");

		i=0;
		while(token!=NULL)
		{
			if(i==0)
			{
				first = token;
			}
			else if(i==1)
			{
				last = token;
			}
			else if(i==2)
			{
				salary = atof(token);
			}
			token=strtok(NULL, " ");
			i++;
		}
		
		cout << right << setw(20) << last << ", " << right << setw(15) << first << ":" << right  << setw(10) << setprecision(2) << fixed  << salary << endl;
		total+=salary;
		people++;
	}
	average=total/people;
	cout << "Average="  <<setprecision(2) << fixed <<  average  << endl;
	
	return 0;
}