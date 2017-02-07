// Check Root.cpp : Defines the entry point for the console application.
// see if integer is a root of 2.... aka if it 2 divides into it evenly
// multiply 2 until it equals integer.... TRUE, if its greater than integer, return FALSE
// use recursion

#include "stdafx.h"
#include <iostream>

using namespace std; 

bool check(double num) {
	// base cases 

	if (num == 1 || num == 0) return true;
	else if (num < 1) return false; 

	// recursive case
	return check(num = num / 2);
}

int main()
{
	if (check(0) == true) cout << "this is a root of 2";
	else cout << "not a root of 2";

	char f;
	cin >> f;
    return 0;
}

