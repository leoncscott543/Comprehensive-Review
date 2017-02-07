// BST 7.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std; 

struct bst {
	int data;
	bst *left;
	bst *right;
};

bst *make_node(bst *root, int data) {
	bst *newNode = new bst; 
	newNode->right = NULL;
	newNode->left = NULL;
	newNode->data = data; 

	return newNode; 
}

bst *insert(bst *root, int data) {
	if (root == NULL) return make_node(root, data);
	else if (data <= root->data) root->left = insert(root->left, data);
	else root->right = insert(root->right, data);

	return root; 
}

int min(bst *root) {
	if (root == NULL) { cout << "root is empty"; return -1; }
	else if (root->left == NULL) return root->data;
	min(root->left); 
}

int max(bst *root) {
	if (root == NULL) { cout << "root is empty"; return -1; }
	if (root->right == NULL) return root->data;
	max(root->right);
}


int main()
{
	bst *root = NULL;
	int data; 

	cout << "Enters numbers into tree (0 for finish): " << endl;
	cin >> data;
	while (data != 0) {
		root = insert(root, data);

		cin >> data; 
	}
	cout << endl << endl << "The minimum is: " << min(root);
	cout << endl << endl << "The maximum is: " << max(root);

	char f; 
	cin >> f;
    return 0;
}

