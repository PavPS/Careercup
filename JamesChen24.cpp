#include "stdafx.h"

/*
Problem
Suppose u have a square matrix of 0s and 1s only ... 
find the longest path of 1s available in the matrix and return that .. you can only move right and down ... For e.g. 

0 0 0 1 1 
1 1 1 0 1 
0 1 1 1 0 
0 0 1 0 0 
1 1 1 1 1

*/

#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>

using namespace std;

static const unsigned MatrixSize = 4;

void printMatrix(const char matrix[MatrixSize][MatrixSize])
{
	for (unsigned r = 0; r < MatrixSize; ++r)
	{
		for (unsigned c = 0; c < MatrixSize; ++c)
		{
			cout << matrix[r][c] << " ";
		}
		cout << endl;
	}
}

bool findPathRecursion(char matrix[MatrixSize][MatrixSize], unsigned r, unsigned c, vector<bool>& path)
{
	if (r == MatrixSize || c == MatrixSize)
		return false;

	if (matrix[r][c] == '0')
		return false;

	vector<bool> rightPath(path), downPath(path);
	if (r < MatrixSize) 
	{
		if( findPathRecursion(matrix, r+1, c, downPath) ) 
			downPath.insert(downPath.begin(), false);
	}

	if (c < MatrixSize) 
	{
		if (findPathRecursion(matrix, r, c+1, rightPath))
			rightPath.insert(rightPath.begin(), true);
	}

	if (rightPath.size() > downPath.size())
		swap(path, rightPath);
	else 
		swap(path, downPath);

	return true;
}

bool findPathFlat(char matrix[MatrixSize][MatrixSize], unsigned r, unsigned c, vector<bool>& path)
{
	if (r == MatrixSize || c == MatrixSize)
		return false;

	auto pred = [&matrix](unsigned row, unsigned col)->bool{return matrix[row][col] != '0';};

	if (!pred(r, c))
		return false;

	int counts[MatrixSize][MatrixSize] = {0};

	int maxSum = 0;
	int maxCol = 0, maxRow = 0;
	for (unsigned row = 0; row < MatrixSize; ++row)
		for (unsigned col = 0; col < MatrixSize; ++col)
		{
			if (!pred(row, col)) continue;

			auto top = row > 0 ? counts[row-1][col] : 0;
			auto left = col > 0 ? counts[row][col-1] : 0;
			counts[row][col] += max(top, left) + 1;

			if (counts[row][col] > maxSum)
			{
				maxSum = counts[row][col];
				maxCol = col;
				maxRow = row;
			}
		}

	vector<bool> tmp;
	while( maxSum > 1 && (maxCol || maxRow) )
	{
		auto left = maxCol > 0 ? counts[maxRow][maxCol-1] : 0;
		auto top = maxRow > 0 ? counts[maxRow-1][maxCol] : 0;

		--maxSum;
		if (top == maxSum)
		{
			tmp.push_back(false);
			--maxRow;
			continue;
		}
		if (left == maxSum)
		{
			tmp.push_back(true);
			--maxCol;
			continue;
		}
	}

	reverse(tmp.begin(), tmp.end());
	swap(tmp, path);

	return true;
}

void findPath(char matrix[MatrixSize][MatrixSize])
{
	vector<bool> path;
	bool found = findPathFlat/*findPathRecursion*/(matrix, 0, 0, path);
	if ( !found )
	{
		cout << "No path" << endl;
		return;
	}

	cout << "Path length is: " << path.size() + 1 << endl;
	unsigned r= 0, c = 0;
	matrix[r][c] = '*';
	for (const auto& d : path)
	{
		if (d) c++; else r++;
		matrix[r][c] = '*';
	}
}

void JamesChen24()
{
	char matrix[MatrixSize][MatrixSize];

	//srand(time(NULL));

	for (unsigned r = 0; r < MatrixSize; ++r)
		for (unsigned c = 0; c < MatrixSize; ++c)
			matrix[r][c] = '0' + rand() % 2;

	cout << "Original:" << endl;
	printMatrix(matrix);

	findPath(matrix);

	cout << "Marked:" << endl;
	printMatrix(matrix);
}

#if !defined(_MSC_VER)
int main()
{
	JamesChen24();
	return 0;
}
#endif