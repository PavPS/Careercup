#include "stdafx.h"

/*
You have two numbers represented by a linked list, where each node contains a single digit. 
The digits are stored in reverse order, such that the 1’s digit is at the head of the list. 
Write a function that adds the two numbers and returns the sum as a linked list.
EXAMPLE
Input: (3 -> 1 -> 5) + (5 -> 9 -> 2)
Output: 8 -> 0 -> 8
*/

#include <iostream>
#include <algorithm>
#include <iomanip>
#include <forward_list>

using namespace std;

typedef struct ListType_ {
	int value;
	ListType_ *next;
}ListType;

void addValueBack(ListType **list, int value)
{
	ListType *node = new ListType();
	node->value = value;
	node->next = NULL;

	if (!*list)
	{
		*list = node;
		return;
	}

	ListType *last = *list;
	while(last->next)
		last = last->next;

	last->next = node;
}

int sumAndReturnInMind(ListType const* list1, ListType const* list2, ListType **result)
{
	const ListType *next1 = NULL;
	if (list1) next1 = list1->next;

	const ListType *next2 = NULL;
	if (list2) next2 = list2->next;

	int inMind;
	if (!next1 && !next2)
	{
		inMind = 0;
	}
	else
	{
		inMind = sumAndReturnInMind(next1, next2, result);
	}

	int sum = 0;
	if (list1) sum += list1->value;
	if (list2) sum += list2->value;
	cout << sum << "(" << inMind << ")" << endl;

	sum += inMind;
	addValueBack(result, sum % 10);
	return sum / 10;
}

// This algo works for inversed sequence. Does not work for this task
void sumLists2(ListType const* list1, ListType const* list2, ListType **result)
{
	auto inMind = sumAndReturnInMind(list1,  list2, result);
	if (inMind)
		addValueBack(result, inMind);
}

void sumLists1(ListType const* list1, ListType const* list2, ListType **result)
{
	int inMind = 0;
	while(list1 || list2)
	{
		int sum = inMind;
		if (list1)
		{
			sum += list1->value;
			list1 = list1->next;
		}

		if (list2)
		{
			sum += list2->value;
			list2 = list2->next;
		}

		addValueBack( result, sum % 10 );
		inMind = sum / 10;
	}
}

void JamesChen22()
{
	forward_list<int> number1; 
	number1.push_front(5);
	number1.push_front(1);
	number1.push_front(3);

	forward_list<int> number2; 
	number2.push_front(2);
	number2.push_front(9);
	number2.push_front(5);

	forward_list<int> numberSum;

	int inMind = 0;
	auto n1 = number1.begin();
	auto n2 = number2.begin();
	while(n1 != number1.end() || n2 != number2.end())
	{
		int sum = inMind;
		if (n1 != number1.end())
		{
			sum += *n1;
			++n1;
		}

		if (n2 != number2.end())
		{
			sum += *n2;
			++n2;
		}

		numberSum.push_front(sum % 10);
		inMind = sum / 10;
	}

	cout << "Result1: ";
	for (auto iter = numberSum.cbegin(), end = numberSum.cend(); end != iter; ++iter)
		cout << *iter << " ";
	cout << endl;

	/*********************************/

	ListType *l1 = NULL, *l2 = NULL;
	addValueBack(&l1, 3);
	addValueBack(&l1, 1);
	addValueBack(&l1, 5);
	addValueBack(&l2, 5);
	addValueBack(&l2, 9);
	addValueBack(&l2, 2);

	ListType *res = NULL;
	sumLists1(l1, l2, &res);
	cout << "Result2: " ;
	do {
		cout << res->value << " ";
		res = res->next;
	}while(res);
	cout << endl;
}

#if !defined(_MSC_VER)
int main()
{
	JamesChen22();
	return 0;
}
#endif