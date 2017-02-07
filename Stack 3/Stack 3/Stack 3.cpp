// Stack 3.cpp : Defines the entry point for the console application.
// hip hip horray!!!

#include "stdafx.h"
#include <iostream>

using namespace std;

struct node {
	int data;
	node *link;
};

node *make_node(int data) {
	node *newNode = new node;
	newNode->data = data;
	newNode->link = NULL;

	return newNode;
}

node *push(node *top, int data) {
	node *current = top;
	if (top == NULL) {
		return make_node(data);
	}
	node *temp = make_node(data);
	temp->link = current;
	top = temp;

	return top; 
}

node *pop(node *top) {
	if (top == NULL) return NULL; 

		node* temp = top; 
		top = top->link;
		delete temp;
	
		return top;
}

void print(node *top) {
	if (top == NULL) {
		return;
	}

	cout << top->data << " ";
	print(top->link);
}
int main()
{
	node *top = NULL;

	top = push(top, 10);
	top = push(top, 14);
	top = push(top, 13);
	
	print(top);

	top = pop(top);
	
	cout << endl << endl;
	print(top);

	for (int i = 0; i < 50; i++) {
		top = push(top, 10 * i);
	}


	cout << endl << endl;

	print(top);

	char f; 
	cin >> f;
    return 0;
}

