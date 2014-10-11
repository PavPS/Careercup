#include "stdafx.h"

/*
Problem
Convert a base 2 number to a base 4 number -- Microsoft
*/

#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>

using namespace std;

int binToDec(const string& bin)
{
	int mul = 1;
	int result = 0;
	for (int i = bin.size() - 1; i >= 0; --i)
	{
		if (bin[i] == '1')
			result += mul;

		mul <<= 1;
	}

	return result;
}

string decToBin(int dec)
{
	string result;
	const auto base = 2;
	while (dec)
	{
		const auto digit = dec % base;
		dec /= base;
		result.push_back('0' + (char)digit);
	}

	reverse(result.begin(), result.end());
	return result;
}

string binToFour(const string& bin)
{
	string num(bin);
	if (num.size() % 2)
		num.insert(num.begin(), '0');

	string result;
	for (int i = num.size() - 2; i >= 0; i -= 2)
	{
		const auto d = (num[i] - '0') * 2 + (num[i + 1] - '0');
		result.push_back('0' + (char)d);
	}

	reverse(result.begin(), result.end());
	return result;
}

void JamesChen28()
{
	string bin = "10101";
	cout << "bin: " << bin << endl;
	const auto dec = binToDec(bin);
	cout << "dec: " << dec << endl;
	const auto four = binToFour(bin);
	cout << "four: " << four << endl;
	cout << "bin: " << decToBin(dec) << endl;
	cout << "four(1000000100000001100000100): " << binToFour("1000000100000001100000100") << endl;
}
