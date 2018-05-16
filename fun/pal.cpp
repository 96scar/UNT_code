#include <iostream>
#include <stdlib.h>
using namespace std;

int main(int argc, char *argv[])
{
	int i, j;

	for(i=0, j=argc-1; i<argc, j>=0; i++, j--)
	{
		if(argv[1][i] != argv[1][j])
		{
			cout << "not a palindrome" << endl;
			exit(1);
		}
		else
		{
			cout << "i: " << i << " j: " << j << endl;
		}
	}
	
	cout << "palindrome" << endl;
	
	return 0;
}
