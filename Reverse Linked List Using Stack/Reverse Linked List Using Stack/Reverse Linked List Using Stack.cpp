// Reverse Linked List Using Stack.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <stack>

using namespace std;

stack<struct node*> S;

struct node {
	int data;
	node *next;
};


node *reverse(node *head, int data) {
	node *temp = S.top();
	head = temp;
	S.top();

	while (!S.empty()) {
		temp->next = S.top();
		S.pop();
		temp = temp->next;
	}
	temp->next = NULL;

	return head;
}


int main()
{

    return 0;
}

