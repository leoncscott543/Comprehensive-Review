// Linked List 9.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

struct node {
	int data;
	node *link;
};

node *build(node *head) {
	/*
	1. make current node, set to head and temp node and set it to NULL
	2. ask for user input
	3. base case, if list is empty, fill head with the data
	4. while input doesnt equal 0
	5. temp equals a new node
	6. define temp's elements
	7. set current equal to temp
	8. ask the user for another input
	9. out side of loop
	10. return return head
	*/

	node *current = head; 
	node *temp = NULL;
	int data;

	cout << "Enter numbers for list: " << endl;
	cin >> data;

	// iterative case
	while (data != 0) {
		if (head == NULL) {
			temp = new node;
			temp->data = data;
			temp->link = NULL;
			current = head = temp;
		}
		
		else {
			temp = new node;
			temp->data = data;
			temp->link = NULL;

			current->link = temp;
			current = temp;
		}  
		cin >> data;
	}
	return head;
}

node *reverse(node *head) {
	/*
	1. build prev, cur, and next nodes
	2. prev and next = NULL... cur = head
	3. while current != NULL
	4. next = cur->link
	5. cur->link = prev
	6. prev = cur
	7. cur = next
	8. outide of loop
	9. return prev
	*/

	node *cur = head;
	node *next = NULL; 
	node *prev = NULL;

	while (cur != NULL) {
		next = cur->link;
		cur->link = prev;
		prev = cur;
		cur = next; 
	}
	return prev;
}

void print(node *current) {
	/*
	1. output a semi-colin
	2. traverse through list and...
	3. print each node's data as you go
	*/

	cout << ":";
	while (current != NULL) {
		cout << " " << current->data;

		current = current->link;
	}

}

int main()
{
	node *head = NULL;
	head = build(head);
	print(head);

	head = reverse(head);
	cout << endl << "reversed";
	print(head);

	char f;
	cin >> f;
    return 0;
}

