#include "stdafx.h"

/*
Given an integer N, print numbers from 1 to N in lexicographic order.

Details: To be implemented without using character conversion (or Strings). 

Example:
N = 25

Print:
1
10
11
..
19
2
20
21
..
25
3
4
5
6
7
8
9

*/

#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

void print29_my(unsigned num, unsigned start)
{
	const auto max = start + 10;
	while (start <= num && start < max)
	{
		cout << start << endl;
		print29_my(num, start * 10);
		++start;

		if (max == 11 && start >= 10) break;
	}
}

void print29_orig(unsigned num, unsigned start)
{
	vector<string> numbers;
	while (start <= num)
		numbers.push_back(to_string(start++));

	sort(numbers.begin(), numbers.end());
	for (const auto& num : numbers)
		cout << num << endl;
}

void JamesChen29()
{
	unsigned number = 100;
	print29_my(number, 1);
	//print29_orig(number, 1);
}
