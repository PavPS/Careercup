#include "stdafx.h"

/*
Given a sorted array of n integers that has been rotated an unknown number of times, give an O(log n) algorithm that finds an element in the array. 
You may assume that the array was originally sorted in increasing order.
EXAMPLE:
Input: find 5 in array (15 16 19 20 25 1 3 4 5 7 10 14)
Output: 8 (the index of 5 in the array)
*/

#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

int bsearchTricky2rec(const vector<int>& values, int value, int left, int right)
{
	if (left == right)
		return -1;

	if (right - left == 1)
	{
		if (values[0] == value)
			return 0;
		return -1;
	}

	const auto valueGetter = [&values](int index)->int{return values[index];};

	if (valueGetter(left) > valueGetter(right))
	{
		const auto middle = left + (right - left) / 2;
		auto found = bsearchTricky2rec(values, value, left, middle);
		if (found >= 0)
			return found;

		found = bsearchTricky2rec(values, value, middle, right);
		if (found >= 0)
			return found;
	}

	while(left < right)
	{
		const auto center = left + (right - left) / 2;
		const auto& centerValue = valueGetter(center);

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

int bsearchTricky2(const vector<int>& values, int value)
{
	return bsearchTricky2rec(values, value, 0, values.size() - 1);
}

int bsearchTricky1(const vector<int>& values, int value)
{
	if (values.size() < 2)
	{
		if (values[0] == value)
			return 0;
		return -1;
	}

	unsigned rotated = 0;
	for (unsigned i = 1; i < values.size(); ++i)
		if (values[i-1] > values[i])
		{
			rotated = i;
			cout << "Rotation: " << rotated << endl;
			break;
		}

	const auto valueGetter = [&values, &rotated](int index)->int{return values[(index + rotated) % values.size()];};

	unsigned left = 0, right = values.size() - 1;
	while(left < right)
	{
		const auto center = left + (right - left) / 2;
		const auto& centerValue = valueGetter(center);

		if (value < centerValue)
		{
			right = center - 1;
		}
		else if (centerValue < value)
		{
			left = center + 1;
		}
		else return center + rotated;
	}

	if (valueGetter(left) == value)
		return left + rotated;

	return -1;
}

void JamesChen37()
{
	vector<int> values{15, 16, 19, 20, 25, 1, 3, 4, 5, 7, 10, 14};

	cout.fill(' ');
	cout << "values: "; for (const auto& v : values)cout << " " << setw(2) << v << " "; cout << endl;

	cout << "1. Index found: " << bsearchTricky1(values, 5) << endl;
	cout << "2. Index found: " << bsearchTricky2(values, 5) << endl;
}

#if !defined(_MSC_VER)
int main()
{
	JamesChen37();
	return 0;
}
#endif
