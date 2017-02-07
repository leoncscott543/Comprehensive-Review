// Binary Tree 6.cpp : Defines the entry point for the console application.
/*
Algorithm
1. make node struct
2. initialize root node in main to null
3. make insert function
4. define insert function's base case.... if root == null
5. make create_node function completely 
6. make insert function's recursive cases
7. call some data into the tree... aka binary build a tree
8. make search function
9. define base cases for search function... if root == null, and if root->data = data being passed
10. make recursive cases for search()
11. search something in the main function to test the program
*/

#include "stdafx.h"
#include <iostream>

using namespace std;

struct node {
	int data; 

	node *left, *right; 
};

node *create_node(int data) {
	node *newNode = new node;

	newNode->data = data;
	newNode->left = newNode->right = NULL;

	return newNode; 
}

node *insert(node *root, int data) {

	//base case
	if (root == NULL) root == create_node(data);

	// recursive cases
	else if (data <= root->data) root->left = insert(root->left, data);
	else root->right = insert(root->right, data);

	return root;
}

bool search(node *root, int data) {
	
	// base cases
	if (root == NULL) return false;
	if (root->data == data) return true;

	// recursive cases
	else if (data <= root->data) search(root->left, data);
	else search(root->right, data);
}

int main()
{
	node *root = NULL;

	root = insert(root, 15);
	root = insert(root, 23);
	root = insert(root, 50); 

	if (search(root, 0) == true) cout << "yep! we found it :)";
	else cout << "cant find that number :(";

	char f;
	cin >> f;
    return 0;
}

