#include "stdafx.h"

/*
Problem
Given a strictly sorted (increasing) array, find an elements whose value is equal to its index i.e. a[i] = i ?
The running time of the solution must be O(logn)
*/

#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

// WARNING!!! STRICTLY MEANS: no duplicates
int getIndexValue(const vector<int>& values)
{
	int left = 0, right = values.size() - 1;
	while (left <= right)
	{
		const auto center = left + (right - left) / 2;
		const auto& centerValue = values[center];
		const auto& value = center;

		if (value < centerValue)
		{
			right = center - 1;
		}
		else if (centerValue < value)
		{
			left = center + 1;
		}
		else return center;
	}

	return -1;
}

void JamesChen39()
{
	const auto ArraySize = 15;
	cout << "        ";
	vector<int> values;
	for (; values.size() < ArraySize;)
	{
		const auto value = rand() % 17;
		if (values.end() == find(values.begin(), values.end(), value))
		{
			values.push_back(value);
			cout << "#" << setfill('0') << setw(2) << values.size() - 1 << " ";
		}
	}
	cout << endl;

	sort(values.begin(), values.end());

	cout.fill(' ');
	cout << "values: "; for (const auto& v : values)cout << " " << setw(2) << v << " "; cout << endl;

	cout << "Result:  " << getIndexValue(values) << endl;
}
