#include <iostream>
using namespace std;
int main()
{
	int x, y, product, quotient, remainder;
	cout << "Enter value x: ";
	cin >> x;
	cout << "Enter value y: ";
	cin >> y;
	product = x*y;
	cout << "Product = " << product << endl;
	quotient = x/y;
	cout << "Quotient = " << quotient << endl;
	remainder = x - quotient*y;
	cout << "Remainder = " << remainder << endl;
	return 0;
}