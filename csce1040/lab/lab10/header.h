/*
Name: Scarlett Jones (ScarlettJones@my.unt.edu)
Teacher: Keathly
Date: 4/7/15
Description: header file with function prototypes and a class
*/

//class called Bank with array of ten accounts from 0 to 9
class Bank
{
	private:
	  int account[10];
	public:
	  Bank(); // constructor
	  //function prototypes
	  void deposit(int num, int value);
	  void withdraw(int num, int value);
	  void balance(int num);
	  void transfer(int num1, int num2, int value);
};







