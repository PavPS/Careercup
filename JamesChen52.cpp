#include "stdafx.h"

/*
Sort integer matrix so that all values in rows and columns are sorted.
*/

#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

const auto MatrixSide = 5;
void sortMatrix(const vector<int>& values, int matrix[MatrixSide][MatrixSide], unsigned side)
{
	if (side > 2)
	{
		sortMatrix(values, matrix, side - 1);
	}
	else if (side == 2)
	{
		matrix[MatrixSide - 1][MatrixSide - 1] = values[values.size() - 1];
		matrix[MatrixSide - 2][MatrixSide - 2] = values[values.size() - 4];

		matrix[MatrixSide - 1][MatrixSide - 2] = values[values.size() - 2];
		matrix[MatrixSide - 2][MatrixSide - 1] = values[values.size() - 3];
		return;
	}

	auto iter = values.end() - side*side;
	matrix[MatrixSide - side][MatrixSide - side] = *iter++;

	for (unsigned i = 1; i < side; ++i)
	{
		matrix[MatrixSide - side][MatrixSide - side + i] = *iter++;
		matrix[MatrixSide - side + i][MatrixSide - side] = *iter++;
	}
}

void JamesChen52()
{
	cout << "        ";
	vector<int> values;
	for (unsigned i = 0; i < MatrixSide*MatrixSide; ++i)
	{
		values.push_back(rand() % 100);
		cout << "#" << setfill('0') << setw(2) << i << " ";
	}
	cout << endl;

	cout.fill(' ');
	cout << "values: "; for (const auto& v : values)cout << " " << setw(2) << v << " "; cout << endl;

	sort(values.begin(), values.end());
	int matrix[MatrixSide][MatrixSide] = {0};
	sortMatrix(values, matrix, MatrixSide);

	for (unsigned r = 0; r < MatrixSide; ++r)
	{
		for (unsigned c = 0; c < MatrixSide; ++c)
			cout << setw(2) << matrix[r][c] << " ";

		cout << endl;
	}
}

