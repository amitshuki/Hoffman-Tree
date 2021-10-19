#include "BStree.h"
#include "heap.h"
#include "hoffman.h"
#include "TreeNode.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;



int main()
{
	hoffman f;
	string s;
	cout << "ENTER FILE NAME:";
	cin >> s;
	
	f.buildHuffmanTree(s);

	return 0;
}

