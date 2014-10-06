#include "stdafx.h"

/*
Problem
Find the maxProduct of three numbers from a given integer array.
1. Handle all the cases
2. Interviewer was looking for a complete code
*/

#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

void JamesChen10()
{
	const auto ArraySize = 10;
	cout << "        ";
	vector<int> values;
	for (unsigned i = 0; i < ArraySize; ++i)
	{
		values.push_back(rand() % 10 - 5);
		cout << "#" << setfill('0') << setw(2) << i << " ";
	}
	cout << endl;

	cout.fill(' ');

	cout << "values: ";
	for (const auto& v : values)
		cout << " " << setw(2) << v << " ";
	cout << endl;

	sort(values.begin(), values.end());

	cout << "sorted: ";
	for (const auto& v : values)
		cout << " " << setw(2) << v << " ";
	cout << endl;

	if (values.size() < 3)
	{
		cout << "Array is too short" << endl;
		return;
	}

	/* ---------------------- SOLUTION 1 ---------------------- */

	auto ScanLeftToRight = [](unsigned& index, const vector<int>& array, const unsigned boundary, unsigned start)
	{ for (index = start; index < boundary && !array[index]; ++index){ } return index < boundary; };

	unsigned a = 0, b = 0, c = 0;

	// Find from the right hand side (except zero)
	a = values.size() - 1;
	while (a >= 0 && !values[a])--a;

	if (!values[a] || a < 2)
	{
		cout << "Zeros..." << endl;
		return;
	}
	
	// b from left side
	if (!ScanLeftToRight(b, values, a, 0))
	{
		cout << "Zeros..." << endl;
		return;
	}

	bool negativeMode = values[b] < 0;

	if (negativeMode)
	{
		if (!ScanLeftToRight(c, values, a, b+1))
		{
			cout << "Negative mode rejected..." << endl;
			negativeMode = false;
		}
	}

	if (!negativeMode)
	{
		b = a - 1;
		while (b >= 0 && b < values.size() && !values[b]) --b;
		if (b >= a)
		{
			cout << "Zeros..." << endl;
			return;
		}
	
		c = b - 1;
		while (c >= 0 && c < values.size() && !values[c]) --c;
		if (c >= b)
		{
			cout << "Zeros..." << endl;
			return;
		}
	}
	else
	{
		auto bNew = a - 1;
		while (bNew >= 0 && bNew < values.size() && !values[bNew]) --bNew;
		if (bNew < a)
		{
			auto cNew = bNew - 1;
			while (cNew >= 0 && cNew < values.size() && !values[cNew]) --cNew;
			if (cNew < bNew)
			{
				if (values[a] * values[bNew] * values[cNew] > values[a] * values[b] * values[c])
				{
					b = bNew;
					c = cNew;
				}
			}
		}

	}

	cout << "Indices: " << a << ", " << b << ", " << c << endl;
	cout << "Max mul: " << values[a] * values[b] * values[c] << endl;

	/* ---------------------- SOLUTION 2 ---------------------- */
	sort(values.begin(), values.end(), [=](int lhs, int rhs) { return abs(lhs) < abs(rhs); });
	cout << "abs:    ";
	for (const auto& v : values)
		cout << " " << setw(2) << v << " ";
	cout << endl;

	int neg[2];
	int pos[3];
	int negCount = 0;
	int posCount = 0;

	for (int i = values.size() - 1; i >= 0; --i){
		if (values[i] > 0 && posCount < 3){
			pos[posCount++] = values[i];
		}

		if (values[i] <= 0 && negCount < 2){
			neg[negCount++] = values[i];
		}

		if (posCount == 3 && negCount == 2){
			break;
		}
	}

	int result = 0;
	if (posCount == 3 && negCount == 2)
	{
		auto allPos = pos[0] * pos[1] * pos[2];
		auto mix = neg[0] * neg[1] * pos[0];
		result = max(allPos, mix);
	}

	if (posCount == 3 && negCount < 2)
	{
		result = pos[0] * pos[1] * pos[2];
	}
	else if (posCount < 3 && negCount == 2)
	{
		a = pos[0];
		b = neg[0];
		c = neg[1];
	}

	cout << "Max mul: " << result << endl;
}