#include "stdafx.h"

#include <vector>
#include <iostream>
#include <algorithm>

/*

Binary search

*/

using namespace std;

typedef bool(Comparer)(const int& lhs, const int& rhs);

bool comparerDefault(const int& lhs, const int& rhs)
{
	return less<int>().operator()(lhs, rhs);
}

bool bsearch(vector<int>::const_iterator begin, vector<int>::const_iterator end, int value, Comparer& cmp = comparerDefault)
{
	while ( begin != end )
	{
		auto middle = begin + (end - begin) / 2;
		if ( value == *middle )
			return true;

		if ( cmp(value, *middle ) )
			end = middle;
		else
			begin = middle;
	}

	return false;
}

// result >= value
vector<int>::const_iterator lbound(vector<int>::const_iterator begin, vector<int>::const_iterator end, int value, Comparer& cmp = comparerDefault)
{
	while ( begin != end )
	{
		auto middle = begin + (end - begin) / 2;
		if ( value == *middle )
			return middle;

		if ( cmp(value, *middle ) )
			end = middle;
		else
			begin = middle;
	}

	return end;
}

// result > value
vector<int>::const_iterator ubound(vector<int>::const_iterator begin, vector<int>::const_iterator end, int value, Comparer& cmp = comparerDefault)
{
	while ( begin != end )
	{
		auto middle = begin + (end - begin) / 2;
		if ( value == *middle )
			return ++middle;

		if ( cmp(value, *middle ) )
			end = middle;
		else
			begin = middle;
	}

	return end;
}

void ThinkCell2()
{
	vector<int> values;

	cout << "original sequence:\t";
	for ( auto i = 0; i < 20; ++i )
	{
		values.push_back( rand() % 10 );
		cout << " " << values.back();
	}
	cout << endl;

	sort( values.begin(), values.end() );

	cout << "sorted sequence:\t";
	for ( auto& iter : values ) cout << " " << iter;
	cout << endl;

	const int valueOfInterest = 7;
	cout << "value of interest: " << valueOfInterest << endl;

	bool found = binary_search( values.cbegin(), values.cend(), valueOfInterest );
	cout << "found (original): " << (found ? "YES" : "NO") << endl;

	found = bsearch( values.cbegin(), values.cend(), valueOfInterest );
	cout << "found (my): " << (found ? "YES" : "NO") << endl;

	auto foundIter = lower_bound( values.cbegin(), values.cend(), valueOfInterest );
	cout << "found lower_boud (original): " << ( values.cend() == foundIter ? values.size() : foundIter - values.cbegin() ) << endl;

	auto foundIndex = lbound( values.cbegin(), values.cend(), valueOfInterest );
	cout << "found lower_boud (my): " << ( values.cend() == foundIter ? values.size() : foundIter - values.cbegin() ) << endl;

	foundIter = upper_bound( values.cbegin(), values.cend(), valueOfInterest );
	cout << "found upper_bound (original): " << ( values.cend() == foundIter ? values.size() : foundIter - values.cbegin() ) << endl;

	foundIndex = ubound(  values.cbegin(), values.cend(), valueOfInterest );
	cout << "found upper_bound (my): " << ( values.cend() == foundIter ? values.size() : foundIter - values.cbegin() ) << endl;
}