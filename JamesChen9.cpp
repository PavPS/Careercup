//#if defined(_MSC_VER)
#include "stdafx.h"
//#endif

/*
Find the largest subarray with equal number of 0's and 1's
Problem
Find the largest subarray with equal number of 0's and 1's.
example 001010101
*/

#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <unordered_map>

using namespace std;

void JamesChen9()
{
	cout << "        ";
	vector<int> values;
	for (unsigned i = 0; i < 10; ++i)
	{
		values.push_back(rand() % 2);
		cout << "#" << setfill('0') << setw(2) << i << " ";
	}
	cout << endl;

	cout.fill(' ');

	cout << "values: ";
	for (const auto& v : values)
		cout << " " << setw(2) << v << " ";
	cout << endl;

	/*
	Dumb method
	*/

	vector<int> aux;
	int sum = 0;
	for (const auto& v : values)
	{
		if (v == 0)
			--sum;
		else
			++sum;
		aux.push_back(sum);
	}

	cout << "aux:    ";
	for (const auto& v : aux)
		cout << " " << setw(2) << v << " ";
	cout << endl;

	int tail = 0;
	unsigned maxLength = 0;
	for (unsigned i = 0; i < values.size(); ++i)
	{
		if (i + maxLength >= values.size()) break;
		const auto awaitable = values[i] == 0 ? (aux[i] + 1) : (aux[i] - 1);
		for (unsigned k = values.size() - 1; k >= i + maxLength; --k)
		{
			if (awaitable == aux[k])
			{
				maxLength = k - i + 1;
				tail = i;
				break;
			}
		}
	}

	cout << "Algorithm 1" << endl;
	cout << "Max length:  " << maxLength << endl;
	cout << "Start index: " << tail << endl;

	/*
	New method
	*/
	unordered_map< int, int > um;
	int growingSum = 0;
	maxLength = 0;
	for (unsigned i = 0; i < values.size(); ++i)
	{
		if (values[i] == 0)
			--growingSum;
		else
			++growingSum;

		auto awaitable = growingSum + ((values[i] == 0) ? 1 : 0);

		cout << "searching for: " << awaitable << endl;
		if (um.find(awaitable) != um.end())
		{
			if (i - um[awaitable] > maxLength)
			{
				cout << "found at: " << um[awaitable] << endl;

				maxLength = i - um[awaitable] + 1;
				tail = um[awaitable];
			}
		}

		um.insert( make_pair(growingSum, i) );
	}

	cout << "Algorithm 2" << endl;
	cout << "Max length:  " << maxLength << endl;
	cout << "Start index: " << tail << endl;
}

#if !defined(_MSC_VER)
int main()
{
	JamesChen9();
	return 0;
}
#endif