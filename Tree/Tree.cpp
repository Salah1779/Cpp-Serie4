// Tree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "BST.h"
#include "AVLTree.h"

int main()
{
	BST<int> Tree(10);

	Tree.addElement(2, nullptr);
	Tree.addElement(12, nullptr);
	Tree.addElement(4, nullptr);
	Tree.addElement(2, nullptr);
	Tree.addElement(34, nullptr);
	Tree.addElement(3, nullptr);


	std::cout<<"BFS traversal of tree: "<<std::endl;
	Tree.BFSdisplay();
	std::cout << std::endl;
	
	std::cout << "In-order traversal of BStree: " << std::endl;
	Tree.display(Tree.getRoot());
	std::cout << std::endl;

int se=3;
std::cout << "Searching for " << se << " ..." << std::endl;
	if(Tree.searchElement(3, Tree.getRoot()))
		std::cout << se << " Found" << std::endl;
	else
		std::cout << se << " Not Found" << std::endl;

	std::cout << "----------------------------------------" << std::endl;


	AVLTree<int> Tree2(4);
	Tree2.addElement(2);
	Tree2.addElement(3);
	Tree2.addElement(1);
	Tree2.addElement(5);
	Tree2.addElement(6);
	Tree2.addElement(7);

	std::cout << "BFS traversal of AVLtree: " << std::endl;
	Tree2.BFSdisplay();
	std::cout << std::endl;

	se = 10;
	std::cout << "Searching for " << se << " ..." << std::endl;
	if (Tree2.searchElement(se, Tree2.getRoot()))
		std::cout << se << " Found" << std::endl;
	else
		std::cout << se << " Not Found" << std::endl;



}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
