#pragma once
#include "TreeNode.h"
#include"BStree.h"





//I implemented the class because I was required by the instructions it has no use of the solution.
class Tree {

private:
	TreeNode* root;

	//assit for nodesie
	int nodesize(TreeNode* _n);
	//assit for dtor
	void delettTree(TreeNode* root);
	TreeNode* findParent(char ch);

public:

	//ctor
	Tree() :root(nullptr) {};
	Tree(TreeNode* t) :root(t) {};

	//dtor
	~Tree() { delettTree(this->root); }

	TreeNode* find(char ch);

	//insert new node to the tree and keep it a search tree
	void insert(char ch);

	//delete a node in the tree ;
	void Delete(char ch);

	//print tree in order;
	void printTree();

	//return the number of the nodes
	int nodesize();

	//getter of root;
	TreeNode* getroot() { return root; }

	friend TreeNode;
};
