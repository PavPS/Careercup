#include "stdafx.h"

/*
Problem
Consider an array of integers wherein each element is +1 or -1 its preceding element. Given a number, find the first occurence of this number (index) in this array without using linear search.

For example, consider the array :
4 5 6 5 6 7 8 9 10 9 10 (each element in this array is +1 or -1 its preceding element)

Input : 10 (find first occurence of 10 without using linear search)
Output : 8
*/

#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

// Not efficient. We must take ABS
int findStrange(const vector<int>& values, int value)
{
	int i = 0;
	for (unsigned iter = 0; iter < values.size(); ++iter)
	{
		const auto& current = values[i];
		if (current == value)
			return i;

		const auto nextBestIndex = i + (value - current);
		unsigned possibleIndex;
		if (nextBestIndex >= (int)values.size())
			possibleIndex = values.size() - 1;
		else if (nextBestIndex < 0)
			possibleIndex = 0;
		else
			possibleIndex = nextBestIndex;

		if (i == (int)possibleIndex)
			break;

		i = possibleIndex;

	};


	return -1;
}

void JamesChen41()
{
	vector<int> values{ 4, 5, 6, 5, 6, 7, 8, 9, 10, 9, 10, };

	cout.fill(' ');
	cout << "values: "; for (const auto& v : values)cout << " " << setw(2) << v << " "; cout << endl;

	const int valueOfInterest = 8;
	cout << "Value " << valueOfInterest << " is at intdex " << findStrange(values, valueOfInterest) << endl;
}
