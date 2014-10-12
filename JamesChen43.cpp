#include "stdafx.h"

/*
Print all possible combination of the characters in a string.
*/

#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>
#include <assert.h>
#include <vector>

using namespace std;

void printAllcombinations2(string str, unsigned from)
{
	if (from == str.size() - 2)
	{
		cout << str << endl;
		swap(str[from], str[from + 1]);
		cout << str << endl;
	}
	else
	{
		for (unsigned i = 0; i < str.size() - from; ++i)
		{
			str.insert(str.begin() + from, str.back());
			str.pop_back();
			printAllcombinations2(str, from + 1);
		}
	}
}

void printAllcombinations1(string str, string tmp)
{
	if (str.empty())
	{
		cout << tmp << endl;
		return;
	}

	for (unsigned i = 0; i < str.size(); ++i)
	{
		auto pig = str;
		pig.erase(pig.begin() + i);

		auto tmpNew = tmp;
		tmpNew.push_back(str[i]);
		printAllcombinations1(pig, tmpNew);
	}
}

void printAllcombinationsCheating(const string& str)
{
	vector<char> vec;

	for (const auto& ch : str)
		vec.push_back(ch);

	sort(vec.begin(), vec.end());
	do
	{
		for (const auto& ch : vec)
			cout << ch;

		cout << endl;

	} while (next_permutation(vec.begin(), vec.end()));
}

// n! always
void JamesChen43()
{
	string str = "12345";

	cout << "Cheating:" << endl;
	printAllcombinationsCheating(str);

	cout << "Version 1:" << endl;
	printAllcombinations1(str, "");

	cout << "Version 2:" << endl;
	printAllcombinations2(str, 0);
}
