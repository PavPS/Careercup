#include "stdafx.h"

/*
Compute number of 2s in a range of (0...n)
Write a method to count the number of 2s between 0 and n.
*/

#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>
#include <assert.h>

using namespace std;

unsigned count2(unsigned number)
{
	unsigned result = (number % 10) == 2 ? 1 : 0;
	int pow = 10;
	int count2 = 1;
	auto tmp = number;
	while (tmp)
	{
		result += (tmp / pow) * count2;
		tmp /= pow;
		count2 *= 10;
	}

	return result;
}

void JamesChen33()
{
	const unsigned n = 10000;
	cout << "Count of '2' in " << n << " is: " << count2(n) << endl;
}
