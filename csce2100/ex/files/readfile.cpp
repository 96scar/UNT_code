#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main()
{
	std::string line_;
	ifstream file_("mytext.txt");
	file_.open("mytext.txt", ifstream::in);
	if(file_.is_open())
	{
		while(file_.good())
		{
			//file_.getline(my, 256, ',');
		}
		/*while(getline(file_, line_))
		{
			std::cout << line_ << "\n";
		}
		*/
		file_.close();
	}
	else
	{
		std::cout << "File is not open." << "\n";
	}
	std::cin.get();
	
	return 0;
}