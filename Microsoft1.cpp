#include "stdafx.h"

/*
 microsoft-interview-questions
0
of 0 votes
4
Answers

Given n rows of integers, such that the ith row (1 <= i <= n) contains i integers, find the path having the maximum weight.
Path traversal rules:
1. A valid path sequence would be top-down i.e. begins with the integer in the first row, and traverses all rows selecting only one integer in each row.
2. From any jth integer in the ith row i.e row[i][j], traversal can happen either downward (i.e to row[i+1][j]) or diagonally downward to the right (i.e to row[i+1][j+1])
The weight of a Path is the sum of values of integers in the Path sequence.
Sample Input:
No. of Rows: 5
4
2 9
15 1 3
16 92 41 44
8 142 6 4 8

Expected Output: 4, 2, 15, 92, 142 (Max weight is 255)
*/

#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>
#include <vector>
#include <memory>
#include <assert.h>

using namespace std;

void getMaxPath1(const vector< vector<int> >& numbers, vector<int>& path)
{
	vector< vector<int> > tmp;
	vector< int > result;

	if (!numbers.size())
		return;

	tmp.push_back( numbers[0] );
	for (unsigned r = 0; r < numbers.size() - 1; ++r)
	{
		tmp.push_back( vector<int>(numbers[r + 1].size(), 0) );

		for (unsigned c = 0; c < numbers[r].size(); ++c)
		{
			const auto& currentValue = tmp[r][c];
			const auto downValue = numbers[r + 1][c] + currentValue;
			const auto diagonalValue = numbers[r + 1][c + 1] + currentValue;

			if (downValue > tmp[r + 1][c]) tmp[r + 1][c] = downValue;
			if (diagonalValue > tmp[r + 1][c + 1]) tmp[r + 1][c + 1] = diagonalValue;
		}
	}

	cout << "Numbers (hlp):" << endl;
	for (const auto& row : tmp)
	{
		for (const auto& cell : row)	
			cout << setw(3) << cell << " ";
		cout << endl;
	}
	cout << endl;

	unsigned maxIndex = 0;
	for (unsigned c = 1; c < tmp[tmp.size() - 1].size(); ++c)
		if (tmp[tmp.size() - 1][c] > tmp[tmp.size() - 1][maxIndex])
			maxIndex = c;

	// Track back. Consider row of equal values.
	result.push_back(numbers[tmp.size() - 1][maxIndex]);
	for (unsigned r = 1; r < tmp.size() - 1; ++r)
	{
		const unsigned rReal = tmp.size() - (r - 1) - 2;
		if (maxIndex == 0)
			result.push_back(numbers[rReal][maxIndex]);
		else if (rReal > maxIndex)
		{
			if (tmp[rReal][maxIndex] + numbers[rReal + 1][maxIndex] == tmp[rReal + 1][maxIndex])
				result.push_back(numbers[rReal][maxIndex]);
			else
				result.push_back(numbers[rReal][--maxIndex]);
		}
		else
		{
			result.push_back(numbers[rReal][maxIndex]);
		}
	}

	result.push_back(numbers[0][0]);
	reverse(result.begin(), result.end());
	swap(path, result);
}

void Microsoft1()
{
	vector< vector<int> > numbers;
	numbers.push_back({ 4 });
	numbers.push_back({ 2, 9 });
	numbers.push_back({ 15, 1, 3 });
	numbers.push_back({ 16, 92, 41, 44 });
	numbers.push_back({ 8, 142, 6, 4, 8 });

	cout << "Numbers:" << endl;
	for (const auto& row : numbers)
	{
		for (const auto& cell : row)	
			cout << setw(3) << cell << " ";
		cout << endl;
	}
	cout << endl;

	vector<int> path;
	getMaxPath1(numbers, path);

	cout << "Max path #1 is:" << endl;
	for (const auto& cell : path)
		cout << setw(3) << cell << " ";
	cout << endl;
}

#if !defined(_MSC_VER)
int main()
{
	Microsoft1();
	return 0;
}
#endif
