// BST 8.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std; 

struct bst {
	int data;
	bst *left;
	bst *right; 
};

bst *create_node(int data){
	bst *newNode = new bst; 
	newNode->data = data;
	newNode->right = NULL;
	newNode->left = NULL;

	return newNode; 
}

bst *insert(bst *root, int data) {
	if (root == NULL) return create_node(data);
	else if (data <= root->data) root->left = insert(root->left, data);
	else root->right = insert(root->right, data);

	return root; 
}

int min(bst *root) {
	if (root == NULL) { cout << "list empty"; return 0; }
	else if (root->left == NULL) return root->data;
	else min(root->left);
}

int max(bst *root) {
	if (root == NULL) { cout << "list empty"; return 0; }
	else if (root->right == NULL) return root->data;
	else max(root->right);
}

int whos_larger(int a, int b) {
	if (a <= b) return b;
	else return a;
}

int height(bst*root) {
	if (root == NULL) return 0; 
	return whos_larger(height(root->left), height(root->right)) + 1;
}

int main()
{
	bst *root = NULL;
	int data;

	cout << "Enter data into tree: ";
	cin >> data; 

	while (data != 0) {
		root = insert(root, data);
		cin >> data; 
	}

	cout << endl << "min: " << min(root);
	cout << endl << "max: " << max(root);
	cout << endl << "height: " << height(root);

	char f;
	cin >> f;
    return 0;
}

