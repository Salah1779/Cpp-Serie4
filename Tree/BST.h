#pragma once
#include "Node.h"
#include <queue>
#include <iostream>

template <class MyType>
class BST
{
private:
    Node<MyType>* root;

public:
    BST(const MyType& rootVal);
    void addElement(const MyType ne, Node<MyType>* node = nullptr);
    bool searchElement(const MyType se, Node<MyType>* node = nullptr) const;
    bool isEmpty() const;
    void display(const Node<MyType>* root) const;
    void BFSdisplay() const;
    Node<MyType>* getRoot() const;
};

template<class MyType>
BST<MyType>::BST(const MyType& rootVal) : root(new Node<MyType>(rootVal)) {}

template<class MyType>
void BST<MyType>::addElement(const MyType ne, Node<MyType>* node)
{
    if (isEmpty()) {
        root = new Node<MyType>(ne);
        return;
    }

    if (!node) node = root; // Start from root if node is nullptr

    if (ne < node->getVal()) {
        if (node->getLeft() == nullptr)
            node->setLeft(new Node<MyType>(ne));
        else
            addElement(ne, node->getLeft());
    }
    else {
        if (node->getRight() == nullptr)
            node->setRight(new Node<MyType>(ne));
        else
            addElement(ne, node->getRight());
    }
}

template<class MyType>
bool BST<MyType>::searchElement(const MyType se, Node<MyType>* node) const
{
    if (isEmpty()) return false;

    if (!node) node = root; // Start from root if node is nullptr

    if (node->getVal() == se) return true;

    if (se < node->getVal())
        return (node->getLeft() != nullptr) && searchElement(se, node->getLeft());
    else
        return (node->getRight() != nullptr) && searchElement(se, node->getRight());
}

template<class MyType>
bool BST<MyType>::isEmpty() const
{
    return root == nullptr;
}

template<class MyType>
void BST<MyType>::display(const Node<MyType>* node) const
{
    if (node == nullptr) return;
    display(node->getLeft());
    std::cout << node->getVal() << " ";
    display(node->getRight());
}

//Method to traverse the tree in breadth
template<class MyType>
void BST<MyType>::BFSdisplay() const
{
    // Check if the tree is empty
    if (isEmpty()) { 
        std::cout << "Tree is empty." << std::endl;
        return; // Exit if the tree has no nodes.
    }

    // Create a queue to hold nodes to process
    std::queue<Node<MyType>*> nodeQueue; // A queue is used for Breadth-First Search (BFS) traversal.
    
    // Start with the root node
    nodeQueue.push(root); // **Visited:** Root node is added to the queue. 

    // Continue until all nodes are processed
    while (!nodeQueue.empty()) { // Checking if there are still nodes to process.
        // Get the current node at the front of the queue
        Node<MyType>* currentNode = nodeQueue.front(); // **Processing:** The current node is taken for processing.
        nodeQueue.pop(); // Remove the current node from the queue.

        // Display the value of the current node
        std::cout << currentNode->getVal() << " ";

        // Check and enqueue the left child if it exists
        if (currentNode->getLeft() != nullptr) { 
            nodeQueue.push(currentNode->getLeft()); // **Visited:** Left child node is added to the queue for future processing. 
        }

        // Check and enqueue the right child if it exists
        if (currentNode->getRight() != nullptr) { 
            nodeQueue.push(currentNode->getRight()); // **Visited:** Right child is added to the queue for future processing.
        }

         // **Processed:** the current node is processed.
    }

    
    std::cout << std::endl; // **Processed:** All nodes have been processed and displayed.
}

template<class MyType>
Node<MyType>* BST<MyType>::getRoot() const
{
    return root;
}
