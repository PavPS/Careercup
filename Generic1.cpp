#include "stdafx.h"

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
Coin exchange
given coins: 1 < 2 < 3 ...
exchange any number
*/

void Generic1()
{
	vector<unsigned> coins;

	coins.push_back(50);
	coins.push_back(20);
	coins.push_back(15);
	coins.push_back(10);
	coins.push_back(5);
	coins.push_back(3);
	coins.push_back(1);

	sort(coins.begin(), coins.end());

	unsigned num = 178;

	while(num)
	{
		// find first coin that is lower or equals.
		auto found = lower_bound(coins.begin(), coins.end(), num);
		if ( found == coins.end() || *found > num )
			found--;

		auto count = num / *found;
		num -= count * (*found);

		cout << *found << ": " << count << endl;
	}
}