#include "stdafx.h"

/*
Problem
How do you remove repeated values from a Int Array returning the resultant array in the same order as the original?
*/

#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <unordered_set>

using namespace std;

void JamesChen17()
{
	const auto ArraySize = 10;
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

	unordered_set<int> unique;
	unsigned head, tail;
	for (head = 0, tail = values.size(); head < tail;)
	{
		auto& v = values[head];
		if (unique.find(v) != unique.end())
		{
			swap(v, values[--tail]);
			continue;
		}

		unique.insert(v);
		++head;
	}

	cout << "unique: "; for (unsigned i = 0; i < tail; ++i)cout << " " << setw(2) << values[i] << " "; cout << endl;
	cout << "dup   : "; for (unsigned i = tail; i < values.size(); ++i)cout << " " << setw(2) << values[i] << " "; cout << endl;
}

#if !defined(_MSC_VER)
int main()
{
	JamesChen17();
	return 0;
}
#endif