#if defined(_MSC_VER)
#include "stdafx.h"
#endif

/*
Find the continuous sequence with the largest sum
Question
You are given an array of integers (both positive and negative). Find the continuous sequence with the largest sum. Return the sum.
EXAMPLE
Input: {2, -8, 3, -2, 4, -10}
Output: 5 (i. e. , {3, -2, 4} )
*/

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void JamesChen8()
{
	vector<int> values;
	for (unsigned i = 0; i < 10; ++i)
		values.push_back(rand() % 20 - 10);

	cout << "values: ";
	for (const auto& v : values)
		cout << v << " ";
	cout << endl;

	int sum = numeric_limits<int>::min();
	int tail = 0;
	pair<int, int> indices {0, 0};
	int sumTmp = 0;
	for (unsigned head = 0; head < values.size(); ++head)
	{
		sumTmp += values[head];
		if (sum <= sumTmp)
		{
			sum = sumTmp;
			indices.first = tail;
			indices.second = head + 1;
		}

		if ( sumTmp <= 0 /* < 0 */)
		{
			tail = head + 1;
			sumTmp = 0;
		}
	}

	cout << "Max sum is: " << sum << endl;
	cout << "Range: " << indices.first << "-" << indices.second << endl;
}

#if !defined(_MSC_VER)
int main()
{
	JamesChen8();
	return 0;
}
#endif