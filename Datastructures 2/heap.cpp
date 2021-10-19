#include "heap.h"
using namespace std;



heap::heap(int max) {
	data = new TreeNode[max];
	maxSize = max;
	heapSize = 0;
}
heap::~heap() {

	delete[] data;
}
int heap::leftChild(int node) {
	return ((2 * node)+1);
}
int heap::rightChild(int node) {
	return ((2 * node) + 2);
}
int heap::parent(int node) {
	return ((node-1) / 2);
}

void heap::insert(TreeNode* item)
{
	if (heapSize == maxSize)
	{
		cout << "Heap full";
		exit(1);
	}
	else
	{

		int i = heapSize;
		heapSize++;
		while ((i > 0) && (data[parent(i)].Frequency()) > item->Frequency())
		{
			data[i] = data[parent(i)];
			i = parent(i);
		}

		data[i] = *item;

	};
}
TreeNode* heap::min() {
	return &data[0];
}
void heap::fixHeap(int node) {
	int min, left, right;
	bool end = false;
	while (end == false) {
		left = leftChild(node);
		right = rightChild(node);
		// Find min among node, left and right.
		if ((left <= heapSize) && (data[left].freq < data[node].freq))
			min = left;
		else
			min = node;
		if ((right <= heapSize) && (data[right].freq < data[min].freq))
			min = right;
		if (min == node)
			end = true;
		else
			swap(data[node], data[min]);
		node = min;
	}
}
TreeNode* heap::deletemin() {
	if (heapSize == 0) { return nullptr; }
	TreeNode* min = new TreeNode(data[0]);
	data[0] = data[heapSize-1];
	heapSize--;
	if (heapSize >= 1)
		fixHeap(0);
	return min;
}
void heap::buildHeap(TreeNode A[], int n) {

	heapSize = maxSize;
	for (int i = (heapSize/2)-1; i >= 0; i--)
		fixHeap(i);
}

void heap::swap(TreeNode& t, TreeNode& y) {
	TreeNode temp = t;
	t = y;
	y = temp;
}

heap::heap(BStree* t) {

	this->maxSize = t->nodesize();
	this->data = new TreeNode[maxSize];
	insertloop(t);
	buildHeap(data, maxSize);
	for (int i = 0; i < heapSize; i++) {
		data[i].left = nullptr;
		data[i].right = nullptr;
	}
}
void heap::insertloop(BStree* t) {
	insertloop(t->getroot());
}
void heap::insertloop(TreeNode* t) {
	if (t->Left() != nullptr)  insertloop(t->Left());
	insert(t);
	if (t->Right() != nullptr)  insertloop(t->Right());



}
void heap::makeEmpty() {
	heapSize = 0;

}
