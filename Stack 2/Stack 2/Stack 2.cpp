// Stack 2.cpp : Defines the entry point for the console application.
// Array based stack implementation 

#include "stdafx.h"
#include <iostream>

using namespace std;

#define MAX_SIZE 10

int A[MAX_SIZE];
int top = -1;

void Push(int x) {
	if (top == MAX_SIZE - 1) {
		cout << "Error: stack overflow\n";
	}

	A[++top] = x;
}

int main(){

    return 0;
}

