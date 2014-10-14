#include "stdafx.h"

/*
 need a function that takes the name of the movie to look up and 
the width of the letter grid, and computes the key presses that 
will enter that string on the DVR grid. The output should be a 
string, with "u", "d", "l", "r", and "!" corresponding to up, 
down, left, right, and select. 

For example, with a grid of width 5, 
a b c d e 
f g h i j 
k l m n o 
p q r s t 
u v w x y 
z 
the movie "up" would be "dddd!u!".
*/

#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

pair<int, int> getCharacterPos(char ch, unsigned width)
{
	const int diff = ch - 'a';
	const auto x = diff % width;
	const auto y = diff / width;
	return make_pair(x, y);
}

string getLetterPath(const pair<int, int>& from, const pair<int, int>& to)
{
	string result;

	const int dy = (from.second <= to.second) ? 1 : -1;
	for (int y = from.second; y != to.second; y += dy)
		result += dy > 0 ? "d" : "u";

	const int dx = (from.first <= to.first) ? 1 : -1;
	for (int x = from.first; x != to.first; x += dx)
		result += dx > 0 ? "r" : "l";

	return result;
}

const unsigned AlphabetWidth = 5;
string encodeMove(const string& movie)
{
	string result;
	pair<int, int> from {0, 0};

	for (const auto& ch : movie)
	{
		const auto to = getCharacterPos(ch, AlphabetWidth);
		result += getLetterPath(from, to) + "!";
		from = to;
	}

	return result;
}

void JamesChen48()
{
	const string movie = "up";
	cout << "Movie name: " << movie << endl;
	cout << "Movements:  " << encodeMove(movie) << endl;
}

#if !defined(_MSC_VER)
int main()
{
	JamesChen48();
	return 0;
}
#endif
