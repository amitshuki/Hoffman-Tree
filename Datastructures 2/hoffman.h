#pragma once
#include "BStree.h"
#include "heap.h"
#include "hoffman.h"
#include "TreeNode.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class hoffman
{
public:
	/*
	This function receives the name of a text file. 
	Opening it scans it letter by letter 
	and creates nodes of pairs that contain the name of the letter and their occurrence.
	All nodes are arranged in a binary search tree by their frequency.

	*/
	BStree* textToBStree(string name);
	
	/*
	This function receives a priorty queue implemend by a minimum heap and executes the Hoffman algorithm on it
	The function returns a pointer to the tree root/
	*/
	TreeNode* huffman(heap* pq);

	//Print the huffman tree by huffman left berch give zero and right bring 1
	int printHuffman(string path, TreeNode* root);

	//this call from  the man and do all the biuld from text to print 'use all the funtion above/
	void buildHuffmanTree(string fname);
	friend heap;
};

