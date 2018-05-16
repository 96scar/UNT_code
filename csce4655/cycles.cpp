#include <iostream>
#include <stdlib.h>
#include <fstream>
using namespace std;

int main(int argc, char *argv[])
{
	string line, command, source1, source2, destination;
	int i=1;
	
	if(argc != 2)
	{
		cout << "usage: ./cycles [filename]" << endl;
		exit(1);
	}

	ifstream input;
	input.open(argv[1]);
	while(getline(input, line))
	{
		cout << i << ": " << line << endl;
		command = line.at(0);
		i++;
	}

	input.close();	

	return 0;
}
