#ifndef _Stack_H_
#define _Stack_H_
#include "disc.h"

#include <iostream>
#include <math.h>
#include <stdio.h>

class Stack {
	

	
	 Disc *tub[1];

public:
					 // Construct stack
	void push(void *inData); // Add element to top of stack
	void *pop(); // Return element at top of stack and remove from top
	void *top(); // Return element at top of stack
	bool empty();
	void display();
	Stack(int size);
void clear();
	int inStack(Disc *a[], int b);
};

#endif //_Stack_H_
