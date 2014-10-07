#include "stdafx.h"

/*
Problem
You are given two sorted arrays of size n and n+m respectively.
Merge these two sorted arrays without using a third array and the resultant array must be sorted ?

For eg.
arr1 (size 3): {1, 4, 6}
arr2 (size 8): {2, 3, 5, 7, 8, null, null, null}

Result must be in arr2 as :
arr2 (size 8): {1, 2, 3, 4, 5, 6, 7}
*/

#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

void JamesChen14()
{
	const auto ArraySize = 5;
	cout << "        ";
	vector<int> values1, values2;
	for (unsigned i = 0; i < ArraySize; ++i)
	{
		values1.push_back(rand() % 10 - 4);
		values2.push_back(rand() % 10 - 1);
		cout << "#" << setfill('0') << setw(2) << i << " ";
	}
	cout << endl;

	cout.fill(' ');

	sort(values1.begin(), values1.end());
	sort(values2.begin(), values2.end());

	cout << "values1:"; for (const auto& v : values1) cout << " " << setw(2) << v << " "; cout << endl;
	cout << "values2:"; for (const auto& v : values2) cout << " " << setw(2) << v << " "; cout << endl;

	values2.resize(values1.size() + values2.size());

	cout << "Target array is 'values2' has size: " << values2.size() << endl;

	int v1Index = ArraySize - 1;
	int v2Index = ArraySize - 1;
	unsigned putter = values2.size() - 1;

	for (unsigned i = 0; i < ArraySize * 2; ++i)
	{
		const auto& v1 = v1Index >= 0 ? values1[v1Index] : values2[v2Index];
		const auto& v2 = v2Index >= 0 ? values2[v2Index] : values1[v1Index];
		const auto& toBeInserted = max(v1, v2);
		values2[putter--] = toBeInserted;

		if (v1Index >= 0 && v1 == toBeInserted)
			--v1Index;
		else if (v2Index >= 0 && v2 == toBeInserted)
			--v2Index;
	}

	cout << "values2:"; for (const auto& v : values2) cout << " " << setw(2) << v << " "; cout << endl;
}