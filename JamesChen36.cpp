#include "stdafx.h"

/*
You given an array: 
3, 2, 1, 6, 5, 4, 9, 8, 7 
you have to find a 3 tuple which has property a < b < c, also a is before b, b is before c in array. 
Answer can have multiple tuples, you have to find any one. 
In this array, answer will be 3, 6, 9
*/

#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

void JamesChen36()
{
	vector<int> values{3, 2, 1, 6, 5, 4, 9, 8, 7};

	cout.fill(' ');
	cout << "values: "; for (const auto& v : values)cout << " " << setw(2) << v << " "; cout << endl;

	// Dumb method
	for (unsigned i = 0; i < values.size(); ++i )
	{
		const auto& mi = values[i];
		for (unsigned j = values.size()-1;j > i+1 ;--j)
		{
			if (values[j] > mi)
			{
				const auto& ma = values[j];
				for (unsigned k = j-1; k > i ;--k)
				{
					if (values[k] > mi && values[k] < ma)
					{
						cout << "a = " << mi << ", b = " << values[k] << ", c = " << ma << endl;
						return;
					}
				}
			}
		}
	}
}

#if !defined(_MSC_VER)
int main()
{
	JamesChen36();
	return 0;
}
#endif
