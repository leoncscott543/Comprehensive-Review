// Linked List 8.cpp : Defines the entry point for the console application.
// 

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

node *build() {
	node *head = NULL; 
	node *current = head;
	int data;

	cout << "Enter data for list: " << endl;
	cin >> data; 

	while (data != 0) {
		node *next = make_node(data); // point next to a heaped node

		if (current == NULL) current = head = next; // base case for making head

		else {
			current->link = next; // point current's link to the next node
			current = next; // move current foward to last node
		}

		cin >> data; // ask user for more data
	}

	return head; // return starting point
}

node *insert(node *head, int data, int position) {
	// define 2 temp nodes
	// set one node to NULL and the other to head
	// make base case for inserting numbers 0 and 1
	// traverse list until we get to two spots before our position
	// make new node
	// point new node's link to current's link 
	// point current's link to new node
	// return head

	node *current = head;
	node *temp = NULL;

	if (position == 0) {
		temp = make_node(data);
		temp->link = head;
		head = temp;

		return head;
	}
	else if (position == 1) {
		temp = make_node(data);

		temp->link = current->link;
		current->link = temp;

		return head;
	}

	for (int i = 0; i <= position - 2; i++) {
		current = current->link;
	}
	temp = make_node(data);

	temp->link = current->link;
	current->link = temp;
	return head;
}

node *del(node *head, int position) {
	/*
	1. make current and temp node
	2. set current to head
	3. set temp to NULL
	4. base case for deleting first and second position
	5. traverse until spot before position
	6. set temp equal to current's link
	7. point current's link to temp's link
	8. delete temp
	9. return head
	*/

	node *current, *temp;
	current = head;
	temp = NULL; 

	// base case 0
	if (position == 0) {
		temp = current->link;
		head = temp;
		delete current;

		return head; 
	}
	else if (position == 1) {
		temp = current->link;
		current->link = temp->link;

		delete temp;
		return head; 
	}

	for (int i = 0; i <= position - 2; i++) {
		current = current->link;
	}
	temp = current->link;
	current->link = temp->link;

	delete temp;

	return head;
}

node *reverse(node *head) {
	/*
	1. make previous, current, and next node pointers
	2. point current to head
	3. set previous and next to NULL
	4. make while loop... ends when current = NULL 
	5. point next to current->link
	6. point current->link to previous
	7. set previous equal to current
	8. set current equal to next... this should all take 4 statements
	9. head = prev
	*/

	node *previous, *current, *next;
	current = head; 
	previous = next = NULL; 

	while (current != NULL) {
		next = current->link;
		current->link = previous;
		previous = current;
		current = next;
	}

	head = previous; 

	return head; // we could have also just returned previous, but this way is easier to read
}

void print(node *temp) {

	while(temp != NULL){
		cout << " " << temp->data;
		temp = temp->link;
	}
}

int main()
{
	node *head = NULL;

	head = build();
	print(head);

	head = insert(head, 0, 2);
	cout << endl; 
	print(head);

	head = del(head, 2);
	cout << endl;
	print(head);

	head = reverse(head);
	cout << endl;
	print(head);

	char f;
	cin >> f;
    return 0;
}

