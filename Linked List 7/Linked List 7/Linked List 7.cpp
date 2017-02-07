// Linked List 7.cpp : Defines the entry point for the console application.
// 

#include "stdafx.h"
#include <iostream>

using namespace std;

struct node {
	int data;
	node *link;
};

node *make_node(int data){
	node *newNode = new node; 
	newNode->data = data;
	newNode->link = NULL;

	return newNode;
} 

node *build(node *head) {
	int data;
	node *current = NULL; 

	cout << "Enter integers for the list. Enter 0 to terminate: ";
	cin >> data; 

	while (data != 0) {
		node *next = make_node(data);

		if (head == NULL) head = current = next; 
		else {
			current->link = next;
			current = next;
		}
	cin >> data; 
	}
	return head; 
}

node *insert(node *head, int data, int position) {

	node *current = head; 
	node *next = make_node(data);

	if (position == 0) {
		next->link = current; 
		head = next;
		return head; 
	}
	else {
		for (int i = 0; i <= position - 2; i++) {
			current = current->link;
		}

		next->link = current->link;
		current->link = next;
	}
	return head;
}

node *del(node *head, int position) {
	node *current = head;
	node *temp = NULL;

	if (position == 0) {
		head = head->link;
		delete current;
		return head; 
	}
	else if (position == 1) {
		temp = current->link;
		current->link = temp->link;
		delete temp;

		return head; 
	}

	for (int i = 0; i < position - 1; i++) {
		current = current->link;
	}
	temp = current->link;
	current->link = temp->link; 
	delete temp; 

	return head;
}

node *reverse(node *head) {
	node *prev, *current, *next; 
	prev = NULL;
	next = NULL;
	current = head;

	while (current != NULL) {
		next = current->link;
		current->link = prev; 
		prev = current;
		current = next;
	}
	head = current;

	return prev; 
}

void print(node *current) {
	
	cout << ":";

	while (current != NULL) {
		cout << " " << current->data;
		current = current->link;
	}
}

int main()
{
	node *head = NULL;

	// building and printing original the list
	head = build(head);
	cout << "original list";
	print(head);

	// inserting number at nth point in list and printing result
	head = insert(head, 5, 1);
	cout << endl << "insert 5 at position 1";
	print(head);

	// deleting element at position 2
	head = del(head, 2);
	cout << endl << "delete position 2";
	print(head);

	// reversing latest list
	head = reverse(head);
	cout << endl << "reversed list";
	print(head);

	char f; 
	cin >> f;
    return 0;
}

