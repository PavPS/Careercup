#include "stdafx.h"

/*
Problem
Write a method which finds the maximum of two numbers. You should not use if-else or any other comparison operator.
EXAMPLE
Input: 5, 10
Output: 10
*/

#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

int max_without_if(int a, int b)
{
	return a + (a - b) * ((a - b) >> 31);
}

void JamesChen20()
{
	const int value1 = 5;
	const int value2 = 10;

	cout << "value1: " << value1 << endl;
	cout << "value2: " << value2 << endl;

	cout << "max = " << max_without_if(value1, value2) << endl;
}
