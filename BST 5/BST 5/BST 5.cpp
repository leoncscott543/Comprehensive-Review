
// BST 5.cpp : Defines the entry point for the console application.
// basic implementation 

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

void preorder(bst *root) {
	if (root == NULL) return; 
	cout << root->data << " ";
	preorder(root->left);
	preorder(root->right);		
}

void postorder (bst *root) {
	if (root == NULL) return;
	postorder(root->left);
	postorder(root->right);
	cout << root->data << " ";
}

void inorder(bst *root) {
	if (root == NULL) return;
	inorder(root->left);
	cout << root->data << " ";
	inorder(root->right);
}



int main()
{
	bst *root = NULL;
	int data; 

	root = insert(root, 15);
	root = insert(root, 30);
	root = insert(root, 10);
	root = insert(root, 50);
	root = insert(root, 100);
	root = insert(root, 20);
	root = insert(root, 1);
	root = insert(root, 5);

	cout << "What number are you looking for? ";
	cin >> data;

	cout << endl;

	if (search(root, data) == true) cout << "we found it :)";
	else cout << "nope cant find it :(";

	cout << endl << endl << "Preorder: ";
	preorder(root);

	cout << endl << endl << "Inorder: ";
	inorder(root);

	cout << endl << endl << "Postorder: ";
	postorder(root);

	char f;
	cin >> f;
    return 0;
}

