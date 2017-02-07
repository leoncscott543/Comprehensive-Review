// Linked List 10.cpp : Defines the entry point for the console application.
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

node *build(node *head, int data) {
	node *current = head; // this code traverses the list 

	if (head == NULL) {
		return make_node(data); // make node, assign it to head, return new head
	}
	while (current->link != NULL) {
		current = current->link;
	}
	node *temp = make_node(data);
	current->link = temp;

	return head;
	

}

void print(node *temp) {
	if (temp == NULL) return;

	cout << temp->data << " ";

	print(temp->link);
}

node *reverse(node* head) {
	node *pre, *nex;
	node *current = head;
	pre = nex = NULL;

	if (head == NULL) {
		return NULL;
	}
	while (current != NULL) {
		nex = current->link;
		current->link = pre;
		pre = current;
		current = nex; 
	}
	head = pre;
	cout << endl << endl;
	print(pre);
}

int main()
{
	node *head = NULL;
	head = build(head, 1);
	head = build(head, 2);
	head = build(head, 3);
	head = build(head, 4);

	print(head);

	reverse(head);

	char f; 
	cin >> f;
    return 0;
}

