#include <iostream>
using namespace std;

class node
{
	public:
		int x;
		node *next;
};

class set
{
	public:
		node *head;
		
		set() {head = new node;}
		
		addNode(int num)
		{
			node *walk = head;
			if(head == NULL)
			{
				walk->x = num;
				walk = walk->next;
			}
			else
			{
				while(walk != NULL)
				{
					walk = walk->next;
				}
				walk->x = num;
				
			}
		}
};

int main()
{
	set SET;
	int i;
	
	for(i=0; i<160; i++)
	{
		SET.addNode();
	}
	
	
	
	SET.print();
	
	return 0;
}