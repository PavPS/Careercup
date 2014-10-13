#include "stdafx.h"

/*
Find a number in the array having least difference with the given number (n) -- Facebook
*/

#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>
#include <assert.h>

using namespace std;

void findLeast(vector<int> values, int value)
{
	sort(values.begin(), values.end());
	cout << "sorted: "; for (const auto& v : values)cout << " " << setw(2) << v << " "; cout << endl;

	int left = 0, right = values.size() - 1;
	while(right - left > 1)
	{
		const auto center = left + (right - left) / 2;
		const auto& centerValue = values[center];
		if ( value < centerValue )
			right = center - 1;
		else
			left = center;
	}

	unsigned index;
	if (abs(values[left] - value) < abs(values[right] - value))
		index = left;
	else
		index = right;

	cout << "Number is: " << values[index] << " at " << index;
}

void JamesChen35()
{
	const auto ArraySize = 20;
	cout << "        ";
	vector<int> values;
	for (unsigned i = 0; i < ArraySize; ++i)
	{
		values.push_back(rand() % 100);
		cout << "#" << setfill('0') << setw(2) << i << " ";
	}
	cout << endl;

	cout.fill(' ');
	cout << "values: "; for (const auto& v : values)cout << " " << setw(2) << v << " "; cout << endl;

	const int target = 31;
	cout << "Looking for number: " << target << endl;
	findLeast(values, target);
}

#if !defined(_MSC_VER)
int main()
{
	JamesChen35();
	return 0;
}
#endif