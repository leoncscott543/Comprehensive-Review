// Binary Tree.cpp : Defines the entry point for the console application.
// building a tree recursively real quick	

#include "stdafx.h"
#include <iostream>
#include <stack>

// time complexity is 0(n)
// there is extra space taken up by pushing data on stack.... 0(n)

using namespace std; 

void Reverse(char C[], int n) {
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
	char C[51];
	cout << "enter a string: ";
	cin >> C;
	Reverse(C, strlen(C));
	cout << "Output = " << C;

	char f; 
	cin >> f;
    return 0;
}

