#include "stdafx.h"

/*
Str="4142434546" Findout missing no 44.Add it to str; 
Output:"414243444546". 
*/

#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

unsigned getFirstNumberWidthMaximum(const string& str)
{
	return str.size() / 2;
}

string fixMissing(string& str)
{
	const auto maxWidth = getFirstNumberWidthMaximum(str);

	for (unsigned w = 1; w <= maxWidth; ++w)
	{
		auto prev = stoi(str.substr(0, w));
		string nextStr = to_string(prev + 1);
		auto next = stoi(str.substr(w, nextStr.size()));
		if (next <= prev) continue;
		if (next > prev+2) continue;

		unsigned pos = w;
		while(true)
		{
			if (next == prev + 2 || next == (prev + 2) / 10)
			{
				const auto result = to_string(prev + 1);
				str.insert(pos, result);
				return result;
			}

			prev = next;
			pos += nextStr.size();
			nextStr = to_string(prev + 1);
			if (pos + nextStr.size() > str.size()) break;
			next = stoi(str.substr(pos, nextStr.size()));
		}
	}

	return "NOTHING";
}

void JamesChen44()
{
	const vector<string> tests { "0123456781011", "012345678911", "911", "4142434546", "99101102103", "101112101114" };
	for (const auto& test : tests)
	{
		auto str = test;
		cout << "String is:         " << str << endl;
		const auto missing = fixMissing(str);
		cout << "Missing number is: " << missing << endl;
		cout << "Result string is:  " << str << endl;
		cout << endl;
	}
}

#if !defined(_MSC_VER)
int main()
{
	JamesChen44();
	return 0;
}
#endif
