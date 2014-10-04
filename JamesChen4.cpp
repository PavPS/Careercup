#include "stdafx.h"

/*
4 individual numbers which could be permuted in 4 factorial ways.
permutation of these 4 integers is an 0indexedarray consisting of 4 digits in some order when integers are different.
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

void JamesChen4()
{
}