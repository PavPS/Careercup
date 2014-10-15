#include "stdafx.h"

#include <iostream>

/*
Invert a single linked list
*/

using namespace std;

struct node {
	int value;
	node *prev; 
};

void printIt(node *node)
{
	while(node)
	{
		cout << node->value << " ";
		node = node->prev;
	}

	cout << endl;
}

void Amazone2()
{
	node *original = nullptr;
	for (int i = 0; i < 10; i++ )
	{
		node *tmp = new node();
		tmp->value = i;
		tmp->prev = original;
		original = tmp;
	}

	printIt(original);

	node *root = original;
	node *prev = nullptr;
	while (root)
	{
		node *prevOld = root->prev;
		root->prev = prev;

		prev = root;
		root = prevOld;
	}

	printIt(prev);
}

#if !defined(_MSC_VER)
int main()
{
	Amazone2();
	return 0;
}
#endif
