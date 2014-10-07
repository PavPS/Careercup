#include "stdafx.h"

/*
Problem
Write a method to randomly generate a set of m integers from an array of size n. Each element must have equal probability of being chosen.
*/

#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

int rand_select_elems(vector<int>& values)
{
	srand((unsigned)time(NULL));
	static int gap = 0;

	int n = rand() % (values.size() - gap);
	int m = gap + n;

	int t = values[gap];
	values[gap] = values[m];
	values[m] = t;

	t = values[gap];

	gap++;
	gap %= values.size();

	return t;
}

void JamesChen16()
{
	const auto ArraySize = 15;
	cout << "        ";
	vector<int> values;
	for (unsigned i = 0; i < ArraySize; ++i)
	{
		values.push_back(rand() % 10);
		cout << "#" << setfill('0') << setw(2) << i << " ";
	}
	cout << endl;

	cout.fill(' ');
	cout << "values: "; for (const auto& v : values)cout << " " << setw(2) << v << " "; cout << endl;

	const unsigned WantToGenerate = 14;
	static_assert(WantToGenerate <= ArraySize, "Invalid parameters");

	cout << "Algorithm 2" << endl;
	vector<bool> used(values.size(), false);
	for (unsigned generated = 0; generated < WantToGenerate;)
	{
		const auto index = rand() % values.size();
		if (used[index])continue;

		cout << "#" << generated << ": " << values[index] << endl;
		used[index] = true;
		++generated;
	}

	/*
	Small change.
	Create a function that could be called multiple times and will hold state somewhere so it is possible
	to return values from an array with equal probability.
	*/
	cout << "Algorithm 2" << endl;
	for (unsigned generated = 0; generated < WantToGenerate; ++generated)
		cout << "#" << generated << ": " << rand_select_elems(values) << endl;
}
