
// The problem at hand is to convert a binary tree 
// to a dynamic linked list
#include <cstdlib>
#include <iostream>

using namespace std;

// Node definition
typedef struct node
{
	int data;
	struct node *left, *right;
} NODE;

// New node initializer
NODE *newNode(int data)
{
	NODE *node = (NODE *) malloc (sizeof(NODE));
	node->data = data;
	node->left = node->right = NULL;
};

// Inorder traversal
void  inorder(NODE *root)
{
	if (root != NULL)
	{
		inorder(root->left); 	// traverse left node first
		cout << root->data << "\t";	// print this root's data
		inorder(root->right);	// traverse right node

	}
}

// change the left pointers, such that they become
// previous pointers in the converted dynamic linked list
// This function does inorder traversal for left pointers and 
// updates left pointer using previously visited node
void setPrevPtr(NODE * root)
{
	// pointer to keep record of previously visited node
	static NODE *prev = NULL;

	if (root != NULL)
	{
		// keep navigating till we reach the left most leaf
		setPrevPtr(root->left);
		// make this node's left to point to previous node
		root->left = prev;
		// for next element save this as the previous node
		prev = root;
		// correct the previous node for right subtree
		setPrevPtr(root->right);
	}
}

// update right pointer to work as next pointer in double linked list
NODE* setNextPtr(NODE* root)
{
	NODE * previous = NULL;

	//Find the right most node in binary tree or last node of dynamic linkedl ist
	while(root && root->right != NULL)
		root = root->right;	 
	// starting from the right most node, traverse back to using left
	// pointer, which now point to previous pointer in the double lilnked list

	while(root && root->left)
	{
		previous = root; 	// save the current node
		root = root->left;	// update current node to point to previous node
		root->right = previous; // now since current node is the previous of 
		// original node, mark right node to original root node
	}
	// we have reached the left most node now, which is the head

	return(root);
}

NODE* BT2DLL(NODE* root)
{
	// set the previous pointers
	setPrevPtr(root);

	// set the next pointers and return the head
	setNextPtr(root);
}

void printDLL(NODE* root)
{
	while(root!= NULL)
	{
		cout << root->data<< "\t" ;
		root = root->right;
	}
}

int main(int argc, char const *argv[])
{

	NODE* root = newNode(10);
	root->left = newNode(12);
	root->right       = newNode(15);
    root->left->left  = newNode(25);
    root->left->right = newNode(30);
    root->right->left = newNode(36);
	
    cout << endl << "Inorder traversal" << endl << endl;

    inorder(root);
	cout << endl << endl;
    
    NODE* head = BT2DLL(root);
    cout << "Double linked list traversal" << endl << endl;
    printDLL(head);
	cout << endl << endl;
	/* code */
	return 0;
}