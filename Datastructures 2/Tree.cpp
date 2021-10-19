#include "Tree.h"


TreeNode* Tree::find(char ch) {
	if (root->letter() == ch)
		return root;
	else {
		if (root->Left())
			find(root->Left()->letter());
		if (root->Right())
			find(root->Right()->letter());
	}
}

//insert new node to the tree
void Tree::insert(char ch) {
 
        if (find(ch) != nullptr) {
           return;
     
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



//delete a node in the tree ;
void Tree::Delete(char ch) {
 
        TreeNode* p;        // Help variable
        TreeNode *parent;   // parent node
        TreeNode *succ;     // successor node

        p = find(ch);

        if (p == nullptr)
            return;               // Not found ==> nothing to delete->->->->


        if (p->Left() == nullptr && p->Right() == nullptr) // Case 1: p has no children
        {
            if (p == root)   
            {
                root = nullptr;
                return;
            }

            parent= findParent(ch);

            if (parent->Left() == p)
                parent->SetLeft(nullptr);
            else
                parent->SetRight(nullptr);

            return;
        }

   

        if (p->Right() == nullptr)
        {
            if (p == root)  
            {
                root = root->Left();
                return;
            }

            parent =findParent(ch);

        
            if (parent->Left() == p)
                parent->SetLeft( p->Left());
            else
                parent->SetRight(p->Left());

            return;
        }

        if (p->Left() == nullptr)  
        {
            if (p == root)  
            {
                root = root->Right();
                return;
            }

            parent = findParent(ch);


       
            if (parent->Left() == p)
                parent->SetLeft(p->Right());
            else
                parent->SetRight(p->Right());

            return;
        }

     

        if (p->Right()->Left() == nullptr)
        {
           
            p->SetChar(p->Right()->letter());         
            p->SetRight(p->Right()->Right());       

            return;                       
        }

        succ = p->Right();               
        TreeNode* succParent = p;            

        while (succ->Left() != nullptr)
        {
            succParent = succ;         
            succ = succ->Left();
        }

    
        p->SetChar( succ->letter());          
        succParent->SetLeft(succ->Right());
    }


//print tree in order;
void Tree::printTree() {
    if (root != nullptr) root->inOrder();
}

//return the number of the nodes
int Tree::nodesize() {
    return nodesize(root);

}
int Tree::nodesize(TreeNode* root) {
    if (root == nullptr)
        return 0;

    return 1 + (nodesize(root->Left()) +
        nodesize(root->Right()));;
}

TreeNode* Tree::findParent(char ch) {
    if (root->Left()->letter() == ch || root->Right()->letter() == ch)
        return root;
    else {
        if (root->Right() == nullptr && root->Left() == nullptr)
            return nullptr;
        if (root->Left())
            findParent(root->Left()->letter());
        if (root->Right())
            findParent(root->Right()->letter());
     
    }
}


void Tree::delettTree(TreeNode* root) {
    if (root != nullptr)
        return;
    if (root->Left())
        delettTree(root->Left());
    if (root->Right())
        delettTree(root->Right());
    delete root;
}