#include "stdafx.h"

/*
Implement Priority Queue
*/

#include <iostream>
#include <assert.h>
#include <sstream>
#include <queue>
#include <string>

using namespace std;

template<class TValue, class TPriority, class TComparer = less<TPriority>>
class PriorityQueue
{
public:
	PriorityQueue()
		: container_(),
		  comparer_()
	{ }

	void insert_with_priority(const TValue& value, const TPriority& priority)
	{
		container_.push_back(make_pair(value, priority));
		push_heap (container_.begin(),container_.end(), comparer_);
	}

	void pull_highest_priority_element()
	{
		pop_heap (container_.begin(),container_.end(), comparer_);
		container_.pop_back();
	}

	const TValue& peek_highest_priority_element() const
	{
		return container_.front().first;
	}

	void clear()
	{
		return container_.clear();
	}

	size_t size() const
	{
		return container_.size();
	}

	bool empty() const
	{
		return container_.empty();
	}

private:
	typedef pair<TValue, TPriority> ElementType;

	class ElementComparer
	{
	public:
		ElementComparer()
			: comparer_()
		{ }

		bool operator()(const ElementType& lhs, const ElementType& rhs) const
		{
			return  comparer_(lhs.second, rhs.second);
		}

	private:
		const TComparer comparer_;
	};

	vector<ElementType> container_;
	const ElementComparer comparer_;
};

void Microsoft2()
{
	PriorityQueue<string, int> q;

	assert( 0 == q.size() );
	assert( q.empty() );

	q.insert_with_priority("element 1", 1);
	assert( 1 == q.size() );
	assert( not q.empty() );
	assert(string("element 1") == q.peek_highest_priority_element());

	q.insert_with_priority("element -1", -1);
	assert( 2 == q.size() );
	assert( not q.empty() );
	assert(string("element 1") == q.peek_highest_priority_element());

	q.insert_with_priority("element 2", 2);
	assert( 3 == q.size() );
	assert( not q.empty() );
	assert(string("element 2") == q.peek_highest_priority_element());

	q.insert_with_priority("element -2", -2);
	assert( 4 == q.size() );
	assert( not q.empty() );
	assert(string("element 2") == q.peek_highest_priority_element());

	q.insert_with_priority("element 3", 3);
	assert( 5 == q.size() );
	assert( not q.empty() );
	assert(string("element 3") == q.peek_highest_priority_element());

	q.clear();
	assert( 0 == q.size() );
	assert( q.empty() );

	cout << "DONE" << endl;
}

#if !defined(_MSC_VER)
int main()
{
	Microsoft2();
	return 0;
}
#endif
