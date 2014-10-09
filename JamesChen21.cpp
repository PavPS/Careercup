#include "stdafx.h"

/*
Implement an algorithm to print the following diagram
1
1  1
1  2   1
1  3   3   1
1  4   6   4   1
1  5 10 10   5  1
1  6 15 20 15  6  1
*/

#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>

using namespace std;

void JamesChen21()
{
	const unsigned LevelCount = 10;
	vector<unsigned> values;

	unsigned printed = 0;
	for (unsigned l = 0; l < LevelCount; ++l)
	{
		if (l == 0)
		{
			values.push_back(1);
		}
		else
		{
			for (unsigned i = 0; i < l + 1; ++i)
			{
				if (i == 0 || i == l)
					values.push_back(1);
				else
					values.push_back( values[printed - (l + 1) + i + 0] + values[printed - (l + 1) + i + 1] );
			}
		}

		while(printed < values.size())
			cout << values[printed++] << " ";

		cout << endl;
	}
}

#if !defined(_MSC_VER)
int main()
{
	JamesChen21();
	return 0;
}
#endif