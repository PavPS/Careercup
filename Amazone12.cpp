/*
Given an array of numbers print the values in diagonal format. 

Example (1) for 8 dataset 
Input Array : [1, 2, 3,4,5,6,7,8] 
Output 
01 02 04 07 
03 05 08 
06 

Example (2) for 45 dataset 
Input Array: [1, 2, 3,4,5,6,7,8,9,10……….44, 45] 
Output 
01 02 04 07 11 15 19 23 27 31 35 39 
03 05 08 12 16 20 24 28 32 36 40 43 
06 09 13 17 21 25 29 33 37 41 44 
10 14 18 22 26 30 34 38 42 45 

Code in Java.
*/

#include "stdafx.h"

#include <string>
#include <vector>
#include <iostream>
#include <assert.h>
#include <iomanip>
#include <algorithm>

using namespace std;

void Amazone12()
{
	vector<int> values;
	for (int i = 1; i <= 45;++i)
		values.push_back(i);

	const unsigned RowCount = 4;
	for (unsigned start = 0, majorStep = 2, row = 0; row < RowCount; start += min(RowCount, majorStep), ++majorStep, ++row)
	{
		for (unsigned k = start, minorStep = majorStep - 1; k < values.size(); k += min(RowCount, minorStep), ++minorStep)
			cout << setw(2) << values[k] << " ";
		cout << endl;
	}
}

#if !defined(_MSC_VER)
int main()
{
	Amazone12();
	return 0;
}
#endif
