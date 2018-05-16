#include <iostream>
using namespace std;

struct node
{
	int data;
	int itemnumber; 
	node *next;
};

void addNode(node *head, node* tail, int x);

int main()
{
	int i;
	
	node *head = new node;
	node *tail = head;
	node *walk = head;

//	head->next=0;

//	head->data=21;
//	head->itemnumber=0;

//	if(walk != 0)
//	{
//		while(walk->next != 0)
//		{
//			walk = walk->next;
//		}
//	}

//	walk->next = new node;
//	walk = walk->next;
//	walk->next = 0;
//	walk->data = 42;
//	walk->itemnumber = 1;
//	tail = walk;
	
	//cout << "Before" <<endl;
	
	addNode(head, tail, 30);
	addNode(head, tail, 21);
	addNode(head, tail, 6);

	cout << "head: " << head->data << endl;

	walk = head;
	while(walk != NULL)
	{
		cout << walk->data << endl;
		cout << "itemnumber: " << walk->itemnumber << endl;
		walk = walk->next;
	}

	return 0;
}


void addNode(node *head, node* tail, int x)
{
//	node *newNode = new node;
	node *walk = head;
	node *prev;

	if(head == tail == NULL) //empty list
	{
		node *newNode = new node;
		head = tail = newNode;
		newNode->data = x;
		newNode->itemnumber = 0;
		return;
	}
	else if(head == tail) //one item in list
	{
		node *newNode = new node;
		walk = head;
		walk = walk->next;
		tail = walk;
		tail->data = x;
		tail->itemnumber = 1;
		return;
	}
	
	prev = tail;
	tail->next = new node;
	tail = tail->next;
	tail->data = x;
	tail->itemnumber = prev->itemnumber + 1;

	return;
}
