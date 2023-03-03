#ifndef NODE_H_EXISTS
#define NODE_H_EXISTS

#include<iostream>
#include<vector>

class Node {

	private:
		int data;
		Node* parent;
		Node* left;
		Node* right;

	public:
		Node();
		Node(int num);
		int getData();
		void setData(int num);
		Node* getParent();
		void setParent(Node* newParent);
		Node* getLeft();
		void setLeft(Node* newLeft);
		Node* getRight();
		void setRight(Node* newRight);
		void inOrder();
		void build(std::vector<int> nums);
		void wipe();
		void invert();

};

#endif