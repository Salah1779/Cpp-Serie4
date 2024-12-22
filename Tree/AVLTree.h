// AVLTree.h
#pragma once
#pragma once
#include "Node.h"
#include <iostream>
#include <queue>
#include <algorithm> 

template <class MyType>
class AVLTree {
private:
    Node<MyType>* root;

    // Helper functions
    int height(Node<MyType>* node) const;
    int getBalanceFactor(Node<MyType>* node) const;
    Node<MyType>* leftRotate(Node<MyType>* x);
    Node<MyType>* rightRotate(Node<MyType>* y);
    Node<MyType>* balance(Node<MyType>* node);
    Node<MyType>* addElementRecursive(Node<MyType>* node, const MyType& value);
    void updateHeight(Node<MyType>* node);

public:
    AVLTree() : root(nullptr) {}
    explicit AVLTree(const MyType& rootValue) : root(new Node<MyType>(rootValue)) {}
    void addElement(const MyType& value);
    bool searchElement(const MyType& value, Node<MyType>* node = nullptr) const;
    bool isEmpty() const;
    void display(Node<MyType>* node = nullptr) const;
    void BFSdisplay() const;
    Node<MyType>* getRoot() const;
};

template <class MyType>
void AVLTree<MyType>::updateHeight(Node<MyType>* node) {
    if (node != nullptr) {
        node->setHeight(1 + std::max(height(node->getLeft()), height(node->getRight())));
    }
}

template <class MyType>
int AVLTree<MyType>::height(Node<MyType>* node) const {
    if (node == nullptr) return 0;
    return node->getHeight();
}

template <class MyType>
int AVLTree<MyType>::getBalanceFactor(Node<MyType>* node) const {
    if (node == nullptr) return 0;
    return height(node->getLeft()) - height(node->getRight());
}

template <class MyType>
Node<MyType>* AVLTree<MyType>::leftRotate(Node<MyType>* x) {
    if (x == nullptr || x->getRight() == nullptr) return x;

    Node<MyType>* y = x->getRight();
    Node<MyType>* T2 = y->getLeft();

    y->setLeft(x);
    x->setRight(T2);

    // Update heights in correct order (bottom-up)
    updateHeight(x);  // Update x first as it's now lower
    updateHeight(y);  // Then update y

    return y;
}

template <class MyType>
Node<MyType>* AVLTree<MyType>::rightRotate(Node<MyType>* y) {
    if (y == nullptr || y->getLeft() == nullptr) return y;

    Node<MyType>* x = y->getLeft();
    Node<MyType>* T2 = x->getRight();

    x->setRight(y);
    y->setLeft(T2);

    // Update heights in correct order (bottom-up)
    updateHeight(y);  // Update y first as it's now lower
    updateHeight(x);  // Then update x

    return x;
}

template <class MyType>
Node<MyType>* AVLTree<MyType>::balance(Node<MyType>* node) {
    if (node == nullptr) return nullptr;

    updateHeight(node);
    int balanceFactor = getBalanceFactor(node);

    // Left Heavy
    if (balanceFactor > 1) {
        if (getBalanceFactor(node->getLeft()) >= 0) {
            // Left-Left Case
            return rightRotate(node);
        }
        else {
            // Left-Right Case
            node->setLeft(leftRotate(node->getLeft()));
            return rightRotate(node);
        }
    }

    // Right Heavy
    if (balanceFactor < -1) {
        if (getBalanceFactor(node->getRight()) <= 0) {
            // Right-Right Case
            return leftRotate(node);
        }
        else {
            // Right-Left Case
            node->setRight(rightRotate(node->getRight()));
            return leftRotate(node);
        }
    }

    return node;
}

template <class MyType>
Node<MyType>* AVLTree<MyType>::addElementRecursive(Node<MyType>* node, const MyType& value) {
    // Normal BST insertion
    if (node == nullptr)
        return new Node<MyType>(value);

    if (value <= node->getVal())
        node->setLeft(addElementRecursive(node->getLeft(), value));
    else
        node->setRight(addElementRecursive(node->getRight(), value));
    

    // Update height and balance the tree
    updateHeight(node);
    return balance(node);
}

template <class MyType>
void AVLTree<MyType>::addElement(const MyType& value) {
    root = addElementRecursive(root, value);
}

// Search for an element
template <class MyType>
bool AVLTree<MyType>::searchElement(const MyType& value, Node<MyType>* node) const {
    if (isEmpty())
        return false;

    if (!node)
        node = root;

    if (node->getVal() == value)
        return true;

    if (value < node->getVal())
        return (node->getLeft() != nullptr) && searchElement(value, node->getLeft());
    else
        return (node->getRight() != nullptr) && searchElement(value, node->getRight());
}

template<class MyType>
inline bool AVLTree<MyType>::isEmpty() const
{
    return false;
}


// In-order display
template <class MyType>
void AVLTree<MyType>::display(Node<MyType>* node) const {
    if (node == nullptr)
        return;

    display(node->getLeft());
    std::cout << node->getVal() << "-->" << "(height: " << node->getHeight() << ")  |";
    display(node->getRight());
}

// Breadth-First Search display
template <class MyType>
void AVLTree<MyType>::BFSdisplay() const {
    if (isEmpty()) {
        std::cout << "Tree is empty." << std::endl;
        return;
    }

    std::queue<Node<MyType>*> nodeQueue;
    nodeQueue.push(root);

    while (!nodeQueue.empty()) {
        Node<MyType>* currentNode = nodeQueue.front();
        nodeQueue.pop();

        std::cout << currentNode->getVal() << "-->" << "(height: " << currentNode->getHeight() << ")  |";

        if (currentNode->getLeft() != nullptr)
            nodeQueue.push(currentNode->getLeft());
        if (currentNode->getRight() != nullptr)
            nodeQueue.push(currentNode->getRight());
    }
    std::cout << std::endl;
}

template<class MyType>
inline Node<MyType>* AVLTree<MyType>::getRoot() const
{
    return root;
}


