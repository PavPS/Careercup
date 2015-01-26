#include "stdafx.h"

/*
Design an LRU cache, where you remove an element not only by time lapsed since last used but also by a cost associated with each element. 
F(t, c) is a method to find weight for each element. Where c is cost and t is time since last used.
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

class TimestampProvider 
{
public:
	size_t getTimestamp() const
	{
		return time(NULL);
	}
};

template<class C>
class WeightCalclulator 
{
public:
	size_t calculate(const size_t& timeDiff, const C& cost) const
	{
		return numeric_limits<size_t>::min() - (cost * 0 + timeDiff);
	}
};

template<class K, class V, class C, class T = TimestampProvider, class W = WeightCalclulator<C> >
class AmazoneCache
{
public:
	AmazoneCache(size_t capacity, size_t retentionSeconds)
	: capacity_(capacity)
	, retentionSeconds_(retentionSeconds)
	, t_(T())
	, w_(W())
	{

	}

	const size_t& getCapacity() const
	{
		return capacity_;
	}

	const size_t& getRetentionSeconds() const
	{
		return retentionSeconds_;
	}

	void add(const K& key, const V& value, const C& cost)
	{
		ValueType v;
		v.value = value;
		v.cost = cost;

		auto result = map_.insert( make_pair(key, v) );
		if (!result.second)
		{
			result.first->second.value = value;
			result.first->second.cost = cost;
			refreshWeight(key, cost);
		}
		else
		{
			addWeight(key, cost);
			while(getSize() > getCapacity())
			{
				const auto lastKey = (--weightKeyMap_.end())->second;
				remove(lastKey);
			}
		}
	}

	void remove(const K& key)
	{
		if ( ! map_.erase(key) )
			return;

		removeWeight(key);
	}

	const V& getOrThrow(const K& key)
	{
		const auto found = map_.find(key);
		if (map_.end() == found)
			throw runtime_error("key does not exist");

		refreshWeight(key, found->second.cost);
		return found->second.value;
	}

	size_t getSize() const
	{
		return map_.size();
	}

	void clear()
	{
		map_.clear();
		weightKeyMap_.clear();
		keyWeightMap_.clear();
	}

private:
	struct ValueType
	{
		V value;
		C cost;
	};

	const size_t capacity_;
	const size_t retentionSeconds_;
	map<K, ValueType> map_;
	multimap<size_t, K> weightKeyMap_;
	map<K, size_t> keyWeightMap_;
	const T t_;
	const W w_;

	void refreshWeight(const K& key, const C& cost)
	{
		removeWeight(key);
		addWeight(key, cost);
	}

	void addWeight(const K& key, const C& cost)
	{
		auto const weight = w_.calculate(t_.getTimestamp(), cost);
		keyWeightMap_.insert( make_pair(key, weight) );
		weightKeyMap_.insert( make_pair(weight, key) );
	}

	void removeWeight(const K& key)
	{
		auto weightIter =  keyWeightMap_.find(key);
		auto const weight = weightIter->second;
		keyWeightMap_.erase(weightIter);

		auto ret = weightKeyMap_.equal_range(weight);
		for (auto iter=ret.first; iter!=ret.second; ++iter)
			if (iter->second == key)
			{
				weightKeyMap_.erase(iter);
				return;
			}

		assert(false);
	}
};

class SimpleCounter 
{
public:
	SimpleCounter()
	: count_(0)
	{ }

	size_t getTimestamp() const
	{
		return ++count_;
	}

private:
	mutable size_t count_;
};

void Amazone14()
{
	AmazoneCache<int, int, int, SimpleCounter> cache(2, 1);

	assert( 2 == cache.getCapacity() );
	assert( 1 == cache.getRetentionSeconds() );
	assert( 0 == cache.getSize() );

	cache.add(1, 1, 1);
	assert( 1 == cache.getSize() );
	assert( 1 == cache.getOrThrow(1) );

	cache.add(1, 2, 2);
	assert( 1 == cache.getSize() );
	assert( 2 == cache.getOrThrow(1) );

	cache.remove(1);
	assert( 0 == cache.getSize() );

	///////////////////////////////////

	cache.clear();
	cache.add(1, 1, 1);
	cache.add(2, 2, 2);
	assert( 2 == cache.getSize() );
	cache.add(3, 3, 3);
	assert( 2 == cache.getSize() );
	assert( 2 == cache.getOrThrow(2) );
	assert( 3 == cache.getOrThrow(3) );

	///////////////////////////////////

	cache.clear();
	cache.add(1, 1, 1);
	cache.add(2, 2, 2);
	assert( 2 == cache.getSize() );
	assert( 1 == cache.getOrThrow(1) );
	cache.add(3, 3, 3);
	assert( 2 == cache.getSize() );
	assert( 3 == cache.getOrThrow(3) );
	assert( 1 == cache.getOrThrow(1) );	
}

#if !defined(_MSC_VER)
int main()
{
	Amazone14();
	return 0;
}
#endif
