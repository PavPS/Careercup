#include "stdafx.h"

/*
Write a program to convert a decimal number into binary your code should work on both big endian 
and small endian machine. U have given a variable which tell u whether machine is big endian or small endian
*/

#include <iostream>
#include <bitset>
#include <vector>
#include <assert.h>

using namespace std;

void Amazone4()
{
	int number = 24198652;
	std::bitset<32> bs(number);
	cout << bs << endl;

	vector<bool> my;
	while(number)
	{
		my.push_back((number % 2) == 1);
		number /= 2;
	}

	while(my.size() < bs.size())
		my.push_back(false);

	for (unsigned i = 0; i < my.size(); i++)
		assert(my[i] == bs[i]);

	cout << "OK";
}

#if !defined(_MSC_VER)
int main()
{
	Amazone4();
	return 0;
}
#endif
