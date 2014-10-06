#include "stdafx.h"

/*
Problem
Given 3 Arrays of integer sorted in ascending order, get the sum of minimum difference using one element from each array.

where a, b, c are the elements from each array.

diff = |a-b| + |b-c|+|c-a|

complexitiy: worst case O(n)
*/

#include <vector>
#include <algorithm>
#include <iostream>
#include <tuple>

using namespace std;

void JamesChen7()
{
	/*
	const unsigned arraySize = 10;
	vector<int> v1, v2, v3;
	srand(123);
	for (unsigned i = 0; i < arraySize; ++i)
	{
	v1.push_back(rand() % 10 + 3);
	v2.push_back(rand() % 10 + 4);
	v3.push_back(rand() % 10 + 5);
	}
	*/

	vector<int> v1{ 1, 2, 3, 4, 5, 10, 11, 12 };
	vector<int> v2{ 5, 6, 7, 7, 7, 8, 11, 13 };
	vector<int> v3{ 2, 30, 40, 50, 50, 110, 200 };

	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	sort(v3.begin(), v3.end());

	cout << "v1: ";
	for (const auto& v : v1)
		cout << v << " ";
	cout << endl;

	cout << "v2: ";
	for (const auto& v : v2)
		cout << v << " ";
	cout << endl;

	cout << "v3: ";
	for (const auto& v : v3)
		cout << v << " ";
	cout << endl;

	size_t maxSize = max(v1.size(), max(v2.size(), v3.size()));

	unsigned minDiff = numeric_limits<unsigned>::max();
	unsigned a = 0, b = 0, c = 0;
	typedef tuple<unsigned, unsigned, unsigned> TupleType;
	TupleType solution{ 0, 0, 0 };

	for (unsigned i = 0; i < maxSize; ++i)
	{
		int diff12New = v1[a] - v2[b];
		int diff13New = v1[a] - v3[c];
		int diff23New = v2[b] - v3[c];

		unsigned diff = abs(diff12New) + abs(diff13New) + abs(diff23New);
		if (diff < minDiff) 
		{
			minDiff = diff;
			solution = make_tuple(a, b, c);
		}
		if (diff == 0) break;

		auto minOfThree = min(v1[a], min(v2[b], v3[c]));
		if (v1[a] == minOfThree) a++;
		if (v2[b] == minOfThree) b++;
		if (v3[c] == minOfThree) c++;
	}

	cout << "a = " << get<0>(solution) << endl;
	cout << "b = " << get<1>(solution) << endl;
	cout << "c = " << get<2>(solution) << endl;
	cout << "minDiff = " << minDiff << endl;

	//unsigned i(0);
	//unsigned j(0);
	//unsigned k(0);

	//long long minSum = numeric_limits<long long>::max();
	//auto min3 = [](int a, int b, int c){ return min(a, min(b, c)); };
	//auto max3 = [](int a, int b, int c){ return max(a, max(b, c)); };

	//while (i < v1.size() && j < v2.size() && k < v3.size()){
	//	long long sum = 2 * (max3(v1[i], v2[j], v3[k])
	//		- min3(v1[i], v2[j], v3[k]));

	//	if (sum < minSum) minSum = sum;
	//	if (minSum == 0) {  break; };

	//	int m3 = min3(v1[i], v2[j], v3[k]);

	//	if (m3 == v1[i]) i++;
	//	if (m3 == v2[j]) j++;
	//	if (m3 == v3[k]) k++;
	//}

	//cout << "a = " << i << endl;
	//cout << "b = " << j << endl;
	//cout << "c = " << k << endl;
	//cout << "minSum = " << minSum << endl;
}