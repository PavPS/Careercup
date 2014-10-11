#include "stdafx.h"

/*
Given a circular linked list, implement an algorithm which returns node at the beginning of the loop and cut it off.
*/

#include <iostream>
#include <algorithm>
#include <iomanip>
#include <unordered_set>

using namespace std;

typedef struct TreeNode26_{
	int value;
	TreeNode26_ *next;
}TreeNode26;

TreeNode26 * addNode26(int value, TreeNode26 **head)
{
	TreeNode26 *n = new TreeNode26();
	n->value = value;
	n->next = nullptr;

	if (*head)
	{
		n->next = *head;
	}

	return *head = n;
}

TreeNode26 const*findLoop1(TreeNode26 const *head)
{
	unordered_set<TreeNode26 const*> visited;

	while (head)
	{
		if (visited.end() != visited.find(head))
			return head;

		visited.insert(head);
		head = head->next;
	}

	return nullptr;
}

TreeNode26 const*findLoop2(TreeNode26 const * const head)
{
	auto slow = head, fast = head;
	do
	{
		slow = slow->next;
		fast = fast->next->next;
	} while (slow != fast);

	unsigned count = 0;
	auto counter = slow;
	do
	{
		counter = counter->next;
		++count;
	} while (slow != counter);

	auto sapper = head;
	auto runner = slow;
	while (sapper != runner)
	{
		sapper = sapper->next;
		do
		{
			runner = runner->next;
		} while (sapper != runner && runner != slow);
	}

	return runner;
}

/*
-5->-4->-3->-2->-1->0->1->2->3->4->
                       |<---------|
*/

void JamesChen26()
{
	TreeNode26 *head = nullptr;
	auto n4 = addNode26(4, &head);
	addNode26(3, &head);
	addNode26(2, &head);
	auto n1 = addNode26(1, &head);
	addNode26(0, &head);
	addNode26(-1, &head);
	addNode26(-2, &head);
	addNode26(-3, &head);
	addNode26(-4, &head);
	addNode26(-5, &head);

	n4->next = n1;

	TreeNode26 const*loop = findLoop2(head);
	if (loop)
		cout << "Found: value=" << loop->value << endl;
	else
		cout << "Not found" << endl;
}
