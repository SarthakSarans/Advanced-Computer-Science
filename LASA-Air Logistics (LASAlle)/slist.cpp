#include "slist.h"
#include <iostream>
#include <fstream>
#include <cmath> 

/*
Class Library File
*/
class Airport {
public:
	char code[5];
	double longitude;
	double latitude;
};

struct Node {
public:
	Airport data;
	struct Node *next;
};

class linked_list {
private:
	Node *head, *tail;

public:
	linked_list() {
		head = NULL;
		tail = NULL;
	}
	void add_node(Airport n) {
		Node *temp = new Node;
		temp->data = n;
		temp->next = NULL;

		if (head == NULL) {
			head = temp;
			tail = temp;
		} else {
			tail->next = temp;
			tail = tail->next;
		}
	}
	/*void delete_node(linked_list[]* afd){
		delete[] afd;
	}*/
	Node* getNode(int index){
		Node* location = head;
		for(int i = 0; i <= index; i++){
			if(i == index){
				return location;
			}
			location = location-> next;
		}
		return location;
	}
	void swapNode(int index1, int index2){
		Node* a = getNode(index1);
		Node* b = getNode(index2);
		Airport tmp;

		tmp=a->data;
		a->data=b->data;
		b->data=tmp;
		
	}
};

// Constructor

// Destructor

// add(value)				//Adds a new value to the end of this list.

// clear()					//Removes all elements from this list.

// equals(list)				//Returns true if the two lists contain the same elements in the same order.

//get(index)				//Returns the element at the specified index in this list.

//insert(index, value)		//Inserts the element into this list before the specified index.

//exchg(index1, index2)		//Switches the payload data of specified indexex.

//swap(index1,index2)		//Swaps node located at index1 with node at index2

// isEmpty()				//Returns true if this list contains no elements.

// remove(index)			//Removes the element at the specified index from this list.

// set(index, value)		//Replaces the element at the specified index in this list with a new value.

// size()					//Returns the number of elements in this list.

// subList(start, length)	//Returns a new list containing elements from a sub-range of this list.

// toString()				//Converts the list to a printable string representation.