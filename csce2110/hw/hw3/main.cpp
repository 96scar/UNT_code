/*
Scarlett Jones
CSCE 2110
Program 3
4/29/16
*/

//main

#include "class.h"

int main()
{
	string str;
	char type;
	int crews, val, i;
	
	cout << "before while" << endl;
	i=0;
	while(getline(cin, str))
	{
		cout << "in while " << i << "th time" << endl;
		i++;
		int spacePos1 = str.find(' '); //finds 1st space
		string arg1 = str.substr(0, spacePos1); //from start to 1st space
		string str2 = str.substr(spacePos1 + 1); //from 1st space to end
		
		type = arg1.at(0); // is it an a or a c or a number?
		if(type == 'a') // arc
		{
			int spacePos2 = str2.find(' '); //finds 2nd space
			string arg2 = str2.substr(0, spacePos2); //from 1st space to 2nd space
			string str3 = str2.substr(spacePos2 + 1); //from 2nd space to end
			int spacePos3 = str3.find(' '); //find 3rd space
			string arg3 = str3.substr(0, spacePos3); //from 2nd space to 3rd space
			string arg4 = str3.substr(spacePos3 + 1); //from 3rd space to end
			
			// arg2 = predecessor
			// arg3 = successor
			// arg4 = #
			
			cout << "predecesor " << arg2 << " added" << endl;
			cout << "successor " << arg3 << " added" << endl;
			cout << "# " << arg4 << " added" << endl;
		}
		else if(type == 'c') // create
		{
			string arg2 = str2;
			
			val = atoi(arg2.c_str()); //convert arg2 to int
			// add a node
			// val = #
			cout << "node " << val << " added" << endl;
		}
		else // number of crews
		{
			crews = atoi(str.c_str());
			// crews = crews
			cout << crews << " crews" << endl;
		}
	}
	// done parsing the data and building the DAG
	// determine critical path length
	// determine nodes on critical path
	// determine schedule
	
	//print out the output
	cout << "The critical path length is " << endl;
	cout << "The nodes on a critical path are: {" << "}" << endl;
	
	cout << "Time Slice Number" << endl; //time slice goes from 0 to the critical path length
	
	for(i = 1; i <= crews; i++)
	{
		//cout << "Time Slice Number" << endl;
		cout << "Crew " << i << "'s tasks" << endl;
	}
	
	
	return 0;
}