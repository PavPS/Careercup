#include "stdafx.h"

/*
You are given an array of n integers which can contain integers from 1 to n only .
Some elements can be repeated multiple times and some other elements can be absent from the array .
Write a running code on paper which takes O(1) space apart from the input array and O(n) time to
print which elements are not present in the array and the count of every element
which is there in the array along with the element number .
NOTE: The array isn't necessarily sorted.
*/

#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <iomanip>

using namespace std;

void JamesChen3()
{
	/*
	1 ........... 10
	5 2 3 4 8 4 4 10
	*/

	vector<int> values { 5, 3, 2, 1, 10, 2, 2, 2, 2, 1 };
	cout << "source array: ";
	for (const auto& value : values)
		cout << value << " ";
	cout << endl;

	for (size_t i = 0; i < values.size(); ++i)
	{
		const auto& v = values[i];
		if (v <= 0) continue;

		queue<int> task;
		task.push(v);
		values[i] = 0;
		while (task.size())
		{
			const auto index = task.back() - 1;
			task.pop();

			if (values[index] <= 0)
			{
				--values[index];
			}
			else
			{
				task.push(values[index]);
				values[index] = -1;
			}

		}
	}

	for (size_t i = 0; i < values.size(); ++i)
	{
		cout << "#" << i+1 << ": ";
		if (values[i] >= 0)
			cout << "NONE";
		else
			cout << abs(values[i]) << " times";

		cout << endl;
	}
}