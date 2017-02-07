// Binary Tree.cpp : Defines the entry point for the console application.
// Binary Tree implementation 
// ADT is a stack
/* 
Algorithm:
1. create node struct (check)
2. create empty tree/root node in main function (check)
3. create insert function for inserting new data into tree... smaller on left, greater on right
4. create new_node function for creating new node... this is used from within insert function
5. use recurssion to fill up tree from within insert() function
5. 
*/

#include "stdafx.h"
#include <iostream>
#include <string>		

using namespace std;

// node structure
struct node {
	int data; 
	node *left;
	node *right;
};

node *new_node(int data)
{
	// creates a new node with data... sets left/right children to NULL by default
	node *newNode = new node;
	newNode->data = data;
	newNode->left = newNode->right = NULL;

	return newNode; // returns address of new node
}

// insertion function
node *insert(node *root, int data)
{
	// base case... if tree is empty, create first root node with both children set to null
	if (root == NULL) {
		cout << data << " root " << endl;
		root = new_node(data);
	}
	// otherwise... recursive case transpires.... essentially filling up the tree
	else if (data <= root->data) {
		cout << " left";
		root->left = insert(root->left, data);
	}
	else { cout << " right"; root->right = insert(root->right, data); }

	return root;
}

int main()
{
	// root node declaration... empty tree
	node *root;
	root = NULL;

	// inserting data tree by calling insert() function
	insert(root, 5);
	insert(root, 10);
	insert(root, 15);

	char f;
	cin >> f;
    return 0;
}

