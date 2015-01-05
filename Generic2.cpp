#include "stdafx.h"

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Copyable
{
public:
	Copyable()
		: field_(0)
	{ }
	
	Copyable(const Copyable& obj)
		:field_(obj.field_)
	{
		cout << "c1" << endl;
	}
	/*
	Copyable(Copyable& obj)
		:field_(obj.field_)
	{
		cout << "c2" << endl;
	}
	*//*
	Copyable(volatile Copyable& obj)
		:field_(obj.field_)
	{
		cout << "c3" << endl;
	}
	*/
	/*
	Copyable(volatile const Copyable& obj)
		:field_(obj.field_)
	{
		cout << "c4" << endl;
	}
	*/

private:
	int field_;
};

class Assignable
{
public:
	Assignable()
		:field_(0)
	{ 
		cout << "a0" << endl;
	}

	explicit Assignable(const Assignable& obj)
		:field_(obj.field_)
	{
		cout << "a1" << endl;
	}

	Assignable(const int& field)
		:field_(field)
	{
		cout << "a00" << endl;
	}

	Assignable& operator=(const int& field)
	{
		cout << "a3" << endl;
		field_ = field;
		return *this;
	}

	Assignable& operator=(const Assignable& obj)
	{
		cout << "a2" << endl;

		if (&obj == this)
			return *this;

		field_ = obj.field_;
		return *this;
	}

private:
	int field_;
};

void Generic2()
{
	Copyable obj1;

	// 1
	Copyable obj2(obj1);

	// 2
	Copyable obj3(obj1);

	// 3
	volatile Copyable obj4(obj1);

	// 5
	volatile Copyable obj5(obj1);

	//////////////////////////////

	Assignable ass1 = 1;
	Assignable ass2;

	ass2 = 1;
	ass2 = ass1;
}