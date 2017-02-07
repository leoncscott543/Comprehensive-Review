// BST 3.cpp : Defines the entry point for the console application.
// build a basic BST
/*
Algorithm:
1. make node struct
2. initialize empty BST
3. make make node function
4. make insert function
5. use recursion in insert function 
6. place values in the tree
7. make search function
8. search for something in the main function 
*/

#include "stdafx.h"
#include <iostream>

using namespace std;

struct bst {
	int data;
	bst *left; 
	bst*right;
};

bst *make_node(int data){
	bst *newNode = new bst; 
	newNode->left = NULL;
	newNode->right = NULL;
	newNode->data = data;

	return newNode; 
}

bst *insert(bst *root, int data) {
	if (root == NULL) return make_node(data); // base case

	else if (data <= root->data) root->left = insert(root->left, data);
	else root->right = insert(root->right, data);

	return root; 
}

bool search(bst *root, int data) {

	if (root == NULL) return false;
	else if (root->data == data) return true;

	else if (data <= root->data) search(root->left, data);
	else search(root->right, data);
}

int main()
{
	bst *root = NULL;
	int data; // for searching

	root = insert(root, 10);
	root = insert(root, 12);
	root = insert(root, 4);

	cout << "Search a number: ";
	cin >> data; 
	cout << endl;

	if (search(root, data) == true) cout << "Its here :)";
	else cout << "sorry, no can find :(";

	char f; 
	cin >> f;
    return 0;
}

