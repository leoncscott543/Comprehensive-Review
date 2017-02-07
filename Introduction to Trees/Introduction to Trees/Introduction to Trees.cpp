// Introduction to Trees.cpp : Defines the entry point for the console application.
// Binary Search Tree Implementation 
/*
Algorithm:
1. build node structure
2. make root node (this node is used to access the whole BST... aka it points to our binary search tree)
*/

#include "stdafx.h"
#include <iostream>

using namespace std; 

struct bst {
	bst *left;
	bst *right; 
	int data; 
};

// makes a new node, fills node with an integer, sets left and right edges/links to NULL... returns the newNode
bst *make_node(int data) {
	bst *newNode = new bst(); 
	newNode->left = NULL;
	newNode->right = NULL;
	newNode->data = data; 

	return newNode;
}

bst *Insert(bst *root, int data) {
	if (root == NULL) // if node is empty 
	{
		root = make_node(data); // make make_node and pass the value into that node... 
		return root;
	}
	else if (data <= root->data) {
		root->left = Insert(root->left, data);
	}
	else root->right = Insert(root->right, data);

	return root;
}

// this function searches for an integer in the BST 
bool search(bst *root, int data) {
	if (root == NULL) return false; // return	 false if cant be found in current node
	else if (root->data == data) return true; // return true if its found in current node

	// otherwise, traverse list recursively depending on whether the integer is smaller or larger than current node
	else if (data <= root->data) search(root->left, data); 
	else search(root->right, data);
}

int main()
{
	bst *root; // pointer to root node; 
	root = NULL; // tree is empty when root = NULL
	int data; // user search

	root = Insert(root, 15);
	root = Insert(root, 10);
	root = Insert(root, 20);
	root = Insert(root, 25);
	root = Insert(root, 55);
	root = Insert(root, 4);
	root = Insert(root, 60);


	cout << "What number are we searching for? ";
	cin >> data;

	if (search(root, data) == true) cout << endl <<  "yep its in there :)";
	else cout << endl << "sorry the number cannot be found ";

	char f; 
	cin >> f;
    return 0;
}

