#include <iostream>
#include <vector>
#include "Tree.h"
#include "Node.h"

Tree::Tree() {

} //end null parameter constructor


Tree::Tree(Node* top) {

	this->root = top;

}


Tree::Tree(std::vector<int> nums) {

	this->root = new Node();
	this->root->setParent(NULL);
	this->root->build(nums);

} //end constructor


Tree::~Tree() {

	if (this->root->getParent() == NULL) {
		this->root->wipe();
		delete root;
	}

} //end destructor


Node* Tree::min() {

	//Follow all left branches
	Node* temp = root;
	while (temp->getLeft() != NULL) {
		temp = temp->getLeft();
	}
	return temp;

} //end min


Node* Tree::max() {

	//Follow all right branches
	Node* temp = root;
	while (temp->getRight() != NULL) {
		temp = temp->getRight();
	}
	return temp;

} //end max



void Tree::inOrder() {

	root->inOrder();
	std::cout << std::endl;

} //end inOrder


Node* Tree::successor(Node* primary) {

	if (primary->getRight() != NULL) { //If the node has a right child, the successor is the min of that subtree
		Tree next = Tree(primary->getRight());
		return next.min();
	}
	else {

		bool keepGoing = true;
		Node* temp = primary;
		while (keepGoing) {

			if (temp->getParent() == NULL) { //If we made it back to the root before finding a successor, we were given the largest element and there is no successor
				return NULL;
			} 
			else if (temp == temp->getParent()->getLeft()) { //If the current node is a left child, the parent is the successor
				temp = temp->getParent();
				keepGoing = false;
				return temp;
			}
			else { //Current node is a right child, keep climbing tree
				temp = temp->getParent();
			}

		}

	}

	return NULL;
} //end successor


void Tree::invert() {

	this->root->invert();

} //end invert