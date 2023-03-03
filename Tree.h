#ifndef TREE_H_EXISTS
#define TREE_H_EXISTS

#include<iostream>
#include<vector>
#include "Node.h"

class Tree {

	private:
		Node* root;

	public:
		Tree();
		Tree(Node* top);
		Tree(std::vector<int> nums);
		~Tree();
		Node* min();
		Node* max();
		void inOrder();
		Node* successor(Node* primary);
		void invert();

};

#endif