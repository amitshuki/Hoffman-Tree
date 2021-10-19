#include "BStree.h"



TreeNode* BStree::find(char ch)
{
	TreeNode* temp = root;
	while (temp != nullptr) {
		if (ch == (temp->data))
			return temp;
		else if (ch < (temp->data))
			temp = temp->left;
		else
			temp = temp->right;
	}
	return nullptr;

}
void BStree::insert(char ch)
{
	if (find(ch) != nullptr) {
		TreeNode* t = find(ch);
		t->freq++;
	}
	else {
		TreeNode* temp = root;
		TreeNode* parent = nullptr;
		TreeNode* newnode;
		while (temp != nullptr)
		{
			parent = temp;
			if (ch < temp->data)
				temp = temp->left;
			else temp = temp->right;
		}
		newnode = new TreeNode(ch);
		if (parent == nullptr)
			root = newnode;
		else if (ch < parent->data)
			parent->left = newnode;
		else parent->right = newnode;

	}

}
void BStree::Delete(char ch) {
	if (find(ch) == nullptr) {
		return;
	}


	TreeNode* n = nullptr;
	TreeNode* v = nullptr;
	n = root;
	while (n != nullptr && n->data != ch) {
		if (n->data > ch) {
			v = n;
			n = n->left;
		}
		if (n->data < ch) {
			v = n;
			n = n->right;
		}
	}
	if (n->data == ch) {
		if (n->right == nullptr && n->left == nullptr) {
			v->right = nullptr;
			v->left = nullptr;
		}
		if (n->right != nullptr && n->left == nullptr) {
			v->right = n->right;
		}
		if (n->right == nullptr && n->left != nullptr) {
			v->left = n->left;
		}
		if (n->right != nullptr && n->left != nullptr) {
			TreeNode* temp = n->right;
			TreeNode* othertemp = nullptr;
			while (temp->left != nullptr) {
				othertemp = temp;
				temp = temp->left;
			}

			n->data = temp->data;
			othertemp->left = nullptr;
		}
	}


}

void BStree::printTree() {
	if (root != nullptr) root->inOrder();
}
int BStree::nodesize(TreeNode* root) {
	if (root == nullptr)
		return 0;


	return 1 + (nodesize(root->left) +
		nodesize(root->right));;
}
int BStree::nodesize() {
	return nodesize(root);
}
void BStree::delettTree(TreeNode* root) {
	if (root != nullptr)
		return;
	if (root->Left())
		delettTree(root->Left());
	if (root->Right())
		delettTree(root->Right());
	delete root;
}
