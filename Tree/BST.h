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

template<class MyType>
void BST<MyType>::BFSdisplay() const
{
    if (isEmpty()) {
        std::cout << "Tree is empty." << std::endl;
        return;
    }

    std::queue<Node<MyType>*> nodeQueue;
    nodeQueue.push(root);

    while (!nodeQueue.empty()) {
        Node<MyType>* currentNode = nodeQueue.front();
        nodeQueue.pop();

        std::cout << currentNode->getVal() << " ";

        if (currentNode->getLeft() != nullptr)
            nodeQueue.push(currentNode->getLeft());
        if (currentNode->getRight() != nullptr)
            nodeQueue.push(currentNode->getRight());
    }
    std::cout << std::endl;
}

template<class MyType>
Node<MyType>* BST<MyType>::getRoot() const
{
    return root;
}
