// Binary Tree 4.cpp : Defines the entry point for the console application.
/*
Deletion:
1. find min in left subtree
2. copy value in targeted node
3. delete duplicate minimum from the bottom of tree
*/

#include "stdafx.h"
#include <iostream>

using namespace std; 

struct node {
	int data; 
	node *left;
	node *right; 
};

node *create_node(node *root, int data) {
	node *newNode = new node;
	newNode->data = data;
	newNode->left = newNode->right = NULL;

	return newNode;
}

node *insert(node *root, int data) {
	if (root == NULL) root = create_node(root, data);

	else if (data >= root->data) {
		root->left = insert(root->left, data);
	}
	else
		root->right = insert(root->right, data);

	return root;
}

bool search(node *root, int data)
{
	if (root == NULL) return false;
	if (root->data == data) return true;

	else if (data > root->data) {
		 search(root->left, data);
	}
	else search(root->right, data);
}

struct node *Delete(struct node *root, int data)
{
	if (root == NULL) return root;
	else if (data < root->data) Delete(root->left, data);
	else if(data > root->data) root->right = Delete(root->right, data);

}

int main()
{
	node *root = NULL;
	
	int num;
	cout << "What number would you like to enter into the tree?	";
	cin >> num;

	while (num != 0) {
		
		root = insert(root, num);
		cin >> num;
	}
	
	cout << "What number would you like to search? ";
	cin >> num;

	while (num != 0) {
		
		if (search(root, num) == true) cout << "found!";
		else cout << "not found";
		cin >> num;
	}

	char f; 
	cin >> f;
    return 0;
}