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
	const auto ArraySize = 15;
	cout << "        ";
	vector<int> values;
	for (unsigned i = 0; i < ArraySize; ++i)
	{
		values.push_back(rand() % 10 - 4);
		cout << "#" << setfill('0') << setw(2) << i << " ";
	}
	cout << endl;

	cout.fill(' ');

	values = { 2, 3, 1, 2, 3, 4 };

	cout << "values: ";
	for (const auto& v : values)
		cout << " " << setw(2) << v << " ";
	cout << endl;

	int max_tail = 0, max_head = 0, max_sum = numeric_limits<int>::min();
	int sum = 0, tail = 0;
	for (unsigned i = 0; i < values.size(); ++i)
	{
		sum += values[i];
		if (sum > max_sum)
		{
			max_sum = sum;
			max_tail = tail;
			max_head = i;
		}
		if (sum <= 0)
		{
			sum = 0;
			tail = i + 1;
		}
	}

	cout << "Max sum is:  " << max_sum << endl;
	cout << "Max tail is: " << max_tail << endl;
	cout << "Max head is: " << max_head << endl;

	// No solution so far....
	// Original solution from site IS NOT CORRECT
	//values = { 1, 2, 3, -4, -1, 4, 5 };
	/*
    int minSum = values[0];
    int maxSum = values[0];

    int maxStart = 0, minStart = 0, minEnd = 0, maxEnd = 0;

    int currMinStart = 0;
    int currMinEnd = 0;
    int currMaxStart = 0;
    int currMaxEnd = 0;
    int currMinSum = 0;
    int currMaxSum = 0;

    for(int i = 0; i < values.size(); ++i){
        currMaxSum += values[i];

        if(maxSum < currMaxSum){
            maxSum = currMaxSum;
        }
        else if (currMaxSum < 0){
            currMaxSum = 0;
            currMaxStart = i + 1;
        }

        if(currMaxSum == maxSum){
            maxStart = currMaxStart;
            maxEnd = i;
        }

        currMinSum += values[i];
        if(minSum > currMinSum){
            minSum = currMinSum;
        }
        else if(currMinSum > 0){
            currMinSum = 0;
            currMinStart = i + 1;
        }

        if(currMinSum == minSum){
            minStart = currMinStart;
            minEnd = i;
        }
    }

	cout << "Site solution MAX: " << maxSum << endl;
	cout << "Site solution MIN: " << minSum << endl;
	*/

	int min_tail = 0, min_head = 0, min_sum = numeric_limits<int>::max();
	sum = 0, tail = 0;
	for (unsigned i = 0; i < values.size(); ++i)
	{
		sum += values[i];
		if (sum < min_sum)
		{
			min_sum = sum;
			min_tail = tail;
			min_head = i;
		}
		if (sum >= 0)
		{
			sum = 0;
			tail = i + 1;
		}
	}

	cout << "Min sum is:  " << min_sum << endl;
	cout << "Min tail is: " << min_tail << endl;
	cout << "Min head is: " << min_head << endl;

	/*
	Next just concern 2 cases
	1. do not overlap
	2. overlap
	*/
}

#if !defined(_MSC_VER)
int main()
{
	JamesChen12();
	return 0;
}
#endif