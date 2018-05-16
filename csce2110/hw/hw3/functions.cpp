/*
Scarlett Jones
CSCE 2110
Program 3
4/29/16
*/

//define functions

#include "class.h"

DAGNode::DAGNode()
{
/*	pre_count = 0;
	suc_count =0;
	pre_top = pre_bottom = NULL;
	suc_top = suc_bottom = NULL;*/
}

DAGNode::~DAGNode()
{
/*	if(pre_top ==NULL)
	{
		return;
	}
	else
	{
		DAGNode *pre_now = pre_top;
		while(pre_now != pre_bottom)
		{
			DAGNode *pre_next = pre_now->getNextPre();
			delete pre_now;
			pre_now = pre_next;
		}
	}
	
	if(suc_top ==NULL)
	{
		return;
	}
	else
	{
		DAGNode *suc_now = suc_top;
		while(suc_now != suc_bottom)
		{
			DAGNode *suc_next = suc_now->getNextSuc();
			delete suc_now;
			suc_now = suc_next;
		}
	} */
}

int DAGNode::setWeight(int w) {weight = w;} // set weight
void DAGNode::setNext(DAGNode *n) {next = n;}
//void DAGNode::setNextPre(int *n) {pre_next = n;}
//void DAGNode::setNextSuc(int *n) {suc_next = n;}

//void DAGNode::getPredecessors() {return;} // get predecessors
//void DAGNode::getSuccessors() {return;} // get successors
int DAGNode::getWeight() {return weight;} // get weight

void DAGNode::addPredecessor() {return;} // add predecessor
void DAGNode::addSuccessor() {return;} // add successor

DAG::DAG() // constructor
{
	node_count = 0;
	top = bottom = NULL;
}

DAG::~DAG() // desconstructor
{
	if(top ==NULL)
	{
		return;
	}
	else
	{
		DAGNode *now = top;
		while(now != bottom)
		{
			DAGNode *next = now->getNext();
			delete now;
			now = next;
		}
	}
}

void DAG::addNode()
{
	DAGNode *temp;
	
	temp = new DAGNode();
	if(node_count == 0)
	{
		top = bottom = temp;
		temp->setNext(NULL);
		node_count++;
	}
	else
	{
		bottom->setNext(temp);
		bottom = temp;
		temp->setNext(NULL);
		node_count++;
	}
	
}