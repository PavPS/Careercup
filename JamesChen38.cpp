#include "stdafx.h"

/*
Yahoo
Given a set of n integers and sum of all numbers is at most K.
find the subset of these n elements whose sum is exactly half of the total sum
of n numbers
*/

#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

void findSumSubsets(const vector<int> values, const vector<int> used, int target, int sum)
{
	if (target == sum)
	{
		copy(used.begin(), used.end(), ostream_iterator<int>(cout, " "));
		cout << endl;
	}

	for (unsigned i = 0; i < values.size(); ++i)
	{
		const auto sumNew = sum + values[i];

		vector<int> usedNew(used);
		usedNew.push_back(values[i]);

		vector<int> valuesNew(values.begin() + i + 1, values.end());

		findSumSubsets(valuesNew, usedNew, target, sumNew);
	}
}

void findSumSubsets(const vector<int>& values)
{
	int sum = 0;
	std::for_each(values.begin(), values.end(), [&](int v){ sum += v; });
	int halfSum = sum / 2;

	cout << "Target: " << halfSum << endl;
	findSumSubsets(values, vector<int>(), halfSum, 0);
}

void JamesChen38()
{
	findSumSubsets({ 7, 2, 3, 4, 5, 6, 9 });
}
