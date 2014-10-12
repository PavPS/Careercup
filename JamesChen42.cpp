#include "stdafx.h"

/*
Print changes(Knapsack)
Problem
Given an infinite number of quarters (25 cents), dimes (10 cents), nickels (5 cents) and pennies (1 cent),
write code to calculate the number of ways of representing n cents.
*/

#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

void change42(int amount, const vector<int>& cionsDesc, unsigned coinIndex, unsigned *ways)
{
	if (coinIndex >= cionsDesc.size())
		return;

	const int& coin = cionsDesc[coinIndex];
	for (unsigned i = 0; (int)(amount - coin*i) >= 0; ++i)
	{
		unsigned amountTmp = amount - coin*i;
		if (amountTmp == 0)
		{
			++(*ways);
			return;
		}
		if (coinIndex != cionsDesc.size() - 1)
			change42(amountTmp, cionsDesc, coinIndex + 1, ways);
	}
}

void JamesChen42()
{
	const unsigned amount = 10;
	unsigned ways = 0;
	vector<int> coins {25, 10, 5, 1};
	change42(amount, coins, 0, &ways);

	cout << "Number of ways is: " << ways << endl;
}
