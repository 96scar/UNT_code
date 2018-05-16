#include <iostream>
using namespace std;

int main()
{
	int i, x, y;
	for(i=1; i<=100; i++)
	{
		x = i%3;
		y = i%5;
		
		if((x!=0)&&(y!=0))
			cout << i;
		else
		{
			if(x==0)
				cout << "Fore";
			
			if(y==0)
				cout << "Scout";
		}
		cout << endl;
	}	

	return 0;
}
