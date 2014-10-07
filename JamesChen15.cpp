#include "stdafx.h"

/*
Problem
Print the numbers without repeating digits in it and with in the range x to y.
ex. range 50 to 5000,
then it must print like 50,51,52,53,54,56,....57,......65,67,....76,77....109,120,123,124...4987.
*/

#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

static const unsigned primes[] = { 1, 3, 5, 7, 11, 13, 17, 23, 29, 31, 37 };
bool hasSameDigits1(unsigned number)
{
	int accu = 1;
	while (number)
	{
		const auto rem = (number % 10);
		const auto& prime = primes[rem + 1];
		if ((accu % prime) == 0)
			return true;

		accu *= prime;
		number /= 10;
	}

	return false;
}

bool hasSameDigits2(unsigned number)
{
	int flags[10] = { 0 };
	while (number)
	{
		const auto rem = (number % 10);
		if (flags[rem]++)
			return true;

		number /= 10;
	}

	return false;
}

void JamesChen15()
{
	const unsigned From = 50;
	const unsigned To = 100;

	cout << "From = " << From << endl;
	cout << "To = " << To << endl;

	cout << "result:";
	for (auto i = From; i <= To; ++i)
	{
		if (!hasSameDigits2(i))
			cout << i << " ";
	}
	cout << endl;
}