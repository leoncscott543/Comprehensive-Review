// Binary Tree 3.cpp : Defines the entry point for the console application.
/*
Algorithm
1. build node struct (check)
2. create default NULL root node.... aka make an empty BST (check)
3. create insert function (check)
4. create newNode function (check)
5. build a tree from the main function (check)
6. create search function for the tree (check)
7. create traveral/printing function for the tree 
*/

#include "stdafx.h"
#include <iostream>

using namespace std;

// node object
struct node {
	int data; 
	node *left;
	node *right; 
};

// allocating new node on heap
node *create_node(int data) {
	node *newNode = new node;

	newNode->data = data;

	newNode->left = newNode->right = NULL;

	return newNode; 
}

// recursive function for placing new nodes in correct location in BST..... 
node *insert(node *root, int data) {

	// base case
	if (root == NULL) {
		root = create_node(data);
	}

	// recursive case 
	else if (data <= root->data) {
		root->right = insert(root->right, data); // smaller data -> right pointer
	}
	else root->left = insert(root->left, data); // larger data <- left pointer

	return root; 
}

// traverse tree, return true if found, return false if not found
bool search(node *root, int data) {

	if (root == NULL) return false; // base case

	if (root->data == data) return true; // return true if found

	else if (data < root->data) {
		search(root->right, data); // recursive case #1
	}
	else {
		search(root->left, data); // recursive case #2
	}
}

int main()
{
	// initialize root as node... empty BST
	node *root = NULL;

	// passing data to build BST
	root = insert(root, 5);
	root = insert(root, 10);
	root = insert(root, 50);

	if (search(root, 50) == true) cout << "We found it :)";
	else cout << ":( sorry its not there";

	char f;
	cin >> f;
    return 0;
}

