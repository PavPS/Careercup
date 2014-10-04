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

using namespace std;

static const float GlassCapacity = 1.0;

float getGlassFormula(int row, int column)
{
	/*
	if ( row == 0 && column == 0 )
		return GlassCapacity;

	const int columnCount = row + 1;
	if ( column == 0 || column == columnCount - 1 )
		return pow( 0.5f, row );

	return getGlassCoeff(row-1, column-1) + getGlassCoeff(row-1, column+0);
	*/

	return 0;
}

float CalcWaterInGlass(int jth, int ith /* DEPTH */, float water)
{
	return 0;
}

void DoTest(int jth, int ith, float water)
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