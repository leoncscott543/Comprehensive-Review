// Binary Tree 5.cpp : Defines the entry point for the console application.
// simple binary search tree.... 
/* Algorithm
1. build node struct
2. initialize root node to node in main function
3. create insert function
4. make base case for insert function
5. make create new node function all the way through
6. make the rest of the conditions for insert() function
7. pass some data into the tree
8. make search function 
9. make two base cases for search function... ex. if node == Null, and if data == true
10. make recursive case for searching for the element....

Making the Tree takes 0(n) time. Space is 0(n)
Searching the tree takes worse case of 0(n) and average of 0log(n)... space is 0(1) with overhead because recursion
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

node *create_node(int data) {
	node *newNode = new node;

	newNode->data = data; 
	newNode->left = newNode->right = NULL;


	return newNode; 
}

node *insert(node *root, int data) {
	if (root == NULL) root = create_node(data);

	else if (data >= root->data) {
		root->left = insert(root->left, data);
	}
	else {
		root->right = insert(root->right, data);
	}
	return root; 
}

bool search(node *root, int data) {

	if (root == NULL) return false; // base case

	if (root->data == data) return true; // return true if found

	else if (data < root->data) {
		search(root->right, data); // recursive case #1
	}
	else {
		search(root->left, data); // recursive case #2
	}
}
int main()
{
	node *root = NULL;

	root = insert(root, 20);
	root = insert(root, 15);
	root = insert(root, 33);

	if (search(root, 33) == true) cout << "found it :)";
	


	char f; 
	cin >> f;
    return 0;
}

