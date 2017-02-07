// Vectors.cpp : Defines the entry point for the console application.
// learning how to implement a vector

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std; 

int main()
{
	vector<int> myVector; 
	myVector.push_back(4);
	myVector.push_back(10);
	myVector.push_back(55);
	myVector.push_back(100);
	
	for (unsigned int i = 0; i < myVector.size(); i++) {
		cout << myVector[i] << " ";
	}

	myVector.insert(myVector.begin() + 2, 15);

	cout << endl;
	for (unsigned int i = 0; i < myVector.size(); i++) {
		cout << myVector[i] << " ";
	}
	char f;
	cin >> f;
    return 0;
}

