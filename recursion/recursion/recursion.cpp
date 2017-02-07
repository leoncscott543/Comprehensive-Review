// recursion.cpp :Defines the entry point for the console application.
// this program prints all the numbers from 0 to n backwards using recursion. 

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

int Print(int n)
{
	if (n == 0)
	{
		return 0;
	}

	else {
		cout << n;

		return Print(n - 1); // recursive step
	}
}

int main()
{
	Print(10);

	char f;
	cin >> f;
    return 0;
}

