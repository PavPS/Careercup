#include "stdafx.h"

/*
Given ~300k words with an average length of 7 in a file.
All words are dictionary correct words.
Print all the anagrams that are present in this list of words without repeating them.

E.g. if the list has:
ACT
BAT
CAT
TAB
TAC

print:
ACT, CAT, TAC
BAT, TAB
*/

#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>
#include <map>
#include <set>

using namespace std;

/* Warning! Code is overflow unsafe. Does not work for very long words */
typedef unsigned HashType;

const HashType Primes[] {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101};
HashType getCharacterHash(const char chr)
{
	return Primes[ 'z' - tolower(chr) ];
}

HashType calcHash(const string& word)
{
	if (word.empty())
		return 0;

	HashType hash = Primes[ getCharacterHash(word.c_str()[0]) ];
	for (unsigned i = 1; i < word.size(); ++i)
		hash *= Primes[ getCharacterHash(word.c_str()[i]) ];

	return hash;
}

void printPrimes(const set<string>& dic)
{
	multimap<HashType, string> hlp;
	for (const auto& word : dic)
		hlp.insert( make_pair(calcHash(word), word) );

	unsigned counter = 0;
	for (auto iter = hlp.begin(), end = hlp.end(); iter != end;)
	{
		const auto currentKey = iter->first;
		cout << ++counter << ": ";
		for (;iter != end && currentKey == iter->first; ++iter)
			cout << iter->second << " ";

		cout << endl;
	}
}

void Amazone13()
{
	set<string> dic;
	dic.insert("ACT");
	dic.insert("BAT");
	dic.insert("CAT");
	dic.insert("TAB");
	dic.insert("TAC");

	cout << "Original:" << endl;
	for (const auto& word : dic)
		cout << word << endl;

	cout << "Anagrams:" << endl;
	printPrimes(dic);
}

#if !defined(_MSC_VER)
int main()
{
	Amazone13();
	return 0;
}
#endif
