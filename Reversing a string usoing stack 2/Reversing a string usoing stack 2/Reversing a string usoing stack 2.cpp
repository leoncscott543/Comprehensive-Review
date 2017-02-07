// Reversing a string usoing stack 2.cpp : Defines the entry point for the console application.
// this program takes a string, reverses it, and prints it out on the console
// we are doing this using a stack 

#include "stdafx.h"
#include <iostream>
#include <stack>

using namespace std;

void reverse(char *C, int n) {
	stack<char> S;

	for (int i = 0; i < n; i++) {
		S.push(C[i]);
	}

	for (int i = 0; i < n; i++) {
		C[i] = S.top();
		S.pop();
	}
}

int main()
{


	char f;
	cin >> f;
    return 0;
}

