#include "stdafx.h"

/*
Question
Given an array of +ve as well as -ve numbers, find out whether it is possible or not to convert it to 0 by adding/subtracting operations on all the elements.

e.g arr[]={1,2,3}
YES (1+2-3)

arr[]={3,6,2}
3+6-2 != 0
3-6-2 !=0
-3-6-2 !=0
-3-6+2 !=0
-3+6-2 !=0
-3+6+2 !=0
3-6+2 !=0
3+6+2 !=0

Hence ans= NO
*/

#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

void JamesChen19()
{
	const auto ArraySize = 10;
	cout << "        ";
	vector<int> values;
	for (unsigned i = 0; i < ArraySize; ++i)
	{
		values.push_back(i);
		cout << "#" << setfill('0') << setw(2) << i << " ";
	}
	cout << endl;

	random_shuffle(values.begin(), values.end());

	cout.fill(' ');
	cout << "values: "; for (const auto& v : values)cout << " " << setw(2) << v << " "; cout << endl;
}
