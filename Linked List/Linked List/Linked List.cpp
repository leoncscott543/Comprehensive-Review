// Linked List.cpp : Defines the entry point for the console application.
// simple linked list stuff
/*
Algorithm:
build node struct
define head as NULL
*/

#include "stdafx.h"
#include <iostream>

using namespace std;

struct node {
	int data; 
	node *link;
};

// this simply inserts a node at the end of the list... time complexity for this absolutely sucks
// space complexity for this 0(n)
node *build(node *head, int data){
	node *temp = head; 
	
	if (temp == NULL) {
		temp = head = new node; 
		temp->data = data;
		temp->link = NULL;
	}
	else {

		while (temp->link != NULL)
		{
			temp = temp->link;
		}
		temp = new node;
		temp->data = data;
		temp->link = NULL;
	}

	return head;
}

void print(node *temp) { // prints the list in conccurent order 

	cout << temp->data << " ";

	if (temp->link == NULL) return; 

	// recursive case

	print(temp->link);

}

int main()
{
	node *head = NULL;

	head = build(head, 15);
	head = build(head, 10);
	head = build(head, 1);
	head = build(head, 24);
	head = build(head, 22);

	print(head);

	char f; 
	cin >> f;
    return 0;
}

