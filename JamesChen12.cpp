#include "stdafx.h"

/*
Problem
Given an array of integers. Find two disjoint contiguous sub-arrays such that the absolute difference between the sum of two sub-array is maximum.
* The sub-arrays should not overlap.

eg- [2 -1 -2 1 -4 2 8] ans - (-1 -2 1 -4) (2 8), diff = 16

O(n) is required.
*/

#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

void JamesChen12()
{
	const auto ArraySize = 10;
	cout << "        ";
	vector<int> values;
	for (unsigned i = 0; i < ArraySize; ++i)
	{
		values.push_back(rand() % 10 - 5);
		cout << "#" << setfill('0') << setw(2) << i << " ";
	}
	cout << endl;

	cout.fill(' ');

	cout << "values: ";
	for (const auto& v : values)
		cout << " " << setw(2) << v << " ";
	cout << endl;

}