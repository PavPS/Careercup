#include "stdafx.h"

/*
Calculate (x^y)%z without pow()
*/

#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>
#include <assert.h>

using namespace std;

int calcPowRecursion(int x, int y)
{
	if (y == 0)
		return 1;

	return x * calcPowRecursion(x, y - 1);
}

int calcMod(int value, int z)
{
	if (value < z)
		return value;

	return calcMod(value - z, z);
}

void JamesChen31()
{
	const int x = 3;
	const int y = 3;
	const int z = 10;

	const int p = calcPowRecursion(x, y);
	const auto result = calcMod(p, z);

	cout << "Result: " << result << endl;
}
