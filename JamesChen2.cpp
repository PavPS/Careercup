#include "stdafx.h"

/*

You have two integer arrays.
Treat these arrays as if they were big numbers, with one digit in each slot.
Perform addition on these two arrays and store the results in a new array.

*/

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

static void generateNumbers(vector<unsigned char>& digits, size_t capacity)
{
	vector<unsigned char> tmp(capacity);
	for (size_t i = 0; i < capacity; ++i)
		tmp[i] = rand() % 10;

	swap(tmp, digits);
}

static void bigSum(const vector<unsigned char>& a, const vector<unsigned char>& b, vector<unsigned char>& sum)
{
	vector<unsigned char> tmp;
	const size_t maxSize = max(a.size(), b.size());
	tmp.reserve(maxSize + 1);

	unsigned inMind = 0;
	for (size_t index = 0; index < maxSize; ++index)
	{
		unsigned char aa;
		if (index < a.size())
			aa = a[a.size() - 1 - index];
		else
			aa = 0;

		unsigned char bb;
		if (index < b.size())
			bb = b[b.size() - 1 - index];
		else
			bb = 0;

		unsigned result = (aa + bb + inMind);
		if (result >= 10)
		{
			inMind = 1;
			result -= 10;
		}
		else
		{
			inMind = 0;
		}

		tmp.insert(tmp.cbegin(), static_cast<unsigned char>(result));
	}

	swap(tmp, sum);
}

static void output(const vector<unsigned char>& digits)
{
	for (auto& digit : digits)
		cout << static_cast<unsigned>(digit);

	cout << endl;
}

void JamesChen2()
{
	vector<unsigned char> a, b, s;
	generateNumbers(a, 3);
	generateNumbers(b, 50);

	cout << "a:\t";
	output(a);

	cout << "b:\t";
	output(b);

	bigSum(a, b, s);
	cout << "sum:\t";
	output(s);
}