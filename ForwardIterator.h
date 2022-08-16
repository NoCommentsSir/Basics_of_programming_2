#pragma once
#include "Tree.h"

template <typename T>
struct ForwardIterator
{
	BinTree<T>* collection;
	Node<T>* current;
    
	ForwardIterator(BinTree<T>* collection)
	{
		this->collection = collection;
		this->current = nullptr;
	}
	
	bool hasMore()
	{
        return (fetchNext() != nullptr);
	}

    Node<T>* findMin(Node<T>* currentNode) {
        if (!currentNode->pLeft)
            return currentNode;

        return findMin(currentNode->pLeft);
    }

    Node<T>* getNextParent(Node<T>* currentNode) {
   
        Node<T>* parent = currentNode->parent;
        if (parent) {
            // going up from Left
            if (parent->pLeft == currentNode) {
                return parent;
            }
            else { // we're in the right subtree
                return getNextParent(parent);
            }
        }
        else // nullptr
            return parent;
    }

    Node<T>* fetchNext() {

        Node<T>* next = nullptr;

        // current == 0
        if (this->current == nullptr) {
            next = findMin(this->collection->root);
            return next;
        }

        if (this->current->isLeaf())
        {
            next = getNextParent(this->current);
            return next;
        } 
        else { // not leaf
            if (this->current->pRight) {
                next = findMin(this->current->pRight);
                return next;
            }
            else {
                next = getNextParent(this->current);
                return next;
            }
        }
    }

	void move()
	{
        this->current = fetchNext();
	}

};