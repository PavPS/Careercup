#include "stdafx.h"

/*
Design an algorithm to find all pairs of integers within an array which sum to a specified value.

-- If the sum of two is equal to the specified value, print it out

*/

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void JamesChen5()
{
	const unsigned capacity = 20;
	vector<int> values;

	cout << "original values: ";
	for (unsigned i = 0; i < capacity; ++i)
	{
		values.push_back(rand() % capacity);
		cout << values.back() << " ";
	}
	cout << endl;

	const int sum = rand() % capacity;
	cout << "required sum is: " << sum << endl;

	sort(values.begin(), values.end());
	cout << "sorted values:   ";
	for (const auto& value : values)
		cout << value << " ";
	cout << endl;

	for (const auto& value : values)
	{
		cout << "searching pair for value " << value << ": ";
		if (value > sum)
		{
			cout << "NO (too large)" << endl;
			continue;
		}

		const auto target = sum - value;
		vector<int>::const_iterator found = lower_bound(values.begin(), values.end(), target);
		if (values.end() == found || *found != target)
		{
			cout << "NO (end of search)" << endl;
			continue;
		}

		while (values.end() != found && *found == target)
		{
			cout << *found << " ";
			++found;
		}

		cout  << endl;
	}

}