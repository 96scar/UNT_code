#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	ofstream file_("mytext.txt");
	//file_.open("mytext.txt");
	if(file_.is_open())
	{
	
	file_ << "Scarlett, Joe, Gxara, Ethan\n";
	}
	file_.close();
	std:cin.get();
	
	return 0;
}