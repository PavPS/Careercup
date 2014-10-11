#include "stdafx.h"

/*
Compute PI.
Problem
Compute PI.

Solution
Calculate an approximate value for pi by using the Monte Carlo method.
*/

#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

void JamesChen27()
{
	const double radius = 10;
	const unsigned iterations = 1000000;
	
	unsigned bingo = 0;
	for (unsigned i = 0; i < iterations; ++i)
	{
		double x = (rand() / (double)RAND_MAX) * 2 * radius;
		double y = (rand() / (double)RAND_MAX) * 2 * radius;

		x -= radius;
		y -= radius;
		const auto r = sqrt(x*x + y*y);
		if (r <= radius) bingo++;
	}

	cout << "pi = " << 4.0 * bingo / iterations << endl;
}
