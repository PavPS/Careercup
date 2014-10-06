#include "stdafx.h"

/*
Problem
there are three shorted int Array
A1: {2,4,9,16,19,68,78}
A2:	{4,8,67,106,109,115,120}
A3:	{9,15,19,108,119,130,190}

write an efficient algo to get the top 5 largest number from these three arrays.

Function would be like

int[] top5LargestNumber(int[] A1,int[] A2,int[] A3)
*/

#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

void JamesChen11()
{
	const auto ArraySize = 10;
	cout << "        ";
	vector<int> values1, values2, values3;
	for (unsigned i = 0; i < ArraySize; ++i)
	{
		values1.push_back(rand() % 10);
		values2.push_back(rand() % 10);
		values3.push_back(rand() % 10);
		cout << "#" << setfill('0') << setw(2) << i << " ";
	}
	cout << endl;
	cout.fill(' ');

	sort(values1.begin(), values1.end());
	sort(values2.begin(), values2.end());
	sort(values3.begin(), values3.end());

	cout << "values1: ";
	for (const auto& v : values1)
		cout << " " << setw(2) << v << " ";
	cout << endl;

	cout << "values2: ";
	for (const auto& v : values2)
		cout << " " << setw(2) << v << " ";
	cout << endl;

	cout << "values3: ";
	for (const auto& v : values3)
		cout << " " << setw(2) << v << " ";
	cout << endl;

	/*           SOLUTION            */
	auto i1 = --values1.end();
	auto i2 = --values2.end();
	auto i3 = --values3.end();

	vector<int> found;
	for (unsigned i = 0; i < 5; ++i)
	{
		// WARNING: here is bug with iterator decrement for too short arrays
		const auto maxValue = max(*i1, max(*i2, *i3));
		found.push_back(maxValue);

		if (maxValue == *i1)
			--i1;
		else if (maxValue == *i2)
			--i2;
		else if (maxValue == *i3)
			--i3;
	}

	cout << "found: ";
	for (const auto& v : found)
		cout << " " << v;
	cout << endl;

}