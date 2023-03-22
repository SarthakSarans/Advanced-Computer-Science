
#include "disc.h"
#include "stack.h"
#include <iostream>
#include <math.h>
#include <stdio.h>

using namespace std;
static int count = 0;
void moveDiscs(int n, Stack *t1, Stack *t2, Stack *t3);
void toh(int n) {
	int i, x;
	Disc *a;
	Disc *b;
	Stack *t1 = new Stack(n);
	Stack *t2 = new Stack(n);
	Stack *t3 = new Stack(n);
t3->clear();
	t2->clear();
	t1->clear();
	for (i = n; i >= 1; i--) {
		// d.setSize(i);
		Disc *d = new Disc(i);
		t1->push(d);
	}
t3->clear();
	t2->clear();
	cout << "=========================================================="<< endl;
	cout << "first" << endl;
	t1->display();
	cout << "second" << endl;
	t2->display();
	cout << "third" << endl;
	t3->display();
	cout << "=========================================================="<< endl;
	// ****  Your Tower of Hanoi solution!
	moveDiscs(n, t1, t2, t3);
	cout << "=========================================================="
		 << endl;
	cout << "first" << endl;
	t1->display();
	cout << "second" << endl;
	t2->display();
	cout << "third" << endl;
	t3->display();
	cout << "=========================================================="
		 << endl;
	cout << "moves " << count << endl;
}

void moveDiscs(int n, Stack *t1, Stack *t2, Stack *t3) {
	if (n == 1) {
		t2->push((Disc *)t1->pop());
		count++;
	} else {
		count++;
		moveDiscs(n - 1, t1, t3, t2);
		cout << "=========================================================="<< endl;
		cout << "first" << endl;
		t1->display();
		cout << "second" << endl;
		t2->display();
		cout << "third" << endl;
		t3->display();
		cout << "=========================================================="<< endl;
		t2->push((Disc *)t1->pop());
		moveDiscs(n - 1, t3, t2, t1);
	}
}
int main() {
	int n;
	cout << "enter the number of disks ";
	cin >> n;
	toh(n);
	return 0;
}
