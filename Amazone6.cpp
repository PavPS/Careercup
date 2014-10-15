#include "stdafx.h"

/*
write a program to give an array such that: 
1. the data value is from 1 to n 
2. the length of it is 2*n 
3. the two elements with same value keep the same number distance. 
for example, when n = 3, the length of array is 6, the array should be 
like: 2, 3, 1, 2, 1, 3. there are two elements between "2" pair, and three 
elements between "3" pair and one element between "1" pair
*/

#include <assert.h>
#include <iostream>
#include <bitset>
#include <vector>

using namespace std;

int get_max_pos(int value, int size)
{
	return size - value - 2;
}

bool set(unsigned number, unsigned index, vector<int>& arr)
{
	if ( index >= arr.size() )
		return true;

	if ( arr[index] )
		return false;

	arr[index] = number;
	return set(number, index + number+1, arr);
}

bool is_full(const vector<int>& arr)
{
	for (unsigned i = 0; i < arr.size(); i++)
		if ( !arr[i] )
			return false;

	return true;
}

bool spread(int number, const vector<int>& arr)
{
	if (!number)
		return false;

	int max_pos = get_max_pos(number, arr.size());

	auto mask = -1 << (max_pos + 1);
	mask = ~mask;
	do
	{
		vector<int> tmp(arr);
		bitset<32> bits(mask);
		bool succ = true;
		for (int i = 0; succ && i < max_pos+1; ++i)
		{
			if (bits[i])
				succ = set(number, i, tmp);
		}

		if ( succ )
		{
			for (int subnum = number-1; !is_full(tmp) && subnum > 0; subnum-- )
				if (spread(subnum, tmp))
					break;

			if (is_full(tmp))
			{
				for (unsigned i = 0; i < tmp.size(); i++)
					cout << tmp[i] << " ";
				cout << endl;

				return true;
			}
		}

	}while(--mask);

	return false;
}

void Amazone6()	
{
	const int n = 7;
	const int size = n*2;

	vector<int> arr;
	arr.resize(size);

	spread(n, arr);

	cout << endl;
}

#if !defined(_MSC_VER)
int main()
{
	Amazone6();
	return 0;
}
#endif
