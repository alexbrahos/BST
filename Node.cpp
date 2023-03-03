#include <iostream>
#include <vector>
#include "Node.h"

Node::Node() {
	this->data = 0;
	this->parent = NULL;
	this->left = NULL;
	this->right = NULL;
} //end null parameter constructor


Node::Node(int num) {
	this->data = num;
	this->parent = NULL;
	this->left = NULL;
	this->right = NULL;
} //end constructor


int Node::getData() {

	return this->data;

} //end getData


void Node::setData(int num) {

	//no type correction, just assime it is an int
	this->data = num;

} //end setData


Node* Node::getParent() {

	return this->parent;

} //end getParent


void Node::setParent(Node* newParent) {
	
	this->parent = newParent;

} //end setparent


Node* Node::getLeft() {

	return this->left;

} //end getLeft


void Node::setLeft(Node* newLeft) {

	this->left = newLeft;

} //end setLeft


Node* Node::getRight() {

	return this->right;

} //end getRight


void Node::setRight(Node* newRight) {

	this->right = newRight;

} //end setRight


void Node::inOrder() {

	//Recursive, print inOrder for left, then print self, then inOrder for right
	if (this->left != NULL) {
		this->left->inOrder();
	}

	std::cout << this->data << ", ";

	if (this->right != NULL) {
		this->right->inOrder();
	}

} //end inOrder


void Node::build(std::vector<int> nums) {

	//Middle value in array is the data
	this->data = nums[nums.size() / 2];

	//make left
	
	//Use the left half of the array to build the left half of the tree
	std::vector<int> passThruLeft;
	for (int i = 0; i < (nums.size() / 2);i++) {

		passThruLeft.push_back(nums[i]);

	}

	//If there is nothing to pass, we are at a leaf
	if (passThruLeft.size() == 0) {
		this->setLeft(NULL);
	}
	else { //else, make the child
		this->left = new Node();
		this->left->setParent(this);
		this->left->build(passThruLeft);
	}

	//make right

	//Use the right half of the vector to build the right half of the tree
	std::vector<int> passThruRight;
	for (int i = (nums.size() / 2) + 1;i < nums.size();i++) {

		passThruRight.push_back(nums[i]);

	}

	//If there is nothing to pass, we are at a leaf
	if (passThruRight.size() == 0) {
		this->setRight(NULL);
	}
	else { //else, make the child
		this->right = new Node();
		this->right->setParent(this);
		this->right->build(passThruRight);
	}
	

} //end build


void Node::wipe() {

	//Same as inOrder printing, just with deletion
	if (this->left != NULL) {

		this->left->wipe();
		delete this->left;

	}
	
	if (this->right != NULL) {

		this->right->wipe();
		delete this->right;

	}



} //end wipe


void Node::invert() {

	if (this->left != NULL) {

		this->left->invert();

	}

	if (this->right != NULL) {

		this->right->invert();

	}

	Node* temp = this->left;
	this->left = this->right;
	this->right = temp;

} //end invert