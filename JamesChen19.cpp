#include "stdafx.h"

/*
Question
Given an array of +ve as well as -ve numbers, find out whether it is possible or not to convert it to 0 by adding/subtracting operations on all the elements.

e.g arr[]={1,2,3}
YES (1+2-3)

arr[]={3,6,2}
3+6-2 != 0
3-6-2 !=0
-3-6-2 !=0
-3-6+2 !=0
-3+6-2 !=0
-3+6+2 !=0
3-6+2 !=0
3+6+2 !=0

Hence ans= NO
*/

#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <bitset>

using namespace std;

bool isZeroSum(vector<int> values)
{
	if (values.size() == 1)
		return values[0] == 0;

	const auto tail = values.back();
	values.pop_back();

	vector<int> part1(values), part2(values);
	part1[0] += tail;
	part2[0] -= tail;

	return isZeroSum(part1) || isZeroSum(part2);
}

void JamesChen19()
{
	const auto ArraySize = 3;
	cout << "        ";
	vector<int> values;
	for (unsigned i = 0; i < ArraySize; ++i)
	{
		values.push_back(rand() % 10);
		cout << "#" << setfill('0') << setw(2) << i << " ";
	}
	cout << endl;

	values = { 3, 6, 2 };

	cout.fill(' ');
	cout << "values: "; for (const auto& v : values)cout << " " << setw(2) << v << " "; cout << endl;

	const auto possible = isZeroSum(values);
	cout << "Possible 0: " << (possible ? "TRUE" : "FALSE") << endl;
}
