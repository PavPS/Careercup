#include "stdafx.h"

#include <iostream>

using namespace std;

void Google1()
{
	unsigned m = (0xFFFFFFFF << 1) - 1;
	unsigned c = 12345;
	unsigned a = 1103515245;
	
	unsigned seed = 34554;

	unsigned x = seed;
	for (int i = 0; i < 100; ++i )
	{
		x = (a*x + c) %	m;
		cout << x << "\t: " << (float)x / (float)(unsigned)(0xFFFFFFFF) << endl;
	}

} 