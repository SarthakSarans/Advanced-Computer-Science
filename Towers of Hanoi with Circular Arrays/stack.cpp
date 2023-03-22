#include "disc.h"
#include "stack.h"
#include <iostream>
#include <math.h>
#include <stdio.h>
using namespace std;

/*
Stack::~Stack()
{
	// delete data;
}
*/
Stack::Stack(int size) {
	tub[size] = new Disc[size];
}

int Stack::inStack(Disc *a[], int b) {
	int count = 0;
	
	int i = 0;
	while (a[i] != NULL) {
		i++;
		count++;
	}

	return count;
}
void Stack::push(void *inData) {
	// your code
	for (int i = inStack(tub, sizeof(tub)); i >= 0; i--) {
		tub[i + 1] = tub[i];
	}
	tub[0] = (Disc*)inData;
}
void *Stack::pop() {
	// your code
	Disc *a = tub[0];
	for (int i = 0; i < inStack(tub, sizeof(tub)); i++) {

		tub[i] = tub[i + 1];
	}
	
	return a;
}

void *Stack::top() {
	// your code
	return tub[0];
}
void Stack::clear(){
	Disc *a = new Disc(0);
	for (int i = 0; i < inStack(tub, sizeof(tub)); i++) {

		tub[i] = a;
	}
	}
bool Stack::empty() {
	// your code
	if (tub[0] == NULL)
		return true;
	else
		return false;
}

void Stack::display() {
	// cout<<endl;

	int i = 0;
	while (tub[i] != NULL) {
		cout << ((Disc *)(tub[i]))->toString() << "\t";
		i++;
	}
	cout << endl;
}
