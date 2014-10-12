#include "stdafx.h"

/*
Compute the nth Fibonacci number.
*/

#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

void JamesChen34()
{
	unsigned int nth = 20;
	vector<int> vec(nth);

	vec[0] = vec[1] = 1;
	for (unsigned i = 2; i < nth; ++i)
	{
		vec[i] = vec[i - 1] + vec[i - 2];
	}

	cout << vec.back() << endl;
}
