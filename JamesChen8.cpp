//#if defined(_MSC_VER)
#include "stdafx.h"
//#endif

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
	for (unsigned i = 0; i < 20; ++i)
		values.push_back(rand() % 20 - 10);

	cout << "values: ";
	for (const auto& v : values)
		cout << v << " ";
	cout << endl;

	/* Max sum and according indices*/
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
	cout << "Range: [" << indices.first << "; " << indices.second << ")" << endl;

	/* Just max sum */
	sum = numeric_limits<int>::min();
	sumTmp = 0;
	for (unsigned head = 0; head < values.size(); ++head)
	{
		sumTmp += values[head];
		if (sum < sumTmp) sum = sumTmp;
		if ( sumTmp < 0 ) sumTmp = 0;
	}

	cout << "Just max sum is: " << sum << endl;

	/* Max sum and according indices of GROWING sequence*/
	sum = numeric_limits<int>::min();
	tail = 0;
	indices = {0, 0};
	sumTmp = 0;
	for (unsigned head = 0; head < values.size(); ++head)
	{
		sumTmp += values[head];

		const bool growing = values[head - (head ? 1 : 0)] <= values[head];
		if (growing && sum <= sumTmp)
		{
			sum = sumTmp;
			indices.first = tail;
			indices.second = head + 1;
		}

		if ( !growing || sumTmp <= 0 )
		{
			tail = head;
			sumTmp = max(0, values[head]);
			if (sumTmp < 0)
				tail++;
		}
	}

	cout << "Max sum of growing range is: " << sum << endl;
	cout << "Growing range: [" << indices.first << "; " << indices.second << ")" << endl;

}

#if !defined(_MSC_VER)
int main()
{
	JamesChen8();
	return 0;
}
#endif