#include "stdafx.h"

/*
Design an efficient algorithm for computing c(n, k) that has the property that it never overflows if c(n, k) can be represented as an integer assume n and k are both integers.
*/

#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>
#include <assert.h>

using namespace std;

// See pascal triangle. How you extract subb from upper row (n-1) and two neighbors (k and k-1) 

int conputeNK(int n, int k)
{
	if (n == k || k == 0)
		return 1;

	return conputeNK(n - 1, k) + conputeNK(n - 1, k - 1);
}

void JamesChen32()
{
	const int n = 5;
	const int k = 2;

	cout << "Result: " << conputeNK(n, k) << endl;
}
