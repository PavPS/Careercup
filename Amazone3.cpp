#include "stdafx.h"

/*
Provided a number dictionary and a number, x , which is formed from the number dictionary. 
Find the rank of the number x? 
Rank is defined as the position of the number x when all the number formed from the dictionary are sorted. 

Example 
Input :{4,1,5} 
X : 451 

Output : 4 

(145,154,415,451,514,541). 451 comes at 4th position
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int makeNum(const vector<int>& vec)
{
	int value = 0;
	int m = 1;
	for (vector<int>::const_reverse_iterator iter = vec.rbegin(), end = vec.rend(); iter != end; ++iter )
	{
		value += *iter*m;
		m*=10;
	}

	return value;
}

void Amazone3()
{
	vector<int> x;
	x.push_back(4);
	x.push_back(1);
	x.push_back(5);
	const int result = 451;

	sort(x.begin(), x.end());

	auto iter1 = x.begin();
	auto iter2 = x.end();
	int i = 1;
	do
	{
		int value = makeNum(x);
		if (value == result )
			cout << i;

		++i;
	}while( next_permutation(iter1, iter2));
}

#if !defined(_MSC_VER)
int main()
{
	Amazone3();
	return 0;
}
#endif
