#include "stdafx.h"

/*
Given two integer arrays. Find the Largest Common sub array. For example,
arr1 = {1,2,3,2,3,2} arr2={2,2,3,3,4,5}, the largest common sub array is {2,2,3,3}
*/

#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>
#include <vector>
#include <memory>
#include <assert.h>

using namespace std;

// The task in not fine. This algoritm finds largest summ index-growing subarray
void printLCSA2(const vector<int>& arr1, const vector<int>& arr2)
{
	vector<int> sorted1(arr1);
	vector<int> sorted2(arr2);
	vector<int> result;

	sort(sorted2.begin(), sorted2.end());
	sort(sorted1.begin(), sorted1.end());

	auto iter2 = sorted2.begin();
	for (const auto& iter1 : sorted1)
	{
		while(sorted2.end() != iter2 && iter1 != *iter2 && *iter2 < iter1) 
			++iter2;

		if (sorted2.end() == iter2)
			break;

		if (*iter2 == iter1)
		{
			result.push_back(iter1);
			++iter2;
		}
	}

	if (result.empty())
	{
		cout << "No matches." << endl;
		return;
	}

	cout << "Match2: "; for (const auto& v : result)cout << setw(2) << v << " "; cout << endl;
}

// The task in not fine. This algoritm finds largest common substring (subarray)
void printLCSA1(const vector<int>& arr1, const vector<int>& arr2)
{
	vector<int> matrix;
	unsigned maxLength = 0;
	pair<unsigned, unsigned> head { 0, 0 };

	for (unsigned row = 0; row < arr2.size(); ++row)
		for (unsigned column = 0; column < arr1.size(); ++column)
		{
			bool match = arr1[column] == arr2[row];
			const unsigned prevValue = (row > 0 && column > 0)? matrix[(row - 1) * arr1.size() + (column - 1)] : 0;
			unsigned matchValue = match ? 1 + prevValue : 0;
			if (matchValue > maxLength)
			{
				maxLength = matchValue;
				head = make_pair(row - (matchValue - 1), column - (matchValue - 1));
			}
			matrix.push_back(matchValue);
		}

	assert(matrix.size() == arr1.size() * arr2.size());

	if (!maxLength)
	{
		cout << "No matches." << endl;
		return;
	}

	cout << "Match1: ";
	for (unsigned i = 0; i < maxLength; ++i)
		cout  << setw(2) << arr2[head.first + i] << " ";
	cout << endl;
}

void NetApp1()
{
	vector<int> arr1 {1,2,3,2,3,2};
	vector<int> arr2 {2,2,3,3,4,5};

	cout << "arr1:   "; for (const auto& v : arr1)cout << setw(2) << v << " "; cout << endl;
	cout << "arr2:   "; for (const auto& v : arr2)cout << setw(2) << v << " "; cout << endl;

	printLCSA1(arr1, arr2);
	printLCSA2(arr1, arr2);
}

#if !defined(_MSC_VER)
int main()
{
	NetApp1();
	return 0;
}
#endif
