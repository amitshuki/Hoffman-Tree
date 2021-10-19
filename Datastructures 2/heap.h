#pragma once
#include "BStree.h"
#include"TreeNode.h"


class heap {
private:
	// data members
	TreeNode*  data  ;
	int maxSize;
	int heapSize;
	// methods

	int leftChild(int node);
	int rightChild(int node);
	int parent(int node);

public:
	//ctor
	heap(int max);
	heap(BStree* t);
	~heap();
	void buildHeap(TreeNode A[], int n);
	
	//function that 
	void fixHeap(int node);
	//check if its empty
	bool isEmpty() { if (heapSize == 0)return true; else false; }
	//return size of prioroty queue
	int size() { return heapSize; }
	
	//recives a treenode and insert to the queue and fix it(call fix heap)
	void insert(TreeNode* item);
	// apeek to the min in the heap
	TreeNode* min(void);

	//delete the min and fix the heap
	TreeNode* deletemin(void);

	//a genric swap of tree nodes
	void swap(TreeNode &t, TreeNode  &y);

	//revice a tree and isert all itss nodes to the heap by inorder scan
	void insertloop(BStree* t);
	void insertloop(TreeNode* t);//assit function

	//make the heap empty
	void makeEmpty();

	friend BStree;
	friend TreeNode;


};