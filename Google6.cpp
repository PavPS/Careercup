#include "stdafx.h"

/*
1.	qaz is a value for a number where this number is less than the other next values which have indexes larger than the index of this number. 
for example: 33 , 25 , 26 , 58 , 41 , 59 -> qaz of (33) = 3 where 33 less than 3 numbers (58 , 41 , 59), 
qaz of (25) = 4 and not 5 because the index of 33 is less than the index of 25, qaz of (26) = 3 , qaz of (58) = 1 , qaz of (41) = 1 , qaz of (59) = 0. 
the question is to find the max qaz. 
it can be solved simply using 2 loops which takes time of O(n^2). 
that's ok but how can we solve this problem in O(nlogn). 
*/

#include <iostream>
#include <assert.h>
#include <string>
#include <map>
#include <vector>
#include <set>
#include <queue>
#include <stdexcept>
#include <limits>
#include <algorithm>

using namespace std;

struct qaz_pair
{
	int value;
	size_t index;
};

bool operator < (const qaz_pair& lhs, const qaz_pair& rhs)
{
	return lhs.value < rhs.value;
}

int qaz(const vector<int>& numbers, int number)
{
	// O(n)
	vector<qaz_pair> tmp;
	for (const auto n : numbers )
		tmp.push_back( qaz_pair{ n, tmp.size() } );

	// O(nlogn)
	sort(tmp.begin(), tmp.end());

	qaz_pair number_pair;
	number_pair.value = number;

	auto found = lower_bound(tmp.begin(), tmp.end(), number_pair);
	if (tmp.end() == found || found->value != number)
		return -1;

	// O(n)
	int result = 0; 
	int previous = found->value;
	const size_t index = found->index;
	for (; tmp.end() != found ; previous = found->value, ++found )
	{
		if (found->index > index)
			if (previous != found->value)
				result++;
	}

	return result;
}

void Google6()
{
	const vector<int> numbers { 33 , 25 , 26, 26 , 58 , 41, 41 , 59, 59 };

	assert( -1 == qaz(numbers, 0) );
	assert( -1 == qaz(numbers, 100) );

	assert( 3 == qaz(numbers, 33) );
	assert( 4 == qaz(numbers, 25) );
	assert( 3 == qaz(numbers, 26) );
	assert( 1 == qaz(numbers, 58) );
	assert( 1 == qaz(numbers, 41) );
	assert( 0 == qaz(numbers, 59) );
}

#if !defined(_MSC_VER)
int main()
{
	Google6();
	return 0;
}
#endif
