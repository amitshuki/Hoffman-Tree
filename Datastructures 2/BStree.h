#pragma once
#include"TreeNode.h"
class BStree
{
private:
	TreeNode* root;



	//assit for nodesie
	int nodesize(TreeNode* _n);
	//assit for dtor
	void delettTree(TreeNode* root);

public:

	//ctor
	BStree() :root(nullptr) {};
	BStree(TreeNode* t) :root(t) {};

	//dtor
	~BStree() { delettTree(this->root); }
	//find if given char is exist in the tree if he does he add 1 for is frenq
	TreeNode* find(char ch);

	//insert new node to the tree and keep it a search tree
	void insert(char ch);

	//delete a node in the tree and fix him to be a search tree
	void Delete(char ch);

	//print tree in order;
	void printTree();

	//return the number of the nodes
	int nodesize();

	//getter of root;
	TreeNode* getroot() { return root; }
	
};

