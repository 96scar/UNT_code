// Modified by Scarlett Jones
// file: rpnCalculator.cpp
// Simple RPN Calculator
// This is an in-lab exercise and was incomplete

#include <iostream>    // used in main()
#include <vector>
#include <stack>
#include <cstdio> // needed to use EOF
using namespace std;

int main()

   // Simple interactive RPN calculator
   // Library facilities used: cin, cout, peek(), ignore() from stream.h
   //                          vector, stack, push(), top(), pop() from the STL
{
   stack<double> operands;
   stack<double> temp;
  

   double nextNumber;
   char   nextOperation;

   double operand1;
   double operand2;

   cout << "Type \"q\" when you are done\n";

   while ( cin && cin.peek() != EOF )
   {
      char ch = cin.peek();

      switch ( ch )
      {
        // digit or decimal point
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
        case '.':
         cin >> nextNumber;
         operands.push( nextNumber );
         break;

        // arithmetic operation
        case '+':
        case '-':
        case '*':
        case '/':
         cin >> nextOperation;

         // handle unary minus
         if ( ( cin.peek() >= '0' && cin.peek() <= '9' ) || cin.peek() == '.' )
         {
            cin >>nextNumber;
            operands.push( -nextNumber );
	    break;
         }

         // do binary operation
         if ( operands.size() < 2 )
         {
            cout << "Not enough operands for " << nextOperation << "\n";
         }
         else
         {
            operand2 = operands.top();
            operands.pop();
            operand1 = operands.top();
            operands.pop();

            switch ( nextOperation )
            {
              case '+':
               operands.push( operand1 + operand2 );
               break;
              case '-':
               operands.push( operand1 - operand2 );
               break;
		case '*':
		 operands.push( operand1 * operand2);
		 break;
		case '/':
		 operands.push( operand1 / operand2);
		 break;
            }

            cout << "-----\n";
            cout << operands.top() << "\n\n";
         }

         break;

        // display stack operation
        case ':':
	  cout << "Size is: " << operands.size() << endl;
	  int size = operands.size();
	  int arr[3]; // was getting a segmentation fault the other way, so i hardcoded 3 in
	  temp = operands; // copies operands to temp

	  for(int i = operands.size() - 1; i >= 0 ; i--) // copies temp into array in order
	  {
		arr[i] = temp.top();
		temp.pop();
	  }
	  for(int i = 0; i < operands.size(); i++) // prints out array in order
	  {
		cout << endl << "Operand : " << arr[i] << endl;
	  }
	 

        // ignore other characters
        default:
         cin.ignore();
         break;
      }

      if (ch == 'q')
         break;
   }

   // report errors
   if ( operands.size() > 1 )
   {
      cout << "Left over operands in the stack\n";
      return -1;
   }

   return 0;    // normal exit code
}
