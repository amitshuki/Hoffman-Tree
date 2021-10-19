#include "TreeNode.h"
using namespace std;



TreeNode::TreeNode() 
{
	this->left = nullptr;
	this->right = nullptr;
	freq = 0;
	data = '&';

}
TreeNode::TreeNode(char _data) 
{
	this->left = nullptr;
	this->right = nullptr;
	this->data = _data;
	this->freq = 1;
}
TreeNode::TreeNode(char ch, TreeNode* r, TreeNode* l, int _freq) {
	this->data = ch;
	this->right = r;
	this->left = l;
	this->freq = _freq;

}

void  TreeNode::inOrder() {
	
	if (left != nullptr) left->inOrder();
	cout <<data<<endl;
	if (right != nullptr)right->inOrder();
}
void TreeNode::postOrder() {
	if (left != nullptr) left->postOrder();
	if (right != nullptr)right->postOrder();
	cout << data;
}
void TreeNode::PreOrder()
{
	cout << data;
	if (left != nullptr) left->PreOrder();
	if (right != nullptr)right->PreOrder();


}
bool TreeNode::isLeaf() {
	if (right == nullptr && left == nullptr)
		return true;
	else
	{
		return false;
	}
}






