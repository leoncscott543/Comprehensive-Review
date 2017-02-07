// linked list 5.cpp : Defines the entry point for the console application.
/*
algorithm:
1. make node struct (chk)
2. initialize head struct in main to NULL (chk)
3. make insert function
4. make newNode function
5. pass some numbers onto the list
*/

#include "stdafx.h"
#include <iostream>

using namespace std;

struct node {
	int data;
	node *link;
};

void print(node *temp);

node *make_node(int data) {
	node *newNode = new node;
	newNode->link = NULL;
	newNode->data = data;

	return newNode;
}

//node *build(node *head, node *temp, int data) {
//	if (head == NULL) {
//		head = make_node(data);
//		temp = head;
//		return head; 
//	}
//	else {
//		temp->link = make_node(data);
//		temp = temp->link;
//		return temp;
//	}
//}

node *build() {
	node *head = NULL;
	node *cur = NULL;	
	int data = 0;

	cout << "Enter numbers into list: " << endl;
	cin >> data;


	while (data != 0) {
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


void print(node* temp) {

	cout << endl << "here is your list : ";

	while (temp != NULL) {
		cout << temp->data << "  ";
		temp = temp->link;
	}
}


int main()
{
	
	node *head = NULL;
	head = build();


	print(head);

	char f;
	cin >> f;
    return 0;
}

