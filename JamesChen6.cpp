#include "stdafx.h"

/*
Problem
Given 2 binary arrays A and B i.e. containing only 0s and 1s each of size N.
Find indices i,j such that Sum of elements from i to j in both arrays is equal and j-i
(i.e. the length of the set i,j) is the maximum possible value.

Solution
O(n) solution
*/

#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

void JamesChen6()
{
	const unsigned arraySize = 10;
	vector<unsigned> v1, v2;
	//srand(123);
	for (unsigned i = 0; i < arraySize; ++i)
	{
		v1.push_back(rand() % 2);
		v2.push_back(rand() % 2);
	}

	cout << "v1: ";
	for (const auto& v : v1)
		cout << v << " ";
	cout << endl;

	cout << "v2: ";
	for (const auto& v : v2)
		cout << v << " ";
	cout << endl;

	for (unsigned i = 1; i < arraySize; ++i)
	{
		v1[i] += v1[i - 1];
		v2[i] += v2[i - 1];
	}

	// This is wrong solution and solves: maximum sum and i-j delta
	/*
	unsigned iterationCount = 0;
	unsigned good_sum = 0;
	pair<unsigned, unsigned> good_pair;
	unsigned tailCompensation1 = 0, tailCompensation2 = 0;
	for (unsigned i = 0; i < arraySize; ++i)
	{
		iterationCount += (int)(log2(arraySize - i) + 0.5);

		auto startPoint = upper_bound(v1.begin() + i, v1.end(), good_sum + tailCompensation1);
		if (startPoint == v1.end()) break;

		for (; startPoint != v1.end(); ++startPoint)
		{
			++iterationCount;

			const auto j = startPoint - v1.begin();
			const auto sum1 = *startPoint - tailCompensation1;
			const auto sum2 = v2[j] - tailCompensation2;

			if (sum1 == sum2)
			{
				good_sum = sum1;
				good_pair = make_pair(i, j);
			}
			else
			{
				break;
			}
		}

		tailCompensation1 = v1[i];
		tailCompensation2 = v2[i];
	}
	*/	

	/*
	cout << "Sum is: " << good_sum << endl;
	cout << "Pair is:    " << good_pair.first << "-" << good_pair.second << endl;
	cout << "Interations:" << iterationCount << endl;
	*/


	// This algowithm is from orginal web site and it is not correct.
	//unsigned maxDiff(0);
	//unsigned low = 0, up = 0;

	//unordered_map<int, pair<int, int>> um;

	//for (unsigned i = 0; i < v1.size(); ++i){
	//	if (um.find(v1[i] - v2[i]) != um.end()){
	//		um[v1[i] - v2[i]] = pair<int, int>(um[v1[i] - v2[i]].first, i);

	//		unsigned diff = um[v1[i] - v2[i]].second - um[v1[i] - v2[i]].first;
	//		if (diff > maxDiff){
	//			maxDiff = diff;
	//			low = um[v1[i] - v2[i]].first;
	//			up = um[v1[i] - v2[i]].second;
	//		}
	//	}
	//	else{
	//		um[v1[i] - v2[i]] = pair<int, int>(i, i);
	//	}
	//}

	//up--;


	//cout << "Pair is:    " << low << "-" << up << endl;

	vector<unsigned> aux;
	unsigned count = 0;
	for (unsigned i = 0; i < arraySize; ++i)
	{
		if (v1[i] == v2[i])
			count++;

		aux.push_back(count);
	}

	pair<unsigned, unsigned> good_pair;

	cout << "Pair is:    " << good_pair.first << "-" << good_pair.second << endl;
}