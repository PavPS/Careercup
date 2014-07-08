/*

6 
Answers
MsExcel columns has a pattern like 
A B C … Z 
AA AB AC…. AZ BA BB … ZZ 
AAA AAB 
A has code 1 
Z has code 26 
AA has code 27 
AAA has code 626 
given a number return a column name as string

*/
#include "stdafx.h"

#include <string>
#include <assert.h>

using namespace std;

string chars("ABCDEFGHIJKLMNOPQRSTUVWXYZ");

int getColumnNumberFlat(const string& name)
{
	double num = 0;
	for ( int i = name.length() - 1; i >= 0 ; --i )
	{
		int dist = name[i] - chars[0] + 1;
		num += dist * pow(chars.length(), (name.length() - 1) - i);
	}

	return (int)num;
}

int getColumnNumberRecursion(const string& name)
{
	if (!name.length())
		return 0;

	int dist = name[name.length()-1] - chars[0] + 1;
	return dist + chars.length()*getColumnNumberRecursion(name.substr(0, name.length()-1));
}

void Amazone11()
{
	assert(1 == getColumnNumberFlat("A"));
	assert(27 == getColumnNumberFlat("AA"));
	assert(/*626*/ 703 == getColumnNumberFlat("AAA"));

	assert(1 == getColumnNumberRecursion("A"));
	assert(27 == getColumnNumberRecursion("AA"));
	assert(/*626*/ 703 == getColumnNumberRecursion("AAA"));
}