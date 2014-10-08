#include "stdafx.h"

/*
Problem
Given an array containing (0..n-1) but in random order, you can only loop through the array once and use swap operation, please sort the array.
*/

#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

void JamesChen18()
{
	const auto ArraySize = 10;
	cout << "        ";
	vector<int> values;
	for (unsigned i = 0; i < ArraySize; ++i)
	{
		values.push_back(i);
		cout << "#" << setfill('0') << setw(2) << i << " ";
	}
	cout << endl;

	random_shuffle(values.begin(), values.end());

	cout.fill(' ');
	cout << "values: "; for (const auto& v : values)cout << " " << setw(2) << v << " "; cout << endl;

	for (unsigned i = 0; i < values.size();)
	{
		auto& current = values[i];
		if (i == (unsigned)current)
		{
			++i;
			continue;
		}

		auto& must = values[current];
		swap(must, current);
	}

	cout << "sorted: "; for (const auto& v : values)cout << " " << setw(2) << v << " "; cout << endl;
}
