#include <iostream>
using namespace std;

int main()
{
	int base1, base2, start;

	cout << endl << "This will convert any number base to any other number base." << endl;
	cout << endl << "Starting Base: ";
	cin >> base1;
	cout << "Ending Base: ";
	cin >> base2;
	cout << "Number: ";
	cin >> start;
	cout << endl << "Converting " << start << " from base " << base1 << " to base " << base2 << endl << endl;

	int quotient, divisor, dividend, remainder;
	
	dividend = start;
	divisor = base2;
	quotient = 1;
	remainder = 1;
	
	/* Count how many digits there are. 
		Check to see if we are converting to binary or decimal.
		Converting from binary to any other base involves multiplying
		each digit by the base you want to convert to, which is raised
		to the power of the position on the number. Then add these together.
		Converting from decimal to any other base requires dividing 
		the whole number by the base, finding the remainder, and 
		continuing until the quotient is zero. Then we read the remainders
		in order from bottom to top.
		Hexadecimal has a few special rules.*/
	
	
	
	switch(base1)
	{
		case 2: //binary
		if(base2 == 16)
		{
			//do something special
		}
		else if(base2 == (2 || 8 || 10))
		{
			
		}
		else
		{
			//unexpected
		}
		break;
		case 8: //octal
		break;
		case 10: //decimal
		if(base2 == 2 || 8)
		{
			quotient = 1;
			while(quotient != 0)
			{
				quotient = dividend/divisor;
				remainder = dividend - quotient*divisor;
				cout << dividend << "/" << divisor << "=" << quotient << " REMAINDER " << remainder << endl;
				dividend = quotient;
				cout << "New dividend: " << dividend << endl;
			}
		}
		else if(base2 == 16)
		{
			quotient = 1;
			while(quotient != 0)
			{
				quotient = dividend/divisor;
				remainder = dividend - quotient*divisor;
				
					switch(remainder)
					{
						case 10: remainder = (int)"A";
						cout << remainder;
						break;
						case 11: remainder = (int)"B";
						break;
						case 12: remainder = (int)"C";
						break;
						case 13: remainder = (int)"D";
						break;
						case 14: remainder = (int)"E";
						break;
						case 15: remainder = (int)"F";
						break;
						default: //none?
						break;
					}
				
				cout << dividend << "/" << divisor << "=" << quotient << " REMAINDER " << remainder << endl;
				dividend = quotient;
				cout << "New dividend: " << dividend << endl;
			}
		}
		else
		{
			//unexpected
		}
		break;
		case 16: //hexadecimal
		break;
		default: //not an expected base
		break;
	}

	return 0;
}

