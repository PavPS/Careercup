#include "stdafx.h"

#include <iostream>

using namespace std;

class test
{
public:
	~test()
	{
		throw 123;
	}

	void foo() throw()
	{
		throw 123;
	}
};

void Exceptional()
{
	//auto obj = new test();

	// Will abort
	/*
	try
	{
		obj->foo();
	}
	catch(...)
	{
		cout << "Exception throwed" << endl;
	}
	*/

	// Will abort
	/*
	try
	{
		delete obj;
	}
	catch(...)
	{

	}
	*/
}

#if !defined(_MSC_VER)
int main()
{
	Exceptional();
	return 0;
}
#endif
