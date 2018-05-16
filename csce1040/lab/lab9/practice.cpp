/*
Name: Scarlett Jones (ScarlettJones@my.unt.edu)
Date: 3/31/15
Teacher: Keathly
Description: this is a practice to using C++
*/
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
	int i, j;
	i=1;
	while(i < argc)
	{
		cout << argv[i] 
		<< " ";
		i++;
	}

	cout << endl << "\nHello world!\n" << endl;

	cout << "Input a number." << endl;
	cin >> j;

	cout << j << endl;	

	return 0;
}
