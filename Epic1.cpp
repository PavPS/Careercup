#include "stdafx.h"

/*
Colorful Number:
A number can be broken into different sub-sequence parts. 
Suppose, a number 3245 can be broken into parts like 3 2 4 5 32 24 45 324 245. 
And this number is a colorful number, since product of every digit of a sub-sequence are different. 
That is, 3 2 4 5 (3*2)=6 (2*4)=8 (4*5)=20 (3*2*4)= 24 (2*4*5)= 40
But 326 is not a colorful number as it generates 3 2 6 (3*2)=6 (2*6)=12.
You have to write a function that tells if the given number is a colorful number or not.
*/

#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>
#include <vector>
#include <unordered_set>
#include <assert.h>

using namespace std;

bool isColorful(int number)
{
	number = abs(number);
	if (number < 10)
		return true;

	unordered_set<int> products;
	vector<int> digits;
	while(number)
	{
		const auto digit = number % 10;
		// Obvious. However we should not assume that it could be in every number.
		if (digit == 1 || digit == 0)
			return false;

		digits.push_back(digit);
		products.insert(digit);
		number /= 10;
	}

	reverse(digits.begin(), digits.end());

	for (unsigned i = 2; i < digits.size(); ++i)
	{
		for (unsigned j = 0; j <= digits.size() - i; ++j)
		{
			int p = 1;
			for (unsigned k = j; k < j + i; ++k)
				p *= digits[k];

			if (products.end() != products.find(p))
				return false;
			
			products.insert(p);
		}
	}


	return true;
}

void Epic1()
{
	assert(true == isColorful(3245));
	assert(false == isColorful(326));
}

#if !defined(_MSC_VER)
int main()
{
	Epic1();
	return 0;
}
#endif
