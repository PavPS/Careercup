#include "stdafx.h"

/*
You are given a 2D Array that contains only 0s and 1s in sorted order. i.e. First Os and then 1s. 

Array: 
0 0 0 1 
1 1 1 1 
0 0 1 1 
0 1 1 1 

You have to figure out the row that contains maximum number of 1s. 

e.g. in above case we have row 2 as the answer.
*/

#include <iostream>
#include <assert.h>
#include <string>
#include <map>
#include <vector>
#include <set>
#include <queue>
#include <stdexcept>
#include <limits>

using namespace std;

//
// Assume that we have more '1' and start from left side scanning from top
// to down and searching for very first '1'
//
int searchStupid(int arr[4][4])
{
	for (unsigned c = 0; c < 4; ++c)
		for (unsigned r = 0; r < 4; ++r)
			if (arr[r][c])
				return r;

	return -1;
}

//
//	First, lets test in the middle and then with kind of binary search algorithm
//	swap and search for edge line between column with zeros only and with at least one '1'
//
int searchSmart(int arr[4][4])
{
	int left = 0;
	int right = 4;
	int hasOne = -1;

	while( left != right )
	{
		const auto column = left + (right - left) / 2;
		hasOne = -1;
		for (unsigned r = 0; hasOne < 0 && r < 4; ++r)
			if (arr[r][column] != 0)
				hasOne = r;

		if (hasOne >= 0)
			right = column;
		else
			left = column + 1;
	}

	return hasOne >= 0 ? hasOne : -1;
}

void testTask()
{
	int arr[4][4] = {
		{0, 0, 0, 1},
		{1, 1, 1, 1},
		{0, 0, 1, 1},
		{0, 1, 1, 1},
	};

	assert( 1 == searchStupid(arr) );
	assert( 1 == searchSmart(arr) );	
}

void testEmpty()
{
	int arr[4][4] = {
		{0, 0, 0, 0},
		{0, 0, 0, 0},
		{0, 0, 0, 0},
		{0, 0, 0, 0},
	};

	assert( -1 == searchStupid(arr) );
	assert( -1 == searchSmart(arr) );	
}

void testFull()
{
	int arr[4][4] = {
		{1, 1, 1, 1},
		{1, 1, 1, 1},
		{1, 1, 1, 1},
		{1, 1, 1, 1},
	};

	assert( 0 == searchStupid(arr) );
	assert( 0 == searchSmart(arr) );	
}

void testRightMost()
{
	int arr[4][4] = {
		{0, 0, 0, 0},
		{0, 0, 0, 0},
		{0, 0, 0, 1},
		{0, 0, 0, 0},
	};

	assert( 2 == searchStupid(arr) );
	assert( 2 == searchSmart(arr) );	
}

void testLeftMost()
{
	int arr[4][4] = {
		{0, 0, 0, 0},
		{0, 0, 0, 0},
		{1, 1, 1, 1},
		{0, 0, 0, 0},
	};

	assert( 2 == searchStupid(arr) );
	assert( 2 == searchSmart(arr) );	
}

void Amazone15()
{
	testTask();
	testEmpty();
	testFull();
	testRightMost();
	testLeftMost();
}

#if !defined(_MSC_VER)
int main()
{
	Amazone15();
	return 0;
}
#endif
