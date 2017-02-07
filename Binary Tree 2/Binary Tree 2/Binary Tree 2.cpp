// Binary Tree 2.cpp : Defines the entry point for the console application.
/*
Algorithm:
1. create node struct (check)
2. create insert() function
3. make first empty node
4. create create_node() function
5. pass some data through to these functions to build a tree
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

bool search(node *root, int data) {

	// cant find it in current node
	if (root == NULL) return false;

	// found the data
	if (root->data == data) return true; 
	
	// push to the right if larger than root
	else if (data >= root->data) {
		return search(root->right, data);
	}

	// push to the left if smaller than rootB
	else {
		return search(root->left, data);
	}


}


// create new node... makes newNode->data = data
node *create_node(int data) {
	node *newNode = new node(); 

	newNode->data = data; 
	newNode->left = NULL;
	newNode->right = NULL;

	return newNode;
}

node *insert(node* root, int data) {

	// base case 
	if (root == NULL) {
		root = create_node(data);
	}
	else if (data >= root->data){
		root->right = insert(root->right, data);
	}
	else root->left = insert(root->left, data);

	return root; 
}

int main()
{
	node *root = NULL;

	// instead of simply calling insert().... we have to overight the NULL loop by setting it equal to the returned root from insert()
	root = insert(root, 20);
	root = insert(root, 50);
	root = insert(root, 15);
	root = insert(root, 23);
	root = insert(root, 70);

	if(search(root, 70) == true) cout << "found";
	else cout << "not found";

	char f; 
	cin >> f;
    return 0;
}

