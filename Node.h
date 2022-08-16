#pragma once

template <typename T>
struct Node
{
	T data;
	Node<T>* pLeft;
	Node<T>* pRight;
	Node <T>* parent;

	Node(T data)
	{
		this->data = data;
		this->pLeft = nullptr;
		this->pRight = nullptr;
		this->parent = nullptr;
	}

    bool isLeaf()
	{
		if (this->pLeft == nullptr && this->pRight == nullptr)
			return true;
		else return false;
	}

    bool isRoot()
	{
		if (this->parent == nullptr)
			return true;
		else return false;
	}

};