#include "stdafx.h"

/*
Warm-up question: Write a function that prints all ASCII characters. You are not allowed to use for/while loop.
*/

#include <iostream>
#include <assert.h>
#include <string>
#include <map>
#include <vector>
#include <set>
#include <queue>
#include <stdexcept>
#include <limits>

using namespace std;

void printRec(int num, int max)
{
	cout << num << endl;
	if (num < max)
		printRec(num+1, max);
}

void Google5()
{
	printRec(0, 255);
}

#if !defined(_MSC_VER)
int main()
{
	Google5();
	return 0;
}
#endif
