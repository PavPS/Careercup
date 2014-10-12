#include "stdafx.h"

/*
* Print the numbers between 30 to 3000. Microsoft
CONSTRAINT:
The numbers shouldnt contain digits either in incresing order or decreasing order.

FOLLOWING NOT ALLOWED
##123,234,345,1234,2345##increasing order,
##32,21,321,432,3210 etc##decresing order.

FOLLOWING ALLOWED:
243,27,578,2344 etc.,
Now see who ll code ths....
* */

#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>
#include <assert.h>

using namespace std;

unsigned getNextInc(unsigned num)
{
	unsigned count = 0;
	unsigned tmp = num;
	while (tmp >= 10)
	{
		++count;
		tmp /= 10;
	}

	if (tmp + count - 1 > 9)
		return num;

	num = tmp;
	while (count--)
	{
		num = num * 10 + ++tmp;
	}

	return num;
}

unsigned getNextDec(unsigned num)
{
	unsigned count = 0;
	unsigned tmp = num;
	while (tmp >= 10)
	{
		++count;
		tmp /= 10;
	}

	if (tmp < count)
		return num;

	num = tmp;
	while (count--)
	{
		num = num * 10 + --tmp;
	}

	return num;
}

unsigned getNextNumber(unsigned num)
{
	unsigned count = 0;
	unsigned tmp = num;
	while (tmp >= 10)
	{
		++count;
		tmp /= 10;
	}

	if (tmp < 9)
		num = tmp + 1;
	else
		num = 10;
	while (count--)
		num = num * 10;

	return num;
}

unsigned getNextBadNumber(unsigned num)
{
	auto dec = getNextDec(num);
	auto inc = getNextInc(num);

	if (num > inc)
		return getNextBadNumber(getNextNumber(num));

	if (num < dec)
		return dec;

	return inc;
}

void JamesChen30()
{
	for (unsigned i = 100; i < 3000;++i)
	{
		const auto stop = getNextBadNumber(i);
		for (; i < stop; ++i)
		{
			string str = to_string(i);
			unsigned delta = 0;
			for (unsigned n = 1; n < str.size(); ++n)
			{
				if ((int)str[n - 1] - (int)str[n - 0] == 1)
					++delta;
			}
			assert(delta < str.size());

			delta = 0;
			for (unsigned n = 1; n < str.size(); ++n)
			{
				if ((int)str[n - 0] - (int)str[n - 1] == 1)
					++delta;
			}
			assert(delta < str.size());
		}
	}
}
