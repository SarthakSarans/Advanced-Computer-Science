#include<stdio.h>
#include<iostream>
#include<math.h>
#include "stack.h"
#include "disc.h"
using namespace std;

Stack::Stack()
{
Node *first = new Node();
first -> data = new Disc();
pTop = first;
	
}
/*
Stack::~Stack()
{
	// delete data;
}
*/

void Stack::push(void* inData)
{
	Node* added = new Node();
	added -> data = pTop -> data;
	added -> pNext = pTop -> pNext;
	pTop -> data = inData;
	pTop -> pNext = added;
	
	// your code
}
void* Stack::pop()
{
	if (pTop == NULL)
		return NULL;
	// your code
	Node* tmp = new Node();
	tmp  = pTop -> pNext;
	Node* tmp2 = new Node();
	tmp2->data = pTop->data;
	tmp2->pNext = pTop->pNext;

	pTop = tmp;
	return tmp2->data;
	

}

void* Stack::top()
{
	// your code
	return pTop;
}

bool Stack::empty()
{
	// your code
	if(pTop == NULL)
		return true;
	else 
		return false;
}

void Stack::display()
{
	//cout<<endl;
	Node *p1;
	p1 = pTop;
	while (p1 != NULL)
	{
		cout<< ((Disc*)(p1->data))->toString()<<"\t";
		p1 = p1->pNext;
	}
	cout<<endl;
}

