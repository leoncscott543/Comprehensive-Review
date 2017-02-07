// BST 4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"




#include "stdafx.h"
#include <iostream>

using namespace std;

struct bst {
	int data;
	bst *left;
	bst *right;
};

bst *make_node(int data) {
	bst *newNode = new bst;
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;

	return newNode;
}

bst *insert(bst *root, int data) {
	if (root == NULL) return make_node(data);
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
	int data; // for search

	// perfect + balanced binary tree right here
	root = insert(root, 12);
	root = insert(root, 123);
	root = insert(root, 2);
	root = insert(root, 32);
	root = insert(root, 1000);
	root = insert(root, 1);
	root = insert(root, 5);

	cout << "Whatcha looking for? ";
	cin >> data; cout << endl; 

	if (search(root, data) == true) cout << "found it :)";
	else cout << "no can find :(";
	
	char f;
	cin >> f;
	return 0;
}
// basic BST