// Stack 1.cpp : Defines the entry point for the console application.
// 

#include "stdafx.h"
#include <iostream>

using namespace std; 

struct node{
	int data;
	node *link;
};

node *make_node(int data) {
	node *newNode = new node;

	newNode->link = NULL;
	newNode->data = data;

	return newNode; 
}

node *push(node *head, int data) {

	node *top;

	if (head == NULL) {
		top = head = make_node(data);
		return ; // make node, assign it to head, return new head
	}
	top = top->link = make_node(data);

	return top;
}
node *pop() {
	 
}

node *top() {

}

bool is_empty(node *head) {
	if (head == NULL)
		return true; 
}

int main()
{
	node *top = NULL;
	top = push(top, 3);
	top = push(top, 4);
	top = push(top, 5);
    return 0;
}

