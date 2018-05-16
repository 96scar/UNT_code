#include <iostream>
using namespace std;
int main()
{
	int n, i;
	float input, low, high, sum, mean, ncon, range;
	low = 0;
	high = 0;
	sum = 0;
	cout << "Input how many numbers you want to take the mean and range of: ";
	cin >> n;
	for(i=0; i<n; i++)
	{
		cout << "Enter a floating point number: ";
		cin >> input;
		if(input < low)
			low = input;
		else if(low == 0)
			low = input;
		if(input > high)
			high = input;
		sum += input;
	}
	ncon = (float)n;
	mean = sum/ncon;
	range = high - low;
	cout << "Mean: " << mean << endl;
	cout << "Range: " << low << " to " << high << endl;
	cout << "Range: " << range << endl;
	return 0;
}