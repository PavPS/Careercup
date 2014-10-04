#include "stdafx.h"
/*
There are some glasses with equal volume 1 liter. The glasses kept as follows


            1
          2   3
       4    5    6
     7    8    9   10
You can put water to only top glass. If you put more than 1 liter water to 1st glass, water overflow and fill equally both 2nd and 3rd glass. 
Glass 5 will get water from both 2nd glass and 3rd glass and so on.. 
If you have X liter of water and you put that water in top glass, so tell me how much water contained by jth glass in ith row. 
*/
/*
level 0: 1
level 1: 1/2  1/2
level 2: 1/4  2/4  1/4
level 3: 1/8  3/8  3/8  1/8
level 4: 1/16  4/16  6/16  4/16  1/16
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

static const float GlassCapacity = 1.0;

static unsigned getRowCellCount(unsigned row)
{
	return row + 1;
}

static unsigned getCompleteCellCount(unsigned row)
{
	const auto currentRowCellCount = getRowCellCount(row);
	if (row == 0) return currentRowCellCount;

	return currentRowCellCount + getCompleteCellCount(row - 1);
}

static unsigned getCellIndex(unsigned row, unsigned column)
{
	auto allCells = getCompleteCellCount(row);
	return allCells - getRowCellCount(row) + column + 1;
}

float CalcWaterInGlass(unsigned jth, unsigned ith /* DEPTH */, float water)
{
	const auto cellCount = getCompleteCellCount(ith + 1);

	vector<float> galsses(cellCount, 0.0f);
	galsses[getCellIndex(0, 0)] = water;

	for (unsigned row = 0; row < ith; ++row)
	{
		for (unsigned column = 0; column < getRowCellCount(row); ++column)
		{
			auto existingAmount = galsses[getCellIndex(row, column)];
			auto canBeHeldInTheGlass = min(GlassCapacity, existingAmount);
			auto willBeSharedAmongNeighbors = existingAmount - canBeHeldInTheGlass;

			galsses[getCellIndex(row, column)] = existingAmount - canBeHeldInTheGlass;
			galsses[getCellIndex(row + 1, column + 0)] += willBeSharedAmongNeighbors / 2;
			galsses[getCellIndex(row + 1, column + 1)] += willBeSharedAmongNeighbors / 2;
			if (column == jth && row == ith) break;
		}
	}

	return min(GlassCapacity, galsses[getCellIndex(ith, jth)]);
}

void DoTest(unsigned jth, unsigned ith, float water)
{
    cout << "Total water:" << water << endl;
    cout << "(" << jth << ", " << ith << ")";
    cout << " = " << CalcWaterInGlass(jth, ith, water) << endl;
    cout << "---------------------------------------" << endl;
}


void JamesChen1()
{
	DoTest(0, 0, 0);
    DoTest(0, 0, 0.5);
    DoTest(0, 0, 1.0);
    DoTest(0, 0, 1.5);
    DoTest(0, 1, 0.5);
    DoTest(0, 1, 1);
    DoTest(0, 1, 1.5);
    DoTest(0, 1, 3);
    DoTest(0, 1, 3.5);
    DoTest(1, 1, 0.5);
    DoTest(1, 1, 1);
    DoTest(1, 1, 1.5);
    DoTest(1, 1, 3);
    DoTest(1, 1, 3.5);
    DoTest(0, 2, 0.5);
    DoTest(0, 2, 3.0);
    DoTest(0, 2, 4.5);
    DoTest(0, 2, 6);
    DoTest(1, 2, 1.5);
    DoTest(1, 2, 3);
    DoTest(1, 2, 5);
    DoTest(1, 2, 6);
    DoTest(2, 2, 1.5);
    DoTest(2, 2, 3);
    DoTest(2, 2, 5);
    DoTest(2, 2, 6);
    DoTest(0, 3, 8);
    DoTest(1, 3, 8);
    DoTest(2, 3, 8);
    DoTest(3, 3, 8);
}