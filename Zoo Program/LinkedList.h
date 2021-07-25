/************************************************************************************************************************************** 
    Title: LinkedList.h
	Name: Dev Chauhan
    Date: 09/28/2020
***************************************************************************************************************************************/    
#ifndef LinkedList_H
#define LinkedList_H
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

template <typename Creature>
class LinkedList
{
	private:
		struct ListNode
		{
			Creature value;           	
			struct ListNode *next;  	
		}; 
		ListNode *head;		
		ListNode *tail;

		int numNodes;
	public:
		// Constructor
		LinkedList()
		{ 
			head = NULL;
			tail = NULL;
			numNodes = 0; 
		}

		// Destructor 
		~LinkedList();


		Creature getNodeValue(int);
		int getLength();
		void appendNode(Creature);
		void deleteNode(int);
};

template <typename Creature>
int LinkedList<Creature>::getLength()
{
	return numNodes;
}

template <typename Creature>
void LinkedList<Creature>::appendNode(Creature val)
{
	ListNode *newNode;  
	ListNode *nodePtr;

	
	newNode = new ListNode;
	newNode->value = val;
	newNode->next = NULL;
	
	if (!head ) 
	{
		head = newNode;
	}
	else 
	{
		nodePtr = head;
		int numNodes = 0;
		while(nodePtr->next != NULL)
		{
			cout << "- node " << numNodes++;
			nodePtr = nodePtr->next;
		}
		
		nodePtr->next = newNode;

	}
}

template <typename Creature>
Creature LinkedList<Creature>::getNodeValue(int position)
{
	ListNode *nodePtr;
	head !=NULL;

		
	if(position == 0)
	{	
		return head->value;
	}	
	nodePtr = head;
	int currentPos = 0;

	while(nodePtr != NULL && position >= currentPos)
	{
		if(position == currentPos)
		{
			return nodePtr->value;
		}	
		currentPos++;
		nodePtr = nodePtr->next;				
	}
}

template <typename Creature>
void LinkedList<Creature>::deleteNode(int val)
{
	ListNode *nodePtr;      
	ListNode *previousNode;  

	if (!head)
		return;

	if (head->value == val)
	{
		nodePtr = head->next;
		delete head;
		head = nodePtr;
	}
	else
	{
		nodePtr = head;

		while (nodePtr != NULL && nodePtr->value != val)
		{  
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
		}

		if (nodePtr)
		{
			if(nodePtr == tail)
			{
				tail = previousNode;
			}
			previousNode->next = nodePtr->next;
			delete nodePtr;
		}
	}
}

template <typename Creature>
LinkedList<Creature>::~LinkedList()
{
	ListNode *nodePtr;  
	ListNode *nextNode; 

	nodePtr = head;

	while (nodePtr != NULL) 
	{
		nextNode = nodePtr->next;

		delete nodePtr;

		nodePtr = nextNode;
		--numNodes;
	}

}


#endif