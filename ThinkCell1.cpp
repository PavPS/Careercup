#include "stdafx.h"

#include <string.h>

#include <iostream>
#include <vector>
#include <string>

/*

ATOI

Test cases:

" "		= 0
""		= 0
NULL	= 0
" 12"	= 12
" +12"	= 12
" -12"	= -12
" 23 "	= 23
"12s"	= 12

*/

using namespace std;

int my_atoi(const char *str)
{
	if (!str) return 0;

	const auto len = strlen(str);
	if (!len) return 0;

	enum class ParserState{ WaitingForSignOrDigit, WaitingForDigit };
	int result = 0;
	int sign = +1;
	auto state = ParserState::WaitingForSignOrDigit;

	for (unsigned i = 0; i < len; ++i)
	{
		const auto& ch = str[i];
		switch (state)
		{
		case ParserState::WaitingForSignOrDigit:
			if (ch == ' ') continue;
			if (ch == '-')
			{
				sign = -1;
				continue;
			}
			else if (ch == '+')
			{
				sign = +1;
				continue;
			}
			else if (ch >= '0' && ch <= '9')
			{
				state = ParserState::WaitingForDigit;
			}
			else break;

		case ParserState::WaitingForDigit:
			if (ch >= '0' && ch <= '9')
			{
				result = result * 10 + ch - '0';
			}
			else break;
		}
	}

	return result * sign;
}

typedef struct {
	char *text;
	int result;
}TestCase;

void test()
{
	vector<TestCase> test = {
		{ NULL, 0 },
		{ " ", 0 },
		{ "", 0 },
		{ " 12", 12 },
		{ " +12", +12 },
		{ " -12", -12 },
		{ " 23", 23 },
		{ "12s", 12 },
	};

	for (auto& item : test)
	{
		auto myResult = my_atoi(item.text);
		cout << "Testing '" << (item.text ? item.text : "NULL") << "' = " << item.result;
		if (myResult == item.result)
			cout << " SUCCESS" << endl;
		else
			cout << " FAILED(" << myResult << ")" << endl;
	}
}

void ThinkCell1()
{
	test();
}