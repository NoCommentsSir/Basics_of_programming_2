#pragma once
#include "Tree.h"

template <typename T>
struct BackwardIterator
{
	BinTree<T>* collection;
	Node<T>* current;
    
	BackwardIterator(BinTree<T>* collection)
	{
		this->collection = collection;
		this->current = nullptr;
	}
	
	bool hasMore()
	{
        return (fetchNext() != nullptr);
	}

    Node<T>* findMax(Node<T>* startingNode) {
        if (!startingNode->pRight)
            return startingNode;

        return findMax(startingNode->pRight);
    }

    Node<T>* getNextParent(Node<T>* currentNode) {
   
        Node<T>* parent = currentNode->parent;
        if (parent) {
            // going up from Left
            if (parent->pRight == currentNode) {
                return parent;
            }
            else { // we're in the left subtree
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
            next = findMax(this->collection->root);
            return next;
        }

        if (this->current->isLeaf())
        {
            next = getNextParent(this->current);
            return next;
        } 
        else { // not leaf, i.e. current is a node
            if (this->current->pLeft) {
                next = findMax(this->current->pLeft);
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