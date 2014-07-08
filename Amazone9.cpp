#include "stdafx.h"

#include <vector>
#include <assert.h>

using namespace std;

int extractRadixLSB(int value, int position)
{
	assert(position >= 1);
	int dev = 1;
	while(position--)
		dev *= 10;

	int rem = value % dev;
	return rem / (dev / 10);
}

int getDigitCount(int number)
{
	int pow = 0;
	do
	{
		pow++;
		number /= 10;
	}
	while(number);

	return pow;
}

void radix_sort(vector<int>& vec)
{
	int max = 0;
	for (int i = 0; i < vec.size(); ++i )
	{
		int m = getDigitCount(vec[i]);
		if ( m > max )
			max = m;
	}

	vector<int> tmp(vec);
	vector<int> counter;
	for (int m = 0; m < max; m++ )
	{
		vector<int> tmp_m(tmp);
		vector<int> a(tmp.size());

		vector<int> counter(tmp.size());
		for (int i = 0; i < tmp.size(); ++i )
			counter[ a[i] = extractRadixLSB(tmp[i], m+1) ]++;

		for (int i = 1; i < tmp.size(); ++i )
			counter[i] += counter[i-1];
	
		for (int i = tmp.size() - 1; i >= 0; --i )
		{
			counter[ a[i] ]--;
			tmp_m[counter[a[i]]] = tmp[i];
		}

		swap(tmp, tmp_m);
	}

	swap(tmp, vec);
}

void Amazone9()
{
	assert(9 == extractRadixLSB(9, 1));
	assert(0 == extractRadixLSB(9, 2));
	assert(5 == extractRadixLSB(95, 1));
	assert(9 == extractRadixLSB(95, 2));
	assert(0 == extractRadixLSB(95, 3));

	vector<int> values;
	values.push_back(9);
	values.push_back(1);
	values.push_back(2);
	values.push_back(11);
	values.push_back(3);
	values.push_back(4);
	values.push_back(7);
	values.push_back(5);
	values.push_back(6);
	values.push_back(0);
	values.push_back(8);
	values.push_back(10);

	radix_sort(values);

	assert(0 == values[0]);
	assert(1 == values[1]);
	assert(2 == values[2]);
	assert(3 == values[3]);
	assert(4 == values[4]);
	assert(5 == values[5]);
	assert(6 == values[6]);
	assert(7 == values[7]);
	assert(8 == values[8]);
	assert(9 == values[9]);
	assert(10 == values[10]);
	assert(11 == values[11]);
}