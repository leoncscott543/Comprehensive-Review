// linked list 5.cpp : Defines the entry point for the console application.
/*
algorithm:
1. make node struct (chk)
2. initialize head struct in main to NULL (chk)
3. create make_node() function
4. create build() function
5. call function from  main
6. create print() function and call it from main 
*/

#include "stdafx.h"
#include <iostream>

using namespace std;

// node structure
struct node {
	int data;
	node *link;
};

// traverses list forward and prints each element
void print(node* temp) {

	cout << endl << "here is your list : ";

	// loop that traverses list
	while (temp != NULL) {
		cout << temp->data << "  ";
		temp = temp->link;
	}
}

// dont need to do this, but it helps keep everything in organized and optimizable 
node *make_node(int data) {

	// this function returns a newly created node whenever we need to make one
	node *newNode = new node;
	newNode->link = NULL;
	newNode->data = data;

	return newNode;
}

// function builds the list with user inputs
node *build() {

	// must initialize nodes to NULL
	node *head = NULL;
	node *cur = NULL;
	int data = 0;

	// user enters first node's data
	cout << "Enter numbers into list: " << endl;
	cin >> data;


	while (data != 0) {

		// creating new everytime a user enters a number.... pointing our temperary node to that heaped node
		node *temp = make_node(data);

		if (head == NULL) head = cur = temp;
		else {
			cur->link = temp;
			cur = temp;
		}

		cin >> data;
	}
	return head;
}

// insert data anywhere in list 
node *insert(node *head, int data, int position) {
	node *temp = make_node(data);
	
		node *current = head; 

		// traverse until we reach position before the index where we want to insert our new information
		for (int i = 0; i <= position-2; i++) {
			current = current->link;
		}
		
		// insert new node into list
		temp->link = current->link;
		current->link = temp;
	
	return head; 
}

// deletes a node at discrete position
node *delete_node(node *head, int position) {
	node *temp = head; 
	node *temp2 = head->link;
	
	// traverse till we get to the position
	for (int i = 0; i < position-1; i++) {
		temp = temp->link;
		temp2 = temp2->link;
	}
	temp->link = temp2->link;
	delete temp2;

	return head; 
}

node *reverse(node *head) {
	node *current, *next, *previous; 
	current = head;
	previous = NULL;
	next = NULL;

	while (current != NULL) {
		next = current->link;
		current->link = previous; 
		previous = current; 
		current = next;
	}

	head = previous; 

	return head; 
}
int main()
{
	// initializing head node to NULL
	node *head = NULL;

	cout << "original list: ";
	head = build();
	print(head);

	cout << endl << "inserting 5 at position 0: ";
	head = insert(head, 0, 0);
	print(head);

	cout << endl << "inserting 3 at position 2: ";
	head = insert(head, 3, 2);
	print(head);

	cout << endl << "deleting position number 6: ";
	head = delete_node(head, 6);
	print(head);

	cout << endl << "reversing list: ";
	head = reverse(head);
	print(head);

	char f;
	cin >> f;
	return 0;
}

