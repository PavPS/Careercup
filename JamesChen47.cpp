#include "stdafx.h"

/*
Given a array of characters of this replace the characters which occur continously with the character and no. 
of times it occured e.g. AAAABCCDDD A4BC3D3 (count for characters that occurs once can be ignored). Do it Inplace.
*/

#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

string encodeStr(const string& str)
{
	auto tmp(str);
	char ch = 0;
	int count = 0;
	unsigned writeIndex = 0;
	for (unsigned readIndex = 0; readIndex < tmp.size(); ++readIndex)
	{
		if (ch == tmp[readIndex])
		{
			++count;
			if (count > 1)
			{
				string countStr = to_string(count);
				copy(countStr.begin(), countStr.end(), tmp.begin() + writeIndex);
			}
		}
		else
		{
			if (count > 1) ++writeIndex;
			ch = tmp[readIndex];
			tmp[writeIndex] = ch;
			++writeIndex;
			count = 1;
		}
	}

	while(++writeIndex < tmp.size())
		tmp[writeIndex] = 0;

	return tmp;
}

void JamesChen47()
{
	const string code = "xAAAABCCDDD";
	cout << "Original: " << code << endl;
	cout << "Encoded : " << encodeStr(code) << endl;
}

#if !defined(_MSC_VER)
int main()
{
	JamesChen47();
	return 0;
}
#endif
