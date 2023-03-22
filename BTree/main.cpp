#include <iostream>

#define MIN_DEGREE 3

struct node {
	int n;
	bool leaf;
	int k[2 * MIN_DEGREE - 1];
	node *c[2 * MIN_DEGREE];
};
node *ALLOCATE_NODE() {
	node *aNode = new node();
	aNode->leaf = false;
	aNode->n = 0;
	for (int i = 0; i < 2 * MIN_DEGREE; i++) {
		aNode->c[i] = NULL;
	}
	return aNode;
}

void B_TREE_SPLIT_CHILD(node *node1, int index, node *node2) {
	node *y = node2;
	node *x = node1;
	int t = MIN_DEGREE;
	node *z = ALLOCATE_NODE();

	z->leaf = y->leaf;
	z->n = t - 1;
	for (int i = 0; i < t - 1; i++) {
		z->k[i] = y->k[i + t];
	}
	if (!y->leaf) {
		for (int i = 0; i < t; i++) {
			z->c[i] = y->c[i + t];
		}
	}
	y->n = t - 1;
	for (int i = x->n - 1; i >= index + 1; i--) {
		x->c[i + 1] = x->c[i];
	}
	x->c[index + 1] = z;
	for (int i = x->n - 1; i >= index; i--) {
		x->k[i + 1] = x->k[i];
	}
	x->k[index] = y->k[t - 1];
	x->n = x->n + 1;

	//
	//    >>>>   YOUR CODE GOES HERE    <<<<
	//
}

void displayNode(node *aNode) {
	std::cout << "leaf: " << aNode->leaf << std::endl;
	std::cout << "keys";
	for (int i = 0; i < aNode->n; i++) {
		std::cout << ", " << aNode->k[i];
	}
	std::cout << std::endl;
	if (aNode->leaf) {
		std::cout << "Pointers : ";
		for (int i = 0; i < aNode->n + 1; i++) {
			if (aNode->c[i] == NULL) {
				std::cout << "[" << i << "] = NULL, ";
			} else {
				std::cout << "[" << i << "] = CHILD, ";
				// std::cout << "[" << i << "] = " << aNode->c[i] << ", ";
			}
		}
		std::cout << std::endl;
	}
}

int main() {
	node *node1 = ALLOCATE_NODE();
	node *node2 = ALLOCATE_NODE();
	int index = 0;
	int inCount = 0;
	std::cout << "Hello B-TREE assignment!\n";
	std::cout << "How many keys for node 1?\n";
	std::cin >> inCount;
	node1->leaf = true;
	node1->n = inCount;
	for (int i = 0; i < inCount; i++) {
		std::cout << "Enter key " << i << " ";
		std::cin >> node1->k[i];
	}

	std::cout << "How many keys for node 2?\n";
	std::cin >> inCount;
	node2->leaf = false;
	node2->n = inCount;
	for (int i = 0; i < inCount; i++) {
		std::cout << "Enter key " << i << " ";
		std::cin >> node2->k[i];
	}
	for (int i = 0; i < 2 * MIN_DEGREE; i++) {
		node2->c[i] = NULL;
	}
	index = 0;
	for (index = 0; index < node1->n; index++) {
		if (node1->k[index] > node2->k[0]) {
			node1->c[index] = node2;
			break;
		}
	}
	// if index == count then node2 keys are greater than all in node1
	if (index == node1->n) {
		node1->c[index] = node2;
	}

	B_TREE_SPLIT_CHILD(node1, index, node2);
	std::cout << std::endl;
	std::cout << "Contents of node 1 :" << std::endl;
	displayNode(node1);

	for (int i = 0; i < node1->n + 1; i++) {
		if (node1->c[i]) {
			std::cout << "Contents of child " << i << " :" << std::endl;
			displayNode(node1->c[i]);
		}
	}
}
