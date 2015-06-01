#include "stdafx.h"

/*
Suppose you are given a puzzle that is represented as a matrix with 0s and 1s, where a 0 indicates you’re allowed to move into that position and 1 means you’re not allowed to move in that position. Write a function that given a start position and an end position, returns a boolean value indicating if there exists a path from start to end. you are only allowed to move up, left, right and down. Diagonal movement is not allowed. 

Example #1 
Input 
0 0 1 0 1 
0 0 0 0 0 
0 1 1 1 1 
0 1 1 0 0 

start: 4,1 
end 0,3 

Output - true 

Example #2 
Input 
0 0 1 1 1 
0 1 0 0 0 
1 1 1 1 1 
0 0 0 0 1 

start: 0,0 
end: 1,2 

Output - false
*/

#include <iostream>
#include <assert.h>
#include <stack>
#include <array>

using namespace std;

static const int ColumnCount = 5;
static const int RowCount = 4;

typedef array<int, ColumnCount> RowType;
typedef array<RowType, RowCount> MatrixType;

template<class T, size_t N>
void assignRow(array<T, N>& arr, const initializer_list<int>& values)
{
	size_t c = 0;
	for (const auto& v : values)
		arr[c++] = v;
}

bool walk(const MatrixType& matrix, int fromRow, int fromColumn, int toRow, int toColumn)
{
	typedef pair<int, int> coord;
	stack<coord> coords;
	MatrixType masked(matrix);

	const coord target(toRow, toColumn);
	coord current(fromRow, fromColumn);

	coords.push(current);
	while (!coords.empty())
	{
		current = coords.top();
		coords.pop();

		if (current == target)
			return true;

		if (current.first > 0)
		{
			auto coordNew = coord(current.first - 1, current.second);
			if (coordNew == target)
				return true;

			if (masked[coordNew.first][coordNew.second])
			{
				coords.push(coordNew);
				masked[coordNew.first][coordNew.second] = 0;
			}
		}

		if (current.first < RowCount - 1)
		{
			auto coordNew = coord(current.first + 1, current.second);
			if (coordNew == target)
				return true;

			if (masked[coordNew.first][coordNew.second])
			{
				coords.push(coordNew);
				masked[coordNew.first][coordNew.second] = 0;
			}
		}

		//////

		if (current.second > 0)
		{
			auto coordNew = coord(current.first, current.second - 1);
			if (coordNew == target)
				return true;

			if (masked[coordNew.first][coordNew.second])
			{
				coords.push(coordNew);
				masked[coordNew.first][coordNew.second] = 0;
			}
		}

		if (current.second < ColumnCount - 1)
		{
			auto coordNew = coord(current.first, current.second + 1);
			if (coordNew == target)
				return true;

			if (masked[coordNew.first][coordNew.second])
			{
				coords.push(coordNew);
				masked[coordNew.first][coordNew.second] = 0;
			}
		}
	}

	return false;
}

void Amazone16()
{
	{
		MatrixType matrix;
		assignRow(matrix[0], {0, 0, 1, 0, 1});
		assignRow(matrix[1], {0, 0, 0, 0, 0});
		assignRow(matrix[2], {0, 1, 1, 1, 1});
		assignRow(matrix[3], {0, 1, 1, 0, 0});

		assert(walk(matrix, 3, 4, 3, 0));
	}

	{
		MatrixType matrix;
		assignRow(matrix[0], {0, 0, 1, 1, 1});
		assignRow(matrix[1], {0, 1, 0, 0, 0});
		assignRow(matrix[2], {1, 1, 1, 1, 1});
		assignRow(matrix[3], {0, 0, 0, 0, 1});

		assert(!walk(matrix, 0, 0, 1, 1));
	}

	{
		MatrixType matrix;
		assignRow(matrix[0], {1, 1, 1, 1, 1});
		assignRow(matrix[1], {0, 0, 0, 0, 1});
		assignRow(matrix[2], {1, 1, 1, 1, 1});
		assignRow(matrix[3], {0, 0, 0, 0, 0});

		assert(walk(matrix, 0, 0, 2, 0));
		assert(walk(matrix, 0, 0, 3, 0));
	}

	{
		MatrixType matrix;
		assignRow(matrix[0], {1, 1, 1, 1, 1});
		assignRow(matrix[1], {0, 0, 0, 0, 1});
		assignRow(matrix[2], {1, 1, 0, 1, 1});
		assignRow(matrix[3], {0, 0, 0, 0, 0});

		assert(!walk(matrix, 0, 0, 2, 0));
	}	

	cout << "DONE" << endl;
}

#if !defined(_MSC_VER)
int main()
{
	Amazone16();
	return 0;
}
#endif
