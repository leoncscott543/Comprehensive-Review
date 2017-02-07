// Factorial.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int fact(int n)
{
	if (n == 0 || 1)
		return 0;

	else
		return n*fact(n - 1);
}

int main()
{
	fact(10);

	char f; 
	cin >> f;
    return 0;
}

