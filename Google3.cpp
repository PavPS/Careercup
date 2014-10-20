#include "stdafx.h"

/*
Write a program to implement Double Linked List from Stack with min. complexity.
*/

#include <iostream>
#include <assert.h>
#include <string>
#include <stack>

using namespace std;

typedef struct { 
	stack<int> s1, s2;	
}sdll;

void sdll_clear(sdll *l)
{
   stack<int> empty1;
	l->s1.swap(empty1);
   stack<int> empty2;
	l->s2.swap(empty2);
}

void add_sdll_node(sdll **l, int value)
{
	if (!(*l))
		*l = new sdll();

	while(!(*l)->s2.empty())
	{
		(*l)->s1.push((*l)->s2.top());
		(*l)->s1.pop();
	}

	(*l)->s1.push(value);
}

sdll *get_next_sdl(sdll *l)
{
	if (!l)
		return nullptr;

	if (l->s1.empty())
		return nullptr;

	auto tmp = l->s1.top();
	l->s2.push(tmp);
	l->s1.pop();

	if (l->s1.empty())
		return nullptr;

	return l;
}

const int& sdll_get_value(sdll *l)
{
	return l->s1.top();
}

sdll *get_prev_sdl(sdll *l)
{
	if (!l)
		return nullptr;

	if (l->s2.empty())
		return nullptr;

	auto tmp = l->s2.top();
	l->s1.push(tmp);
	l->s2.pop();

	if (l->s1.empty())
		return nullptr;

	return l;
}

void Google3()
{
	sdll *l = NULL;
	add_sdll_node(&l, 0);
	add_sdll_node(&l, 1);
	add_sdll_node(&l, 2);
	add_sdll_node(&l, 3);

	cout << "Values are: ";
	for (sdll *tmp = l; tmp; tmp = get_next_sdl(tmp))
	{
		cout << sdll_get_value(tmp) << " ";
	}
	cout << endl;

	cout << "Values are: ";
	for (sdll *tmp = get_prev_sdl(l); tmp; tmp = get_prev_sdl(tmp))
	{
		cout << sdll_get_value(tmp) << " ";
	}
	cout << endl;
}

#if !defined(_MSC_VER)
int main()
{
	Google3();
	return 0;
}
#endif
