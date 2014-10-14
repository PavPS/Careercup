#include "stdafx.h"

/*
Question
Does a given file name match a single - star pattern ? (Do not use regex)
    index.html matches *.html
    foo.txt does not match *.html

    matches(“index.html”, “*html”) returns true
    matches(“foo.txt”, “*html”) returns false
    matches(“cat”, “c*t”) returns true
*/

#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

bool singleStarTest(const string& test, const string& pattern)
{
	unsigned const starPos = pattern.find("*");
	if (string::npos == starPos)
		return test == pattern;

	const auto prefix = pattern.substr(0, starPos);
	const auto suffux = pattern.substr(starPos + 1);

	unsigned prefixPos = 0;
	// we do not while here!
	while( string::npos != (prefixPos = test.find(prefix, prefixPos)) && prefixPos < test.size() )
	{
		const auto tail = test.rfind(suffux);
		if (string::npos != tail && tail >= prefixPos + prefix.size())
			return true;

		prefixPos++;
	}

	return false;
}

void JamesChen45()
{
	typedef pair<string, string> TestPairType;
	const vector<TestPairType> tests { {"index.html", "*html"}, {"foo.txt", "*html"}, {"cat", "c*t"}, {"this_is_my_test_and_it_is_tricky", "is*tricky"} };

	for (const auto& test : tests)
	{
		cout << "Text: '" << test.first << "', pattern: '" << test.second << "'" << endl;
		if ( singleStarTest(test.first, test.second) )
			cout << "Matches" << endl;
		else
			cout << "Does NOT match" << endl;

		cout << endl;
	}
}

#if !defined(_MSC_VER)
int main()
{
	JamesChen45();
	return 0;
}
#endif
