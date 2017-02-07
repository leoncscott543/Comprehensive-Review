// Reverse a String using Stack.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

struct node {
	char data; 
	node *link;
};

node *push(node *top, char word[51]) {
	// increment for looping through string in recrusive case
	int i = 1;

	// base case
	if (top == NULL) {
		top->data = 'a';
		top->link = NULL;
	}

	// recursive case
	while (word[i] != NULL) {
	node *newNode = new node;
	newNode->data = word[i];
	newNode->link = top;

	i++;

	top = push(newNode, word); 
	}

	return top;
}

void print(node *top) {
	if (top == NULL) return;

	cout << top->data << " ";

	print(top->link);
}

int main()
{
	node *top = NULL;
	char word[51]; 

	cout << "Enter a word to reverse: ";
	cin >> word; 

	top = push(top, word);


	cout << endl << endl << "Reversed word: ";
	print(top);


	char f; 
	cin >> f;
    return 0;
}

