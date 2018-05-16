#include <iostream>

using namespace std;

static void N(int &x);

int main()
{
	int num=123;
	N(&123);
	
	return 0;
}

static void N(int &x)
{
	
	return;
}