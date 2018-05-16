#include <iostream>
using namespace std;
int main()
{
	int input, remain, times, div;
	//float con, div;
	cout << "Enter an integer: ";
	cin >> input;
	//con = (float)input;
	div = input/2;
	cout << "div: " << div << endl;
	times = div*2;
	cout << "times: " << times << endl;
	remain = input - times;
	cout << "remain: " << remain << endl;
	if(remain == 0)//even
		cout << "Even" << endl;
	else
		cout << "Odd" << endl;
	return 0;
}