#pragma once
#include <iostream>

template <class MyType>
class Node {
private:
    MyType elem;
    Node<MyType>* left;
    Node<MyType>* right;
    int height;
public:
    Node(MyType val);
    void display() const;
    MyType getVal() const;
    MyType setVal() const;

     int getHeight() const;
	void setHeight(int h);

    Node<MyType>* getLeft() const;
    void setLeft(Node* next);
    Node<MyType>* getRight() const;
    void setRight(Node* next);
    
};

// Constructor
template <class MyType>
inline Node<MyType>::Node(MyType val) : elem(val), left(nullptr) , right(nullptr),height(1) {}


template <class MyType>
inline void Node<MyType>::display() const {
    std::cout << elem;
}

template<class MyType>
inline MyType Node<MyType>::getVal() const
{
    return elem;
}

template<class MyType>
inline MyType Node<MyType>::setVal() const
{
    return MyType();
}

template<class MyType>
inline int Node<MyType>::getHeight() const
{
    return height;
}

template<class MyType>
inline void Node<MyType>::setHeight(int h)
{
	height = h;
}


template<class MyType>
inline Node<MyType>* Node<MyType>::getRight() const
{
    return right;
}

template<class MyType>
inline void Node<MyType>::setRight(Node* n)
{
    right = n;
}
template<class MyType>
inline Node<MyType>* Node<MyType>::getLeft() const
{
    return left;
}

template<class MyType>
inline void Node<MyType>::setLeft(Node* n)
{
    left = n;
}

