// BST 2.cpp : Defines the entry point for the console application.
/*
Algorithm:
1. make node structure
2. initialize empty BST
3. make a make node function
4. make an insert function, pass root and integer variable 
5. use recursion for traversing to the right spot to insert a new node 
6. pass some numbers to the tree 
7. make a search function
8. function returns true and false depending on whether data is found in tree
9. Complexities... Insert: O(logn)... Searching: 0(logn)... Space: 0(n) for building the list.... 0(1) for searching and inserting. 
*/

#include "stdafx.h"
#include <iostream>

using namespace std;

// node struct
struct bst {
	bst *left; 
	bst *right;
	int data;
};

// function creates a new dynamically allocated node 
bst *make_node(int data) {
	bst *newNode = new bst; 
	newNode->left = NULL;
	newNode->right = NULL;
	newNode->data = data;

	return newNode; 
}

// function that inserts a new node in the BST
bst *insert(bst *root, int data) {
	if (root == NULL) {
		root = make_node(data);
		return root; 
	} // base case
	else if (data <= root->data) root->left = insert(root->left, data); // recursive case #1
	else root->right = insert(root->right, data); // recursive case #2

	return root; 
}

// function seeks a nu	mber
bool search(bst *root, int data) {
	if (root == NULL) return false; // base case #1
	else if (root->data == data) return true; // base case #2
	else if (data <= root->data) search(root->left, data); // recursive case #1
	else search(root->right, data); // recursive case #2
}

int main()
{
	bst *root = NULL; // empty tree initialization 
	int data; // for searching

	// self explanatory
	root = insert(root, 43);
	root = insert(root, 50);
	root = insert(root, 10);
	root = insert(root, 20);
	root = insert(root, 32);
	root = insert(root, 60);
	root = insert(root, 85);
	root = insert(root, 45);

	cout << "What number are you looking for? ";
	cin >> data; 

	if (search(root, data) == true) cout << endl << "its in the list!";
	else cout << endl << "sorry its not in the list :(";
	char f; 
	cin >> f;
    return 0;
}

