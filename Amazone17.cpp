#include "stdafx.h"

/*
Implement a program to reverse the linear linked list in pairs. 
it should handle both even number of nodes and odd number of nodes. 
if odd number of nodes, the last node will be the last node after reversion. 
Do not move the data in the nodes. Do manipulate node pointers/references. 
the nodes themselves need to be manipulated, not just the data in the nodes. 
For example, if the initial linear linked is, 
1->2->3->4->5 
after reverse it should be, 
2->1->4->3->5
*/

#include <iostream>
#include <assert.h>
#include <stack>
#include <array>

using namespace std;

struct node 
{
	int value;
	node *prev;
};

void print_list(node *n)
{
	while(n)
	{
		cout << n->value;
		n = n->prev;
		if (n)
			cout << "->";
	}
	cout << endl;
}

void append_node(node** n, int value)
{
	node *target;
	if (!*n)
		target = *n = new node();
	else
	{
		target = new node();
		target->prev = *n;
		*n = target;
	}

	target->value = value;
}

node *try_get_prev(node *n)
{
	if (n)
		return n->prev;

	return nullptr;
}

node* swap_pairs(node* n)
{
	node *n1 = n;
	node *n2 = try_get_prev(n1);
	node *n3 = try_get_prev(n2);

	if(n1 && n2)
	{
		auto tmp = n2->prev;
		n2->prev = n1;
		n1->prev = tmp;

		n1->prev = swap_pairs(n3);
		return n2;
	}

	return n;
}

void Amazone17()
{
	node *root = nullptr;
	append_node(&root, 5);
	append_node(&root, 4);
	append_node(&root, 3);
	append_node(&root, 2);
	append_node(&root, 1);

	print_list(root);
	root = swap_pairs(root);
	print_list(root);

	cout << "DONE" << endl;
}

#if !defined(_MSC_VER)
int main()
{
	Amazone17();
	return 0;
}
#endif
