// BST 6.cpp : Defines the entry point for the console application.
// wonderfully fun implementation 

#include "stdafx.h"
#include <iostream>

using namespace std;

struct bst {
	bst *left;
	bst *right;
	int data;
};

bst *make_node(int data) {
	bst *newNode = new bst;
	newNode->left = NULL;
	newNode->right = NULL;
	newNode->data = data; 

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
	if (root->data == data) return true; 
	else if (data <= root->data) search(root->left, data);
	else search(root->right, data);
}

void preorder(bst *root) {
	if (root == NULL) return;
	cout << root->data << " ";
	preorder(root->left);
	preorder(root->right);
}

void inorder(bst *root) {
	if (root == NULL) return;
	inorder(root->left);
	cout << root->data << " ";
	inorder(root->right);
}

void postorder(bst *root) {
	if (root == NULL) return;
	postorder(root->right);
	postorder(root->left);
	cout << " " << root->data;
}

bst *del(bst *root, int data) {
	// case 0: empty list
	// case 1: no children
	// case 2: left child only
	// case 3: right child only
	// case 4: both children present

	if (root == NULL) { cout << "the tree is empty"; return root; } // case 1

	else if (data <= root->data) root->left = del(root->left, data);
	else if (data > root->data) root->right = del(root->right, data);
	else {

		// case  1
		if (root->left == NULL && root->right == NULL) {
			delete root; 
			root = NULL;
			return root;
		}

		// case 2
		if (root->left == NULL) {
			bst *temp = root; 
			root = root->right;
			delete temp;
			return root; 
		}

		// case 3
		if (root->right == NULL) {
			bst *temp = root;
			root = root->left; 
			delete temp;
			return root;
		}
	}
	return root; 
}

int main()
{
	bst *root = NULL;
	int data; 

	root = insert(root, 50);
	root = insert(root, 45);
	root = insert(root, 65);
	root = insert(root, 10);

	cout << "What number would you like to search? ";
	cin >> data;

	if (search(root, data) == true) cout << "Yep its in the list";
	else cout << "nope its not there";

	cout << endl << "Inorder:"; inorder(root);

	char f;
	cin >> f;
    return 0;
}

