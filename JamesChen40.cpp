#include "stdafx.h"

/*
Problem
Given a sorted integer array and a number, find the start and end indexes of the number in the array.

Ex1: Array = {0,0,2,3,3,3,3,4,7,7,9} and Number = 3 --> Output = {3,6}
Ex2: Array = {0,0,2,3,3,3,3,4,7,7,9} and Number = 5 --> Output = {-1,-1}

Complexity should be less than O(n)
*/

#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

pair<int, int> getPairIndices(const vector<int>& values, int value)
{
	int left = 0, right = values.size() - 1;
	int found = -1;
	while (left <= right)
	{
		const auto center = left + (right - left) / 2;
		const auto& centerValue = values[center];

		if (value < centerValue)
		{
			right = center - 1;
		}
		else if (value > centerValue)
		{
			left = center + 1;
		}
		else 
		{
			found = center;
			break;
		}
	}

	if (found < 0) return pair<int, int>(-1, -1);

	left = 0;
	right = found;
	while (left <= right)
	{
		const auto center = left + (right - left) / 2;
		const auto& centerValue = values[center];

		if (value <= centerValue)
		{
			right = center - 1;
		}
		else if (value > centerValue)
		{
			left = center + 1;
		}
	}

	const auto leftEdge = left;

	left = found;
	right = values.size() - 1;
	while (left <= right)
	{
		const auto center = left + (right - left) / 2;
		const auto& centerValue = values[center];

		if (value < centerValue)
		{
			right = center - 1;
		}
		else if (value >= centerValue)
		{
			left = center + 1;
		}
	}

	const auto rightEdge = right;

	return pair<int, int>(leftEdge, rightEdge);
}

void JamesChen40()
{
	vector<int> values{ 0, 0, 2, 3, 3, 3, 3, 4, 7, 7, 9 };

	cout.fill(' ');
	cout << "values: "; for (const auto& v : values)cout << " " << setw(2) << v << " "; cout << endl;

	const auto indices = getPairIndices(values, 4);
	cout << "Left: " << indices.first << ", Right: " << indices.second << endl;
}
