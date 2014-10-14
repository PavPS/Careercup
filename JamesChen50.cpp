#include "stdafx.h"

/*
find a pattern in byte array and change that pattern in place (do not use temp array or variable) 
for example, find pattern 0,0,3 in an byte array and replace it with 0,0 should be o(n) 
*/

#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

void replacePattern2(string& str)
{
	if (str.size() < 3)
		return;

	unsigned readIndex = 2, writeIndex = 2;
	while(readIndex < str.size())
	{
		str[writeIndex] = str[readIndex];

		if (str[writeIndex - 2] == '0' && str[writeIndex - 1] == '0' && str[writeIndex - 0] == '3')
		{ }
		else writeIndex++;

		++readIndex;
	}

	while(writeIndex < str.size())
		str[writeIndex++] = 0;
}

void replacePattern1(const string& pattern, const string& replacement, string& str)
{
	unsigned writeIndex = 0;
	unsigned comparePointer = 0;
	for (unsigned readPointer = 0; readPointer < str.size();)
	{
		//cout << writeIndex << "<-" << readPointer << ": " <<  str[readPointer] << endl;
		str[writeIndex] = str[readPointer];

		unsigned m;
		for (m = 0; m < pattern.size() && m + comparePointer < str.size() && str[m + comparePointer] == pattern[m]; ++m) { }

		if (pattern.size() == m)
		{
			copy(replacement.begin(), replacement.end(), str.begin() + writeIndex);
			readPointer += pattern.size() - (writeIndex - comparePointer);
			writeIndex = comparePointer + replacement.size();
			//cout << "X, writeIndex = " << writeIndex << endl;
		}
		else
		{
			++writeIndex;
			++readPointer;
			++comparePointer;
		}
	}

	while(writeIndex < str.size())
		str[writeIndex++] = 0;
}

void JamesChen50()
{
	const vector<string> tests { "10033003123003031003", "00233123101130233112", "22022333011010133110", "10232003100100331111" };
	for(const auto& test : tests)
	{
		auto tmp(test);
		cout << "Before: " << tmp << endl;

		replacePattern1("003", "00", tmp);
		cout << "After1: " << tmp << endl;

		tmp = test;
		replacePattern2(tmp);
		cout << "After2: " << tmp << endl;

		cout << endl;
	}
}

#if !defined(_MSC_VER)
int main()
{
	JamesChen50();
	return 0;
}
#endif
