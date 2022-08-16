#pragma once
#include "Node.h"
#include <iostream>
template <typename T>
struct BinTree
{
	Node<T>* root = nullptr;
	void push(T data)
	{
		if (!root)
		{
			root = new Node<T>(data);			
		}
		else
		{
			addToItem(root, data);
		}
	}
	void addToItem(Node<T>* currentNode, T value)
	{
		
		if (currentNode->data > value)
		{
			if (currentNode->pLeft == nullptr)
			{
				currentNode->pLeft = new Node<T>(value);
				currentNode->pLeft->parent = currentNode;
			}
			else addToItem(currentNode->pLeft, value);
		}
		else
		{
			if (currentNode->pRight == nullptr)
			{
				currentNode->pRight = new Node<T>(value);
				currentNode->pRight->parent = currentNode;
			}
			else addToItem(currentNode->pRight, value);
		}
	}
	void printNode(Node<T>* currentNode)
	{
		if (currentNode == nullptr)
			return;
		else
		{
			printNode(currentNode->pLeft);
			std::cout << currentNode->data << '\n';
			printNode(currentNode->pRight);
		}
	}
	void print()
	{
		if (!root)
			std::cout << "empty \n";
		else
		{
			printNode(root);
		}
	}

	//int get_height();
};