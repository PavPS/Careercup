#include "stdafx.h"

/*
Problem
Reverse a sentence but do not reverse words and period.
For example:
I come from London.
.London from come I
*/

#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

void splitWords(const string& str, vector<string>& words)
{
	vector<string> tmp;

	size_t left = 0, right;
	while( left < str.size() && string::npos != (right = str.find(" ", left)) ) 
	{
		const auto sub = str.substr(left, right - left);
		tmp.push_back(str.substr(left, right - left));
		left = right + 1;
	}

	if (left < str.size())
		tmp.push_back(str.substr(left));

	swap(tmp, words);
}

string reverseSentence(const string& str)
{
	vector<string> words;
	splitWords(str, words);
	if (words.empty())
		return str;

	string result;
	for (int i = words.size() - 1; i >= 0; --i)
	{
		result += words[i];
		if (i) result += " ";
	}

	return result;
}

void JamesChen46()
{
	const string sentence = "I come from London.";
	cout << "Original: " << sentence << endl;
	cout << "Reversed: " << reverseSentence(sentence) << endl;
}

#if !defined(_MSC_VER)
int main()
{
	JamesChen46();
	return 0;
}
#endif
