#include "stdafx.h"

/*
4 individual numbers which could be permuted in 4 factorial ways.
permutation of these 4 integers is an 0-indexed array consisting of 4 digits in some order when integers are different.
the best permute of the 4 integers is by the following funciton
func(summ) = abs(summ[0] - summ[1]) + abs(summ[1] - summ[2] + abs(summ[2] - summ[3])) that would give maximum value.

method signature
public int answer(int w, int x, int y, int z){
}

w = 5
x = 3
y = -1
z = 5

the sample permute wiht given numbers in the given function that would give maximum value is as follows.

for the
summ[0] = 5
summ[1] = -1
summ[2] = 5
summ[3] = 3

This should be done in O(1)time ans space complexity.
My questions wordings may be confusing, but the function and sample data are perfectly correct.

*/

#include <vector>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;

int getScore(const vector<int>& numbers)
{
	return abs(numbers[0] - numbers[1]) + abs(numbers[1] - numbers[2] + abs(numbers[2] - numbers[3]));
}

void answer_stupid(int w, int x, int y, int z)
{
	vector<int> numbers;
	numbers.push_back(w);
	numbers.push_back(x);
	numbers.push_back(y);
	numbers.push_back(z);

	sort(numbers.begin(), numbers.end());
	
	map< int, vector<int> > score;
	while (next_permutation(numbers.begin(), numbers.end()))
		score[getScore(numbers)] = numbers;

	const auto best = --score.end();
	for (const auto& number : best->second)
		cout << number << " ";
	cout << endl;
}

void answer_smart(int w, int x, int y, int z)
{
	if (abs(w - x) >= abs(w - y) && abs(w - x) >= abs(w - z))
	{ }
	else if (abs(w - y) >= abs(w - x) && abs(w - y) >= abs(w - z))
		swap(x, y);
	else if (abs(w - z) >= abs(w - x) && abs(w - z) >= abs(w - y))
		swap(x, z);

	if (x - y > x - z)
		swap(y, z);

	cout << w << " " << x << " " << y << " " << z << endl;
}

void JamesChen4()
{
	answer_smart(5, 3, -1, 5);
}