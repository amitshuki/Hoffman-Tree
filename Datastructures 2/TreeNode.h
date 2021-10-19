#pragma once
#include <iostream>

class TreeNode
{
private:
	char data;
	TreeNode* left, * right;
	int freq;



public:
	//ctor and dtor
	TreeNode();
	TreeNode(char ch,TreeNode*r,TreeNode*l,int _freq);
	TreeNode(char _data);
	//~TreeNode();

	//getters
	TreeNode* Left() { return left; }
	TreeNode* Right() { return right; }
	int Frequency() { return freq; }
	char letter() { return data; }
	bool isLeaf();

	//setters
	void SetLeft(TreeNode* node) { left = node; }
	void SetRight(TreeNode* node) { right = node; }
	void setFrequency(int num) { freq = num; }
	void SetChar(char ch) { data = ch; }
	//prints metheods
	void inOrder();
	void postOrder();
	void PreOrder();
	TreeNode& operator=(const TreeNode& other)
	{
		this->data = other.data;
		this->freq = other.freq;
		this->left = other.left;
		this->right = other.right;

		return (*this);
	}

	//friends
	friend class BStree;
	friend class Btree;
	friend class heap;
	friend class Tree;


};

