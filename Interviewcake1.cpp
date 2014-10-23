/*
Your company built an in-house calendar tool called HiCal. You want to add a feature to see the times in a day when everyone is available.
To do this, you’ll need to know when any team is having a meeting. In HiCal, a meeting is stored as a tuple 
of integers (start_time, end_time). These integers represent the number of 30-minute blocks past 9:00am.

(2, 3) # meeting from 10:00 – 10:30 am
(6, 9) # meeting from 12:00 – 1:30 pm

Write a function condense_meeting_times() that takes an array of meeting time ranges and returns an array of condensed ranges.

For example, given:
[(0, 1), (3, 5), (4, 8), (10, 12), (9, 10)]

your function would return:
[(0, 1), (3, 8), (9, 12)]

Do not assume the meetings are in order. The meeting times are coming from multiple teams.
In this case the possibilities for start_time and end_time are bounded by the number of 30-minute slots in a day. 
But soon you plan to refactor HiCal to store times as Unix timestamps (which are big numbers). 
Write something that's efficient even when we can't put a nice upper bound on the numbers representing our time ranges.

Look at this case:
[(1, 2), (2, 3)]
These meetings should probably be merged, altough they don't exactly "overlap"—they just "touch." Does your function do this?

Look at this case:
[(1, 5), (2, 3)]
Notice that although the second meeting starts later, it ends before the first meeting ends. 
Does your function correctly handle the case where a later meeting is "subsumed by" an earlier meeting?

Look at this case:
[(1, 10), (2, 6), (3, 5), (7,9)]
Here all of our meetings should be merged together into just (1,10). We need keep in mind that after we've 
merged the first two we're not done with the result—the result of that merge may itself need to be merged into other meetings as well.

Make sure that your function won't "leave out" the last meeting.

We can do this in O(nlg(n)) time.
*/

#include "stdafx.h"

#include <string>
#include <vector>
#include <iostream>
#include <assert.h>
#include <iomanip>
#include <map>

using namespace std;

typedef pair<int, int> range;

void condense_meeting_times(const vector<range>& ranges, vector<range>& condensed)
{
	map<int, range> glue;

	auto is_in_range = [=](map<int, range>::const_iterator iter, int value)->bool{ return value >= iter->second.first && value <= iter->second.second; };

	for (const auto& r : ranges)
	{
		cout << "processing [" << r.first << ", " << r.second << "]" << endl;

		if (glue.empty())
		{
			cout << "inserting [" << r.first << ", " << r.second << "]" << endl;
			glue.insert( make_pair(r.first, r) );
			continue;
		}

		const auto end = glue.end();

		auto upper1 = --glue.upper_bound(r.first);
		// If we're inside existing region
		int lowNew;
		if ( is_in_range(upper1, r.first) )
		{
			// Completely inside
			if ( is_in_range(upper1, r.second) )
				continue;

			lowNew = upper1->first;
		}
		else
		{
			lowNew = r.first;
			++upper1;
		}

		cout << "considering new low boundary = " << lowNew << endl;

		//right is more than existing boundary and might cross other ranges.
		auto upper2 = --glue.upper_bound(r.second);
		int upNew;
		if ( is_in_range(upper2, r.second) ) // We're insede of an another range
		{
			upNew = upper2->second.second;
			++upper2;
		}
		else // We're between ranges
		{
			upNew = r.second;
			++upper2;
		}

		cout << "considering new up boundary = " << upNew << endl;

		if (end != upper1)
		{
			cout << "removing from [" << upper1->first << ", " << upper2->first << ")" << endl;
			glue.erase(upper1, upper2);
		}
		cout << "inserting [" << lowNew << ", " << upNew << "]" << endl;
		glue.insert( make_pair(lowNew, make_pair(lowNew, upNew)) );
	}

	vector<range> tmp;
	for (const auto& g : glue)
		tmp.push_back(g.second);

	swap(tmp, condensed);
}

void Interviewcake1()
{
	vector<range> ranges;

	/*
	ranges.push_back( make_pair(0, 1) );
	ranges.push_back( make_pair(3, 5) );
	ranges.push_back( make_pair(4, 8) );
	ranges.push_back( make_pair(10, 12) );
	ranges.push_back( make_pair(9, 10) );
	*/

	/*
	ranges.push_back( make_pair(1, 2) );
	ranges.push_back( make_pair(2, 3) );
	*/

	/*
	ranges.push_back( make_pair(1, 5) );
	ranges.push_back( make_pair(2, 3) );
	*/

	/*
	ranges.push_back( make_pair(1, 10) );
	ranges.push_back( make_pair(2, 6) );
	ranges.push_back( make_pair(3, 5) );
	ranges.push_back( make_pair(7, 9) );
	*/

	vector<range> condensed;
	condense_meeting_times(ranges, condensed);

	cout << "[ ";
	for (const auto& r : condensed)
		cout << "(" << r.first << ", " << r.second << ") ";
	cout << "]" << endl;
}

#if !defined(_MSC_VER)
int main()
{
	Interviewcake1();
	return 0;
}
#endif
