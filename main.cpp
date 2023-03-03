#include <iostream>
#include <vector>
#include "Node.h"
#include "Tree.h"

int main() {
	std::vector<int> nums = { 6, 17, 20, 41, 45, 52, 57, 65, 71, 76, 79, 87, 92, 95, 99 };
	//Create a tree using the vector of numbers
	Tree t = Tree(nums);
	t.inOrder();
	std::cout << "Minimum value: " << t.min()->getData() << std::endl;
	std::cout << "Maximum value: " << t.max()->getData() << std::endl;

	int k = 16;

	std::cout << "Please enter a value for k: ";
	std::cin >> k;
	std::cin.ignore();

	Node* currentSmallest = t.min();

	for (int i = 0; i < k - 1; i++) {
		//Start at the smallest and find the successor k times
		currentSmallest = t.successor(currentSmallest);

	} //end for

	std::cout << "k is: " << k << std::endl;

	if (currentSmallest != NULL) {
		std::cout << "kth smallest element is: " << currentSmallest->getData() << std::endl;
	}
	else {
		std::cout << "k is out of range" << std::endl;
	}
	
	t.invert();
	t.inOrder();
	
}