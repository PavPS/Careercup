#include "stdafx.h"

/*
	static_cast / dynamic_cast puzzles
*/

#include <iostream>
#include <assert.h>
#include <string>

using namespace std;

class AAA { 
public:
	string str;
	AAA() : str("AAA") { }
	string print_AAA() { cout << str << endl; return str; }

	string print() { return print_AAA(); }
};

class BBB { 
public:
	string str;
	BBB() : str("BBB") { }
	string print_BBB() { cout << str << endl; return str; }

	string print() { return print_BBB(); }
};

class CCC : public AAA, public BBB { };

class DDD { 
public:
	string str;
	DDD() : str("DDD") { }
	string print_DDD() { cout << str << endl; return str; }

	string print() { return print_DDD(); }
};

class EEE : public DDD { };
//class FFF : public EEE, public DDD { };

class XYZ { };

void JamesChen51()
{
	AAA* a = new AAA();
	assert("AAA" == a->print());

	CCC* c = static_cast<CCC*>(a);
	// This is buggy, but memory layout of CCC contains AAA and BBB sequentially
	assert("AAA" == c->print_AAA());

	// This is buggy. And fake. CCC occupies more space than original AAA instance.
	// assert("BBB" == c->print_BBB());

	// Ambiguous (AAA and BBB);
	// assert("AAA" == c->print());

	AAA a_stack;
	CCC& c_stack = static_cast<CCC&>(a_stack);
	// This is buggy, but memory layout of CCC contains AAA and BBB sequentially
	assert("AAA" == c_stack.print_AAA());

	 //This is buggy. And fake. CCC occupies more space than original AAA instance. This object is on stack. 
	 // Memory may not be null but point to wrong place
	 // assert("BBB" == c_stack.print_BBB());

	// -------------------------------------------------------------------------------------

	c = new CCC();
	assert("BBB" == c->print_BBB());
	assert("AAA" == c->print_AAA());

	// Correct
	a = static_cast<AAA*>(c);
	assert("AAA" == a->print());

	// Correct
	BBB *b = static_cast<BBB*>(c);
	assert("BBB" == b->print());

	// See difference - it's not stupid pointer cast. Compiler knows layout.
	b = reinterpret_cast<BBB*>(c);
	assert("AAA" == b->print());

	// -------------------------------------------------------------------------------------

	//FFF *f = new FFF();	
	// Ambiguous
	// assert("DDD" == f->print_DDD());

	// Ambiguous. 2 DDD in hierarchy. It controls it.
	// DDD *d = static_cast<DDD*>(f);

	// It understands that the class is completely of of hierarchy
	// So basically, you can move back and forward non-safe. 
	// But you can not cast to any foreign type
	// XYZ *xyz = static_cast<XYZ*>(f);
}

#if !defined(_MSC_VER)
int main()
{
	JamesChen51();
	return 0;
}
#endif
