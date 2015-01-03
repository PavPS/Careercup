#include "stdafx.h"

#include <assert.h>
#include <set>

/*
Given a binary search tree.
Given two nodes. Find common node is exists.
*/

using namespace std;

struct btp_node
{
	int value;
	btp_node *left;
	btp_node *right;
	btp_node *parent;
};

btp_node** btp_next(btp_node* node, int value)
{
	if (value <= node->value)
		return &node->left;
	else
		return &node->right;
}

void btp_add(btp_node* node, int value)
{
	btp_node **victim = btp_next(node, value);
	if (!*victim)
	{
		*victim = new btp_node();
		(*victim)->value = value;
		(*victim)->parent = node;
	}
	else
	{
		btp_add(*victim, value);
	}
}

int btp_sum_rec(btp_node* node)
{
	if (!node)
		return 0;

	return node->value + btp_sum_rec(node->left) + btp_sum_rec(node->right);
}

btp_node* bt_search_rec(btp_node* node, int value)
{
	if (!node)
		return nullptr;

	if (node->value == value)
		return node;

	return bt_search_rec( *btp_next(node, value), value );
}

btp_node* findCommonNode(btp_node* first, btp_node* second)
{
	set<btp_node*> unique;
	while(first)
	{
		if ( first == second )
			return first;

		unique.insert(first);
		first = first->parent;
	}

	while(second)
	{
		if ( unique.find(second) != unique.end() )
			return second;

		second = second->parent;
	}

	return nullptr;
}

void Amazone8()
{
	btp_node *root = new btp_node();
	root->value = 2;
	btp_add(root, 7);
	btp_add(root, 5);
	btp_add(root, 1);
	btp_add(root, 4);
	btp_add(root, 9);
	btp_add(root, 3);

	auto sum = btp_sum_rec(root);
	assert(sum == 31);

	auto first = bt_search_rec(root, 4);
	auto second = bt_search_rec(root, 1);
	auto common = findCommonNode(first, second);
	UNUSED(common);
}


#if !defined(_MSC_VER)
int main()
{
	Amazone8();
	return 0;
}
#endif
