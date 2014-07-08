#include "stdafx.h"

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
Given an array of Integers, and a range (low, high), find all continuous subsequences in the array which have sum in the range. 
Is there a solution better than O(n^2)?
*/

typedef struct
{
	int value;
	int pos;
}value_pos;

bool comparer(const value_pos& lhs, const value_pos& rhs)
{
	return std::less<int>().operator()(lhs.value, rhs.value);
}

void Google2()
{
	vector<int> numbers;
	numbers.push_back(9);
	numbers.push_back(3);
	numbers.push_back(7);
	numbers.push_back(8);
	numbers.push_back(1);
	numbers.push_back(4);
	numbers.push_back(2);
	numbers.push_back(-6);
	numbers.push_back(1);
	numbers.push_back(1);
	numbers.push_back(1);
	numbers.push_back(1);
	numbers.push_back(-5);

	pair<int, int> range(2, 7);

	vector<int> numbers_new;
	int sum = 0;
	for (vector<int>::iterator iter = numbers.begin(), end = numbers.end(); iter != end; ++iter)
	{
		sum += *iter;
		numbers_new.push_back(sum);
	}

	vector<value_pos> numbers_new_sorted;
	for (vector<int>::const_iterator iter = numbers_new.begin(), end = numbers_new.end(); iter != end; ++iter)
	{
		value_pos vp;
		vp.pos = numbers_new_sorted.size();
		vp.value = *iter;

		numbers_new_sorted.push_back(vp);
	}

	sort(numbers_new_sorted.begin(), numbers_new_sorted.end(), comparer);

	value_pos tmp;
	for (int i = 0; i < numbers.size(); ++i)
	{
		int current_number = numbers[i];
		int offset = numbers_new[i];
		int target_max_number = offset - current_number + range.second;
		int target_min_number = offset - current_number + range.first;

		tmp.value = target_min_number;
		// log(n)
		vector<value_pos>::iterator found_lower = lower_bound (numbers_new_sorted.begin(), numbers_new_sorted.end(), tmp, comparer);
		if (numbers_new_sorted.end() == found_lower)
			continue;

		tmp.value = target_max_number;
		// log(n)
		vector<value_pos>::const_iterator found_upper = upper_bound (found_lower, numbers_new_sorted.end(), tmp, comparer);

		// O(k)
		for ( vector<value_pos>::const_iterator iter = found_lower, end = found_upper; iter != end; ++iter )
		{
			int distance = iter->pos - i;
			if (distance > 0)
				cout << "from " << i << " to " << i+distance << ", sum = " << iter->value - offset + current_number << ", count = " <<  distance+1 << endl;
		}
	}
}